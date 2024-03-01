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

ifneq ($(BOLOS_SDK),)
$(error Containerized build, BOLOS_SDK should be empty)
endif

APP_BUILDER_IMAGE = ledger-app-builder:3.9.0

default_target: build

ifdef INTERACTIVE
INTERACTIVE_SETTING:="-i"
TTY_SETTING:="-t"
else
INTERACTIVE_SETTING:=
TTY_SETTING:=
endif

ifdef NO_PULL
DOCKER_PULL_COMMAND =
else
DOCKER_PULL_COMMAND = docker pull ghcr.io/ledgerhq/ledger-app-builder/$(APP_BUILDER_IMAGE)
endif

#We build the container from source to avoid this issue https://github.community/t/docker-pull-from-public-github-package-registry-fail-with-no-basic-auth-credentials-error/16358
define run_docker	
	$(DOCKER_PULL_COMMAND)
	docker image tag ghcr.io/ledgerhq/ledger-app-builder/$(APP_BUILDER_IMAGE) ledger-app-builder
	@echo "docker host: id -u: `id -u`"
	@echo "docker host: whoami: `whoami`"
	docker version
	docker run $(TTY_SETTING) $(INTERACTIVE_SETTING) $(MAKE_LINUX_DOCKER_OPTIONS) --rm \
	-e SCP_PRIVKEY=$(SCP_PRIVKEY) \
	-e BOLOS_ENV_IGNORE=/opt/bolos \
	-e COIN=$(COIN) \
	-e APP_TESTING=$(APP_TESTING) \
	-e BOLOS_SDK=$(BOLOS_SDK_DIRECTORY) \
	-e DEVEL=$(DEVEL) \
	-e TARGET_NAME=$(TARGET_NAME) \
	-e NO_INTEGRITY_CHECK=$(NO_INTEGRITY_CHECK) \
	-u $(USERID):$(USERID) \
	-v $(shell pwd):/app \
	$(1) \
	ledger-app-builder \
	$(2)
endef

##############
#   Build    #
##############

.PHONY: shell
shell:
	$(call run_docker, -ti, bash)

.PHONY: build
build: 
	$(call run_docker, , make build)
	
.PHONY: all
all: 
	$(call run_docker, , make all)

.PHONY: clean
clean:
	$(call run_docker, , make clean)
	
.PHONY: listvariants
listvariants:
	$(call run_docker, , make listvariants)

.PHONY: size
size:
	$(call run_docker, , make size)


##############
#   Style    #
##############

.PHONY: format
format:
	$(call run_docker, , make format)

#Does not work in non-containerized build
.PHONY: scan-build
scan-build:
	$(call run_docker, , make scan-build)


