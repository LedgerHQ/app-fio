cmake_minimum_required(VERSION 3.10)

project(FioFuzzer VERSION 0.1 LANGUAGES C)

set(CMAKE_C_STANDARD 11)

# BOLOS SDK
set(BOLOS_SDK $ENV{BOLOS_SDK})
add_compile_definitions(IO_HID_EP_LENGTH=64)

add_compile_definitions(HAVE_ECC HAVE_HASH HAVE_HMAC HAVE_SHA256 HAVE_SHA512 HAVE_AES HAVE_ECDH HAVE_RNG HAVE_RIPEMD160 HAVE_ECDSA HAVE_ECC_WEIERSTRASS HAVE_SECP256K1_CURVE DEVEL NO_INTEGRITY_CHECK HEADLESS)
include_directories(.
        ../src
        "${BOLOS_SDK}/include"
        "${BOLOS_SDK}/lib_cxng/include"
        "${BOLOS_SDK}/lib_ux/include"
)

add_compile_options(-g -ggdb2 -O3)

# Build with code coverage generation
if(CODE_COVERAGE)
    if(CMAKE_C_COMPILER_ID MATCHES "(Apple)?[Cc]lang")
        add_compile_options(-fprofile-instr-generate -fcoverage-mapping)
        add_link_options(-fprofile-instr-generate -fcoverage-mapping)
    elseif(CMAKE_C_COMPILER_ID MATCHES "GNU")
        add_compile_options(-fprofile-arcs -ftest-coverage)
        link_libraries(gcov)
    else()
        message(FATAL_ERROR "Unsupported compiler used with code coverage generation")
    endif()
endif()

# Fuzzer target
set(APP_SRC_DIR "../src")

add_definitions(
    -DAPPNAME="FIO"
    -DMAJOR_VERSION=1
    -DMINOR_VERSION=0
    -DPATCH_VERSION=6
    -DAPPVERSION="1.0.6"

    -DOS_IO_SEPROXYHAL
    -DIO_SEPROXYHAL_BUFFER_SIZE_B=128
    -DRESET_ON_CRASH
    
    -DHAVE_BAGL
    -DHAVE_SPRINTF
    -DHAVE_SNPRINTF_FORMAT_U
    -DHAVE_PENDING_REVIEW_SCREEN
    -DHAVE_IO_USB
    -DHAVE_L4_USBLIB
    -DIO_USB_MAX_ENDPOINTS=4
    -DIO_HID_EP_LENGTH=64
    -DHAVE_USB_APDU
    -DHAVE_WEBUSB
    -DWEBUSB_URL_SIZE_B=0
    -DWEBUSB_URL=""
    -DHAVE_BOLOS_APP_STACK_CANARY
)

set(APP_SOURCES
    ${APP_SRC_DIR}/assert.h
    ${APP_SRC_DIR}/assert.c
    ${APP_SRC_DIR}/bip44.h
    ${APP_SRC_DIR}/bip44.c
    ${APP_SRC_DIR}/decodeDH.h
    ${APP_SRC_DIR}/decodeDH.c
    ${APP_SRC_DIR}/diffieHellman.h
    ${APP_SRC_DIR}/diffieHellman.c
    ${APP_SRC_DIR}/eos_utils.h
    ${APP_SRC_DIR}/eos_utils.c
    ${APP_SRC_DIR}/fio.h
    ${APP_SRC_DIR}/fio.c
    ${APP_SRC_DIR}/getPublicKey.h
    ${APP_SRC_DIR}/getPublicKey.c
    ${APP_SRC_DIR}/getSerial.h
    ${APP_SRC_DIR}/getSerial.c    
    ${APP_SRC_DIR}/getVersion.h
    ${APP_SRC_DIR}/getVersion.c
    ${APP_SRC_DIR}/hash.h
    ${APP_SRC_DIR}/handlers.h
    ${APP_SRC_DIR}/handlers.c
    ${APP_SRC_DIR}/hexUtils.h
    ${APP_SRC_DIR}/hexUtils.c
    ${APP_SRC_DIR}/keyDerivation.h
    ${APP_SRC_DIR}/keyDerivation.c
    ${APP_SRC_DIR}/securityPolicy.h
    ${APP_SRC_DIR}/securityPolicy.c
    ${APP_SRC_DIR}/signTransaction.h
    ${APP_SRC_DIR}/signTransaction.c
    ${APP_SRC_DIR}/signTransactionCountedSection.h
    ${APP_SRC_DIR}/signTransactionCountedSection.c
    ${APP_SRC_DIR}/signTransactionIntegrity.h
    ${APP_SRC_DIR}/signTransactionIntegrity.c
    ${APP_SRC_DIR}/signTransactionParse.h
    ${APP_SRC_DIR}/signTransactionParse.c
    ${APP_SRC_DIR}/state.h
    ${APP_SRC_DIR}/state.c
    ${APP_SRC_DIR}/textUtils.h
    ${APP_SRC_DIR}/textUtils.c
    ${APP_SRC_DIR}/uiHelpers.h
    ${APP_SRC_DIR}/uiHelpers.c
    ${APP_SRC_DIR}/uiHelpers_nanos.c
    ${APP_SRC_DIR}/uiScreens.h
    ${APP_SRC_DIR}/uiScreens.c
    ${APP_SRC_DIR}/utils.h
)

add_executable(fuzz_message
        fuzz_fio.c
        os_mocks.c
        ${APP_SOURCES}
)

target_include_directories(fuzz_message PUBLIC ../src)
target_compile_options(fuzz_message PUBLIC -fsanitize=fuzzer,address,undefined -fno-sanitize-recover=undefined)
target_link_options(fuzz_message PUBLIC -fsanitize=fuzzer,address,undefined -fno-sanitize-recover=undefined)
