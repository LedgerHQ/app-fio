# decode shared secret

**Description**

Decrypt shared secret. Decryption of shared secret spanns several APDU commands.

**Command 1**

| Field | Value    |
| ----- | -------- |
| CLA   | `0xD7`   |
| INS   | `0x30`   |
| P1    | `0x01`   |
| P2    | unused   |
| Lc    | data     |

Data contains part of the encrypted data (after base64 decoding). This command can be sent multiple times, but reasonably, it should be used at most twice at this moment (the longest addmissible message has length 324 bytes after base 64 decoding).

**Command 2**

| Field | Value                                        |
| ----- | -------------------------------------------- |
| CLA   | `0xD7`                                       |
| INS   | `0x30`                                       |
| P1    | `0x02`                                       |
| P2    | `0x01` for newfundsreq; `0x02` for recordobt |
| Lc    | data                                         |

Data decoding.

**Command 2 Data**

| Field                             | Length | Comments                           |
| --------------------------------- | ------ | ---------------------------------- |
| Other public key                  | 65     | Pub key                            |
| BIP32 path len                    | 1      | min 2, max 10                      |
| First derivation index            | 4      | Little endian. Must be 44'         |
| Second derivation index           | 4      | Little endian. Must be 235'        |
| (optional) Third derivation index | 4      | Little endian                      |
| ...                               | ...    | ...                                |
| (optional) Last derivation index  | 4      | Little endian                      |
| (optional) No. of remaining keys  | 4      | Little endian                      |

Ledger will will process only certain paths, other paths will be rejected by app policy (see Ledger responsibilities section). 

**Command 3**

| Field | Value  |
| ----- | -------|
| CLA   | `0xD7` |
| INS   | `0x30` |
| P1    | `0x03` |
| P2    | unused |
| Lc    | unused |

Sends remaining decoded data. You need to send this message even if the data 

**Response**

| Field                                    | Length   | Comments                            |
| ---------------------------------------- | -------- |------------------------------------ |
| total length of the whole message        | 2        | Little endian                       |
| length of the second part of the message | 1        |                                     |
| decoded message (first part)             | variable | Length according to the field above |

**Errors (SW codes)**

- `0x9000` OK
- `0x6E10` Request rejected by app policy
- `0x6E09` Request rejected by user
- for more errors, see [src/errors.h](../src/errors.h)

**Ledger responsibilities**

- Check:
  - check P1 is valid
  - check P2 is valid
  - check data is valid:
    - `Lc >= 66` (we have public key and path_len)
    - `65 + 1 + path_len * 4 == Lc`
  - check if public key is valid
  - check derivation path is valid and within FIO BIP32 space
    - `path_len == 5`
    - `path[0] == 44'` (' means hardened)
    - `path[1] == 235'`
    - `path[2] == 0'` 
    - `path[3] == 0` 
    - Ledger might impose more restrictions, see implementation of `policyForDecodeDHDecode` in [src/securityPolicy.c](../src/securityPolicy.c) for details
- validate that decoded message confirms to format imposed by newfundsreq / recordobt content structure
- display relevant decoded fields
- after confirmation respond with decoded message
 
