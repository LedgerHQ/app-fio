#*******************************************************************************
#   Ledger Nano S
#   (c) 2016 Ledger
#
#  Licensed under the Apache License, Version 2.0 (the "License");
#  you may not use this file except in compliance with the License.
#  You may obtain a copy of the License at
#
#      http://www.apache.org/licenses/LICENSE-2.0
#
#  Unless required by applicable law or agreed to in writing, software
#  distributed under the License is distributed on an "AS IS" BASIS,
#  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
#  See the License for the specific language governing permissions and
#  limitations under the License.
#*******************************************************************************

# We use BOLOS_SDK to determine the development environment that is being used
# BOLOS_SDK IS  DEFINED	 	We use the plain Makefile for Ledger
# BOLOS_SDK NOT DEFINED		We use a containerized build approach
# containerize build is recommended

APPVERSION_M = 1
APPVERSION_N = 0
APPVERSION_P = 5

NANOS_ID = 1
WORDS = "abandon abandon abandon abandon abandon abandon abandon abandon abandon abandon abandon about"
PIN = 5555

SPECULOS_MODEL_SWITCH=nanos
NANO_ICON_GIF=icon_fio_nanos.gif
BOLOS_SDK_DIRECTORY=/opt/nanos-secure-sdk
TARGET_NAME=TARGET_NANOS
TEST_DEVICE=nanos
SPECULOS_SDK_STRING= --sdk 2.1
ifeq ($(TARGET_DEVICE), NANO_X)
    $(info Targeting NanoX)
    SPECULOS_MODEL_SWITCH=nanox
    NANO_ICON_GIF=icon_fio_nanox.gif
    BOLOS_SDK_DIRECTORY=/opt/nanox-secure-sdk
    TARGET_NAME=TARGET_NANOX
    TEST_DEVICE=nanox
    SPECULOS_SDK_STRING=
endif
ifeq ($(TARGET_DEVICE), NANO_SP)
    $(info Targeting NanoSPlus)
    SPECULOS_MODEL_SWITCH=nanosp
    NANO_ICON_GIF=icon_fio_nanox.gif
    BOLOS_SDK_DIRECTORY=/opt/nanosplus-secure-sdk
    TARGET_NAME=TARGET_NANOS2
    TEST_DEVICE=nanosp
    SPECULOS_SDK_STRING=
endif

ifeq ($(TARGET_DEVICE), STAX)
    $(info Targeting STAX)
    SPECULOS_MODEL_SWITCH=stax
    NANO_ICON_GIF=icon_fio_stax.png
    BOLOS_SDK_DIRECTORY=/opt/stax-secure-sdk
    TARGET_NAME=TARGET_STAX
    TEST_DEVICE=stax
    SPECULOS_SDK_STRING=
endif


ifeq ($(BOLOS_SDK),)
include $(CURDIR)/MakefileContainer.mk
else
include $(CURDIR)/MakefileLocal.mk
endif

include $(CURDIR)/MakefilePhysicalDevice.mk

include $(CURDIR)/MakefileSpeculos.mk

include $(CURDIR)/MakefileJS.mk

include $(CURDIR)/MakefileTest.mk

