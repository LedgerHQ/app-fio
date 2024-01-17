# FIO Ledger App Sign transaction call security documentation

For purpose of this documentation we divide the call source into following parts:
- App integrity component
- Parsing component
- Counted section component
- MAIN HANDLER
- INIT and FINISH subcalls
- APPEND_CONST_DATA subcall
- SHOW_MESSAGE subcall
- STORE_VALUE subcall
- APPEND_DATA subcall
- Counted section subcalls
- DH subcalls

Sign transaction is a multiAPDU call. The call sequence starts with an INIT call and ends with FINISH call. Between these calls, there may be an arbitrary sequence of calls, however, paired commands have to match(`START COUNTED SECTION`-`END COUNTED SECTION`, `START DH ENCODING`- `END DH ENCODING`). That is if we replace counted section commands with `(` and `)`, DH commands with `[` and `]`, and remove other commands, we need to obtain a correct parentheses-bracket sequence.

Each command has constant part and variable part. There is a list of allowed command sequences (`../allowed_command_sequences.md`). Constant part of the command must be constant within the command sequence (this includes P1, P2), variable parts may vary, thus only constant parts of the commands are documented. 

The app uses the mechanism of integrity hashes (see app integrity component) to validate that the command sequence is allowed. Init initializes integirity component and each subsequent call sends its constant data to the integrity component. On cryptographically important occasions, integrity components compares its state with a list of known states to validate that thw whole previous command sequence is correct. The occasions are:
- `END DH ENCODING` subcall - This subcall finishes DH encoding and produces final HMAC. Note that without HMAC, the part of encoded message is of no cryptographic use. Thus it is OK to return parts of encoded H message without integrity validation (and also without confirmation).
- `FINISH` subcall - We produce signature only if a correct sequence of commands was executed.


## App integrity component

The integrity check component is implemented in`signTransactionIntegrity.c/h`.
The integrity check component works as a linear Merkle tree using SHA-256. 

`integrityCheckInit` - Initiates integrity context. sets hash to `0`'s. This corresponds to the leaf of the Merkle tree
`integrityCheckProcessInstruction` - Takes current integrity hash, concatenates it with p1, p2, constant data length, and constant data. Note that this concatenation is injective. Then calculates hash of the result. Thanks to SHA-256 second preimage resistance and the injectivity of the concatenation, it is not feasible to construct the resulting hash in a different way.
`integrityCheckEvaluate` - Verifies, if current hash is among the known list of integrity hashes (known Merkle tree roots).

Security consideration:
- First APDU in a sequence must initialize integrity check  with `integrityCheckInit` (done by MAIN HANDLER).
- Each instruction (including `INIT`) must call `integrityCheckProcessInstruction` (done by MAIN HANDLER).
- `END DH ENCODING` and `FINISH` must call `integrityCheckEvaluate` after calling `integrityCheckProcessInstruction` (done by END DH ENCODING and FINISH). 

Testing: This component is covered by a unit test validating most aspects of its functionality.
The component is new.


## Counted section component

The counted section component is implemented in`signTransactionCountedSection.c/h`.
On many places, transaction contains length of the next element (which may be a sting or a more complex structure). Counted sections are created to guarantee that the length of the element matches the length appended to the transaction. 

Counted section component does not directly handle issues arising from DH encoded sections. Counted sections inside DH encoded section need to count data before DH encoding, and those that include DH encoded section must calculate the encoded data length. We achieve this behavior by "fixing" the length difference using `countedSectionProcess` call when handling END DH ENCODING subcall.

`countedSectionInit` - Initializes counted section variable
`countedSectionBegin` - Starts new counted section
`countedSectionProcess` - Adds given number of bytes to all currently running counted section
`countedSectionEnd` - Finishes topmost counted section. Validates that its length matches the sum of lengths given in `countedSectionProcess` calls.
`countedSectionFinalize` - Validates that all counted sections are finished

Security consideration:
- First APDU in sequence must call `integrityCheckInit` (done by MAIN HANDLER).
- All other calls must use `countedSectionBegin`/ `countedSectionProcess` / `countedSectionEnd` to guarantee transaction integrity.
- Allowed APDU sequences must be defined in such a way that there is a bijection from resulting transaction to variable data in  respective calls
  - This is attained by fixing length of everything that goes into the transaction (either due to the fact that the length is constant or due to being in a counted section). 
  - See `allowed_command_sequences.md` and `ledferjs-fio/src/interactions/transactionTemplates/` for command sequences description.
- FINISH must call `countedSectionFinalize` (done by FINISH)

Testing: This component is covered by a unit test validating most aspects of its functionality.
The component is new.


## Parsing component

The counted section component is implemented in `signTransactionParse.c/h`.
This component parses and validates data given in various formats.
Testing: This component is tested as part of integration tests as they the functions present are used to parse various transaction elements.
The component is new.


## MAIN HANDLER

This covers `MISC` and `MAIN HANDLER` sections of `signTransaction.c/h`.

- `lookup_subhandler` - Finds correct subhandler given the value of `P1`.
- `signTransaction_handleAPDU` 
  - Initiates everything if the call is new.
    - Integrity variable
    - Counted section variable
    - Storage variable
  - Validates and splits input to constant and variable parts
  - Updates integrity check
- `processShaAndPosibleDHAndPrepareResponse` - Helper function to update rolling hash of the transaction. This includes possible DH encoding if we are within DH encoded section (this includes calculating the difference of DH encrypted data and plain data, so we can adjust counted sections once we leave DH encoded section). 
- `prepareOurPubkeyForDisplay` - Helper function to get our public key in a readable format.
- `signTx_ui_runStep_simple` - Defines simple and reusable UI screen sequence. It uses `ctx->key` and `ctx->value` as the source of data/

Testing: This component is tested as part of integration tests.
The component is new.


## INIT and FINISH subcalls

This covers `INIT` and `FINISH` sections of `signTransaction.c/h`.

Testing: Primary test for this part is `signTransactionCommandsBasic.js` Speculos test.
- `INIT` subcall must
  - Parse derivation path and chain.
  - Show chain to the user.
- `FINISH` subcall must
  - Validate command sequence integrity
  - Validate that there are no running counted sections
  - Validate that DH encoded section is not running
  - Display public key used to sign the transaction
  - Ask user for confirmation before sending the response
The component is new.


## APPEND_CONST_DATA subcall

This covers `APPEND_CONST_DATA` section of `signTransaction.c/h`.

Testing: Primary test for this part is `signTransactionCommandsBasic.js` Speculos test.
The component is new.


## SHOW_MESSAGE subcall

This covers `SHOW_MESSAGE` section of `signTransaction.c/h`.

Testing: Primary test for this part is `signTransactionCommandsBasic.js` Speculos test.
The component is new.


## STORE_VALUE subcall

The app has three register variables. The purpose of this subcall is to write variable part of the instruction into one of the registers

Testing: Primary test for this part is `signTransactionCommandsStorage.js` Speculos test.
The component is new.


## APPEND_DATA subcall

Append data to transaction, parse, validate it, and possibly display it. This may include value validation again one of register variables.

Testing: Primary test for this part is `signTransactionCommandsShowData.js` Speculos test. Various modes of function of this call is tested in Speculos transaction tests.
The component is new.


## Counted section subcalls

This covers `START COUNTED SECTION` and `END COUNTED SECTION` sections of `signTransaction.c/h`.

Testing: Primary test for this part is `signTransactionCommandsCountedSection.js` Speculos test. Various modes of function of this call is tested in Speculos transaction tests.
The component is new.


## DH subcalls

This covers `START DH ENCODING` and `END DH ENCODING` sections of `signTransaction.c/h`.

Security consideration:
  - `END DH ENCODING` encoding must adjust the length of outstanding counted section for the different length of DH encoded data compared to plain data.
  - `END DH ENCODING` must ask for confirmation before returning the last blocks (which include HMAC).
  - `END DH ENCODING` must wipe out encoded buffer in case user rejects encoding.
Testing: Primary test for this part is `signTransactionCommandsDH.js` and `signTransactionCommandsDHAndCountedSections.js`
The component is new.


## C source files index

- `signTransaction.c/h` - Source file divided into sections.
  - `MISC`- Main handler
  - `INIT` - INIT and FINISH subcalls
  - `APPEND_CONST_DATA` - APPEND_CONST_DATA subcall
  - `APPEND_DATA` - APPEND_DATA subcall
  - `SHOW_MESSAGE` - SHOW_MESSAGE subcall
  - `START COUNTED SECTION` - Counted section subcalls
  - `END COUNTED SECTION` - Counted section subcalls
  - `STORE_VALUE` - STORE_VALUE subcall
  - `START DH ENCODING` - DH subcalls
  - `END DH ENCODING` - DH subcalls
  - `FINISH` - INIT and FINISH subcalls
  - `MAIN HANDLER` - MAIN HANDLER
- `signTransactionCountedSections.c/h` - Counted section component
- `signTransactionIntegrity.c/h` - App integrity component
- `signTransactionParse.c/h` - Parsing component

