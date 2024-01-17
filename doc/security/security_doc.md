# FIO Ledger App security documentation

For purpose of this documentation we divide the app into following parts:
- Main app
- Common components
- Simple calls (getSerial, getVersion, runTests)
- Get public key call
- DecodeDH call
- Sign transaction call

## Main app

- `handlers.c/h`
Lookup handler function.
Tests: Speculos tests for respective calls
Change: Add decode_handleAPDU handler

- `menu*.c/h`
Menu.
Testing: Manual on device test
No change

- `state.c/h`
App state.
Security concerns:
- It is important to wipe out the state when new APDU sequence is initiated. (handled by main.c)
Testing: Speculos tests for respective calls
Change: Add state for DH decoding

- `main.c`
Main app
Security concerns:
- Wipe out app state when new APDU sequence is initiated
- Terminate APDU sequence in case of an error (so that the state is wiped out).
Testing: Speculos tests for respective calls
Change: Minor cleanup


## Common components

The files in this section offer services to the rest of the app. 

- `assert.c/h`
Introduces assert function and macros.
Testing: Speculos tests for respective calls
No modification. 

- `bip44.c/h` 
Types and function working with BIP44 derivation paths 
Testing: Unit tests present
Change: LE to BE transition

- `common.h` 
Header to be included in many source files
No modification. 

- `diffieHellman.c/h`
Diffie-Hellman key derivation, encoding, and decoding function and related types.
Encoding works as a stream with two buffers. One buffer is for DH encoding itself, second buffer is for base64 encoding. Decoding occurs in one go.
Security concerns:
- Wipe out intermediate secrets even in the case of failure
- Callers must wipe out retrieved secrets even in the case of failure
Testing: This files have unit tests covering all aspects of their functionality
These files are new.

- `eos_utils.c/h`
Helpers for FIO signature calculation / conversion. 
Security concerns:
- Functions use cryptographicaly sensitive data, but do not create any new secrets/coppies of secrets. 
- Caller is responsible for wiping out the secrets provided to these functions.
Testing: Speculos tests for signTx calls
No modification. 

- `errors.h`
List of error codes
Change: New error codes for integrity check and HMAC validation failure.

- `fio.c/h`
FIO chain helper functions.
Testing: Speculos tests for signTx calls
Minor cleanup.

- `glyphs.c/h`
Generated files containing icons

- `hash.h`
Hash calculation helper functions.
Testing: Speculos tests for signTx calls (including DH encryption)
Change: Added SHA-512.

- `hexUtils.c/h`
Hex encoding and decoding.
Testing: Covered by unit tests.
Change: Formatting change.

- `io.c/h`
IO helper functions
Testing: Speculos tests for various calls
No change

- `keyDerivation.c/h`
Key derivation functions
Security concerns:
- Wipe out intermediate secrets even in the case of failure
- Callers must wipe out retrieved secrets even in the case of failure
Testing: This files have unit tests
Minor cleanup.

- `securityPolicy.c/h`
Defines security policies for all relevant aspects of the app
Change: Policies modified doe to app changes with the focus on cryptographicaly sensitive events.

- `testUtils.h`
Test utils.
No change.

- `textUtils.c/h`
Text utils
Testing: Unit tests present
Change: Formatting change.

- `uiElements.h`
Helpers to declare UI elements
No change.

- `uiHelpers*.c/h`
Helpers for UI steps declaration
Change: wipes out the value to be returned in case of reject.

- `uiScreens.c/h`
Helpers for displaying UI screens.
Testing: Speculos tests for various calls
Minor cleanup.

- `utils.h`
Defines various macros used in the code.
Testing: Speculos tests for various calls
Change: New MARK_UNUSED_NO_DEVEL macro, formatting.


## Simple calls (getSerial, getVersion, runTests)

- `getSerial.c/h`
Get serial call
Testing: Speculos tests for getSerial call
No change

- `getVersion.c/h`
Get version call
Testing: Speculos tests for getVersion call
No change

- `runTests.c/h`
Run tests call.
Testing: For DEVEL mode only, unit tests are ran in Speculos.
Changes: Add new unit tests: run_diffieHellman_test(), run_integrityCheck_test(), run_countedSection_test(), remove endian unit tests (functions were removed)


## Get public key call

- `getPublicKey.c/h`
Get public key call. To store data `instructionState.getKeyContext` is used (see `state.h`).
Testing: Speculos tests for getPublicKey call
New debugging printouts.


## DecodeDH call

- `decodeDH.c/h`
Decode DH call. To store data `instructionState.decodeContext` (`*ctx`) is used (see `state.h`).
The call is served using multi APDU sequence.
- APDUs with `P1=0x01` are used to receive data and store it into `ctx->buffer`. Further APDUs extend the buffer. 
- APDU with `P1=0x02` asks for decodes the message and shows its content (interpretation depending on `P2`) and asks for confirmation.
- APDUs with `P1=0x03` the device to send next chunk of decoded data.
Security concerns:
- Wipe out secrets. For decoding, all secrets are handled solely by`diffieHellman.c/h`.
- Wipe out the decoded buffer in case user rejects sending the decoded message or in case of an error.
Testing: Speculos tests for decodeDH call
New file


## Sign transaction call

- `signTransaction*.c/h`
See [Sign Transaction](security_sign.md)


## C source files index

References to where source files are covered:
- `assert.c/h` - Common components
- `bip44.c/h` - Common components
- `common.h` - Common components
- `decodeDH.c/h`- Decode call
- `diffieHellman.c/h`- Common components
- `eos_utils.c/h` - Common components
- `errors.h` - Common components
- `fio.c/h` - Common components
- `getPublicKey.c/h` - Get public key call
- `getSerial.c/h` - Simple calls
- `getVersion.c/h` - Simple calls
- `glyphs.c/h` - Common components
- `handlers.c/h` - Main app
- `hash.h` - Common components
- `hexUtils.c/h` - Common components
- `io.c/h` - Common components
- `keyDerivation.c/h` - Common components
- `main.c` - Main app
- `menu*.c/h` - Main app
- `runTests.c/h` - simple calls
- `securityPolicy.c/h` - Common components
- `signTransaction*.c/h` - Sign  transaction call
- `state.c/h` - Main app
- `testUtils.h` - Common components
- `textUtils.c/h` - Common components
- `uiElements.h` - Common components
- `uiHelpers*.c/h` - Common components
- `uiScreens.c/h` - Common components
- `utils.h` - Common components

