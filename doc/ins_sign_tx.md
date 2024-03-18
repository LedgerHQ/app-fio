# Sign Transaction

**Description**

Construct and sign a transaction (returns just the signature).

For FIO app main use cases it is instrumental that the app is as small as possible, while we need to have >20 different workflows for various actions. To accomplish this we designed several commands to serialize transaction while displaying (or not) parts of it. Each command is divided into constant part and variable part. Constant parts of the commands are used to calculate integrity hash by concatenating integrity hash of the previous command with constant parts of current command to produce new integrity hash. This process creates a Merkle tree and at every critical step (signing transaction, finishing DH encryption) we compare the integrity hash to one stored in the app. This guarantees that to get ether a signature or encrypted message, the constant parts of theinstructions and the ordering of the instructions have to match exactly.

For the list of allowed command sequences, see [List of allowed command sequences](allowed_command_sequences.md)

The main rationale behind is the following:
1) This approach reduces app size. The app size is almost constant while we add new features.
2) Decreases memory footprint (and no need to use flash memory). We never store whole transaction on the device. The data arrives in natural chunks.
3) Communication protocol is easily extensible in the future.
4) Potential security improvement --- because SignTx does not output the serialized transaction, only the witnesses, the host app is responsible for serializing the transaction itself. Any serialization mismatch between host and Ledger would result in a transaction which is rejected by nodes.

**SignTx Limitations**

- Single Transfer FIO tokens action, single authorization. Actor in authorization and action data must be the same. 

**Communication protocol non-goals:**

The communication protocol is designed to *ease* the Ledger App implementation (and simplify potential edge conditions). As such, the protocol might need more APDU exchanges than strictly necessary. We deem this as a good trade-off between implementation and performance (after all, the bottleneck are user UI confirmations).

Given these requirements in mind, here is how transaction signing works:

## General command structure

**Command**

| Field | Value    |
| ----- | -------- |
| CLA   | `0xD7`   |
| INS   | `0x20`   |
| P1    | command  |
| P2    | variable |
| Lc    | variable |

**Data**

| Field                 | Length   | Comments                            |
| ----------------------| -------- | ----------------------------------- |
| Constant data length  | 1        |                                     |
| Variable data length  | 1        |                                     |
| Constant data         | variable | Length matches constant data length |
| Variable data         | variable | Length matches variable data length |

Ledger will will process only certain paths, other paths will be rejected by app policy (see Ledger responsibilities section). 

**Return value**

FINISH command returns signature and serialized transaction hash. 
All other commands either do return nothing, or if we are within DH-encoded sections return finished blocks encoded by Diffie-Hellman.


## List of commands

| Command                 | P1     | Brief description                                     |
| ----------------------- |------- |-------------------------------------------------------|
| INIT                    | `0x01` | Initiates transaction signing                         |
| APPEND_CONST_DATA       | `0x02` | Appends constant data do the transaction              |
| SHOW_MESSAGE            | `0x03` | Show message on ledger screen                         |
| APPEND_DATA             | `0x04` | Append variable data to the transaction               |
| START_COUNTED_SECTION   | `0x05` | Initiates transaction section of given length         |
| END_COUNTED_SECTION     | `0x06` | Ends transaction section of given length              |
| STORE_VALUE             | `0x07` | Store value into a register                           |
| DH_START                | `0x08` | Starts transaction section encrypted by shared secret |
| DH_END                  | `0x09` | Ends transaction section encrypted by shared secret   |
| FINISH                  | `0x10` | Finishes and signs the transaction                    |


### INIT

| Field | Value    |
| ------|--------- |
| P1    | `0x01`   |
| P2    | unused   |

**Constant data**

| Field                             | Length | Comments                            |
| --------------------------------- | ------ | ----------------------------------- |
| (none)                            |        |                                     |

**Variable data**

| Field                             | Length | Comments                           |
| --------------------------------- | -------| ---------------------------------- |
| Chain ID                          | 32     | Must be mainnet or testnet chainId |
| BIP32 path len                    | 1      | min 2, max 10                      |
| First derivation index            | 4      | Little endian. Must be 44'         |
| Second derivation index           | 4      | Little endian. Must be 235'        |
| (optional) Third derivation index | 4      | Little endian                      |
| ...                               | ...    | ...                                |
| (optional) Last derivation index  | 4      | Little endian                      |
| (optional) No. of remaining keys  | 4      | Little endian                      |

**Ledger actions**

- Validate Chain Id
- Validate derivation path, ledger accepts only certain derivation paths (see [src/securityPolicy.c](../src/securityPolicy.c))
- Appends Chain Id to the transaction (includes counted section validation update)
- Display chain to the user
- Initialize integrity validation

### APPEND_CONST_DATA 

| Field | Value    |
| ------|--------- |
| P1    | `0x02`   |
| P2    | unused   |

**Constant data**

| Field                             | Length   | Comments                            |
| --------------------------------- | -------- | ----------------------------------- |
| Data to append to transaction     | variable |                                     |

**Variable data**

| Field                             | Length | Comments                            |
| --------------------------------- | ------ | ----------------------------------- |
| (none)                            |        |                                     |

**Ledger actions**

- Appends data to the transaction (includes counted section validation update and possible DH encoding)
- Continue integrity validation

### SHOW_MESSAGE

| Field | Value    |
| ------|--------- |
| P1    | `0x03`   |
| P2    | unused   |

**Constant data**

| Field                             | Length   | Comments                            |
| --------------------------------- | -------- | ----------------------------------- |
| Key Len                           | 1        |                                     |
| Key                               | variable |                                     |
| Value Len                         | 1        |                                     |
| Value                             | variable |                                     |

**Variable data**

| Field                             | Length | Comments                            |
| --------------------------------- | ------ | ----------------------------------- |
| (none)                            |        |                                     |

**Ledger actions**

- Display the message
- Continue integrity validation

### APPEND_DATA

| Field | Value    |
| ------|--------- |
| P1    | `0x04`   |
| P2    | unused   |

**Constant data**

| Field                             | Length   | Comments                                   |
| --------------------------------- | -------- | ------------------------------------------ |
| Value Format                      | 1        | NAME, STRING, UINT64                       |
| ValueValidation                   | 1        | NONE, LENGTH, EQUALS_STORED                |
| ValueValidationArg 1              | 8        |                                            |
| ValueValidationArg 2              | 8        |                                            |
| Policy and storage                | 1        | higher 4 bits storage, lower 4 bits policy |
| Key length                        | 1        |                                            |
| Key                               | variable |                                            |

Value formats: 

- VALUE_FORMAT_BUFFER_SHOW_AS_HEX = 0x01
- VALUE_FORMAT_ASCII_STRING = 0x02,
- VALUE_FORMAT_NAME = 0x03: Special FIO name format. To be converted to string before display
- VALUE_FORMAT_ASCII_STRING_WITH_LENGTH = 0x04: String prefixed with VarUInt length
- VALUE_FORMAT_FIO_AMOUNT = 0x10: FIO currency amount stored as UINT64
- VALUE_FORMAT_UINT64 = 0x14,
- VALUE_FORMAT_VARUINT32 = 0x17,
- VALUE_FORMAT_MEMO_HASH = 0x20: Special mode for showing memo or hash and offline url.
    Format:
    - has memo 1 byte (0x00/0x01) followed by memo string with length (as in VALUE_FORMAT_ASCII_STRING_WITH_LENGTH), string length 1-127.
    - has hash 1 byte (0x00/0x01) followed by hash string with length (as in VALUE_FORMAT_ASCII_STRING_WITH_LENGTH), string length 0-127.
    - has offline_url 1 byte (0x00/0x01) followed by offline_url string with length (as in VALUE_FORMAT_ASCII_STRING_WITH_LENGTH), string length 0-127.
    The value has to have either memo, or hash and offline_url. Hash and offline_url cannot be of max length at the same time because of APDU buffer size. The purpose of this instruction is to save several APDUs and to limit the number of allowed command sequences.
- VALUE_FORMAT_CHAIN_CODE_TOKEN_CODE_PUBLIC_ADDR = 0x21: Special mode for showing chain code, token code and public address as one entry.
    Format:
    - Token code (as in VALUE_FORMAT_ASCII_STRING_WITH_LENGTH)
    - Chain code (as in VALUE_FORMAT_ASCII_STRING_WITH_LENGTH)
    - Public address (as in VALUE_FORMAT_ASCII_STRING_WITH_LENGTH)
    
Value validation: 

- VALUE_VALIDATION_NONE = 0x01
- VALUE_VALIDATION_INBUFFER_LENGTH = 0x02: Validates that the length of value is between ValueValidationArg 1 and ValueValidationArg 2
- VALUE_VALIDATION_NUMBER = 0x03: Value has to be a number (VALUE_FIO_AMOUNT, VALUE_UINT64, VALUE_FORMAT_VARUINT32). Validates that the numeric value is between ValueValidationArg1 and ValueValidationArg2

Storage bites:

Storage is used to guarantee that certain elements in the transaction match. Storage has three registers of variable sizes (see store value calls).
- VALUE_STORAGE_CHECK_NO = 0x00: No check with storage
- VALUE_STORAGE_CHECK_R1 = 0x10: Checks value equality with R1
- VALUE_STORAGE_CHECK_R2 = 0x20: Checks value equality with R2
- VALUE_STORAGE_CHECK_R3 = 0x30: Checks value equality with R3
- VALUE_STORAGE_CHECK_R1_DECODE_NAME = 0x40: Checks value equality with R1 converted from name to string.


**Variable data**

| Field                             | Length   | Comments                            |
| --------------------------------- | -------- | ----------------------------------- |
| Value                             | variable |                                     |

**Ledger actions**

- Parse and validate the value
- Validate storage
- Append value to tx (includes counted section validation update and possible DH encoding)
- Display key and parsed value(s) if policy requires it
- Continue integrity validation


### START_COUNTED_SECTION 

Counted sections append a VARINT to the transaction and then validate that the total length of buffers appended to the transaction between START_COUNTED_SECTION and END_COUNTED_SECTION matches the value. Matching pairs of commands have to be both either outside or within DH encrypted segment. Note that DH encoding modifies the length of what is appended to the transaction so counted section takes this into account.

| Field | Value    |
| ------|--------- |
| P1    | `0x05`   |
| P2    | unused   |

**Constant data**

| Field                             | Length   | Comments                                   |
| --------------------------------- | -------- | ------------------------------------------ |
| Value Format                      | 1        | NAME, STRING, UINT64                       |
| ValueValidation                   | 1        | NONE, LENGTH, EQUALS_STORED                |
| ValueValidationArg1               | 8        |                                            |
| ValueValidationArg2               | 8        |                                            |

Value formats: 
- VALUE_FORMAT_FIO_AMOUNT = 0x10: FIO currency amount stored as UINT64
- VALUE_FORMAT_UINT64 = 0x14,
- VALUE_FORMAT_VARUINT32 = 0x17,

Value validation: 
See APPEND_DATA instruction

**Variable data**

| Field                             | Length   | Comments                            |
| --------------------------------- | -------- | ----------------------------------- |
| Value                             | variable |                                     |

**Ledger actions**

- Checks if the limit on nested counted section was not surpassed (MAX_NESTED_COUNTED_SECTIONS = 5)
- Parse and validate the value
- Append value to tx (includes counted section validation update and possible DH encoding)
- Initiate new counted section validation (Value itself does not count into the new counted section)
- Continue integrity validation


### END_COUNTED_SECTION 

| Field | Value    |
| ------|--------- |
| P1    | `0x06`   |
| P2    | unused   |

**Constant data**

| Field                             | Length | Comments                            |
| --------------------------------- | ------ | ----------------------------------- |
| (none)                            |        |                                     |

**Variable data**

| Field                             | Length   | Comments                            |
| --------------------------------- | -------- | ----------------------------------- |
| Value                             | variable |                                     |

**Ledger actions**

- Validate that the number of bytes appended matches the expected value given in matching START_COUNTED_SECTION.
- Continue integrity validation


### STORE_VALUE

Stores Value into one of the registers. APPEND_DATA may compare its value with the register. This mechanism allows to guarantee match of certain transaction elements.

| Field | Value                         |
| ------|------------------------------ |
| P1    | `0x07`                        |
| P2    | register to use: 1, 2, or 3   |

Registers 1 and 2 have 8 bytes. Register 3 has 64 bytes. Together with the value we also store its length.

**Constant data**

| Field                             | Length | Comments                            |
| --------------------------------- | ------ | ----------------------------------- |
| (none)                            |        |                                     |

**Variable data**

| Field                             | Length | Comments                            |
| --------------------------------- | ------ | ----------------------------------- |
| (none)                            |        |                                     |

**Ledger actions**

- Validate that the value fits into selected register.
- Store value into selected register
- Continue integrity validation


### DH_START

Starts Diffie-Hellman encrypted block.

| Field | Value    |
| ------|--------- |
| P1    | `0x08`   |
| P2    | unused   |

**Constant data**

| Field                             | Length | Comments                            |
| --------------------------------- | ------ | ----------------------------------- |
| (none)                            |        |                                     |

**Variable data**

| Field                             | Length | Comments                            |
| --------------------------------- | ------ | ----------------------------------- |
| DH encryption (their) pubkey      |     65 |                                     |

**Ledger actions**

- Continue integrity validation
- Show that DH encrypted section is starting
- Parse, store and show DH pubkey
- Validate that DH encryption is not active and activate it (and guarantee that counted sections take DH into account)
- Derive and wipe out AES key
- Securely create the initialization vector (IV)
- Return encrypted blocks that were finished during AES initialization.

Note that all commands within DH encrypted section that append value to the transaction have to:
- Initiate and wipe out AES key
- Instead of appending the data to the transaction, append them to DH encryption, and append the finished blocks to the transaction
- Return finished blocks
Also note that partial DH encrypted cypher text is of no cryptographic use before final HMAC is sent (which is only done at the end ). 


### DH_END

Ends Diffie-Hellman encrypted block.

| Field | Value    |
| ------|--------- |
| P1    | `0x09`   |
| P2    | unused   |

**Constant data**

| Field                             | Length | Comments                            |
| --------------------------------- | ------ | ----------------------------------- |
| (none)                            |        |                                     |

**Variable data**

| Field                             | Length | Comments                            |
| --------------------------------- | ------ | ----------------------------------- |
| (none)                            |        |                                     |


**Ledger actions**

- Continue integrity validation
- Validate the integrity hash against the list of known hashes
- Validate that DH encryption active and deactivate it (and guarantee that counted sections take DH into account)
- Derive and wipe out AES key
- Finish DH encryption
- Ask for confirmation before returning final blocks (containing HMAC)
- Return final encrypted blocks that were finished during AES initialization


### FINISH

| Field | Value    |
| ------|--------- |
| P1    | `0x10`   |
| P2    | unused   |

**Constant data**

| Field                             | Length | Comments                            |
| --------------------------------- | ------ | ----------------------------------- |
| (none)                            |        |                                     |

**Variable data**

| Field                             | Length | Comments                            |
| --------------------------------- | ------ | ----------------------------------- |
| (none)                            |        |                                     |

**Ledger actions**

- Validate that DH is not active and there is no running counted section  
- Continue integrity validation
- Validate the integrity hash against the list of known hashes
- Request confirmation to sign the transaction
- Return the signature and hash

**Response**

| Field     | Length | Comments           |
| --------- | ------ | ------------------ |
| Signature | 65     | Witness signature  |
| Hash      | 32     | Serialized Tx hash |

