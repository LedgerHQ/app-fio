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

CONTAINER_FULL_NAME = ghcr.io/ledgerhq/ledger-app-builder/ledger-app-dev-tools:latest
	
define run_announce
	@perl -e 'use Time::HiRes; use POSIX; $$ts = sprintf qq[%f], Time::HiRes::time(); ($$f) = $$ts =~ m~(\....)~; printf qq[%s%s %s make: %s\n], POSIX::strftime("%H:%M:%S", gmtime), $$f, q[-] x 126, $$ARGV[0];' "$(1)"
endef

ifdef NO_PULL
DOCKER_SPECULOS_PULL_COMMAND =
else
DOCKER_SPECULOS_PULL_COMMAND = docker pull $(CONTAINER_FULL_NAME)
endif

define start_speculos_container
	$(DOCKER_SPECULOS_PULL_COMMAND)
	docker run --detach --name speculos-port-$(1) --rm -it -v $(CURDIR):/app --publish $(1):$(1) --publish $(2):$(2) $(CONTAINER_FULL_NAME) speculos $(SPECULOS_SDK_STRING) --seed $(WORDS) --display headless --apdu-port $(2) --api-port $(1) /app/build/$(BUILD_DEVICE)/bin/app.elf
	rm -f $(CURDIR)/speculos-port-$(1).log ; touch $(CURDIR)/speculos-port-$(1).log ; docker logs --follow speculos-port-$(1) 2>&1 | tee -a $(CURDIR)/speculos-port-$(1).log > /dev/null 2>&1 & perl -e 'use Time::HiRes; $$t1=Time::HiRes::time(); while(1){ $$o=`cat $(CURDIR)/speculos-port-$(1).log`; if($$o =~ m~apdu: Server started~s){ printf qq[# detected -- via log -- speculos listening after %f seconds; spy on emulated device via http://localhost:$(1)/\n], Time::HiRes::time() - $$t1; exit; } Time::HiRes::sleep(0.01); };'
endef
	
define stop_speculos_container
	# make: todo: using --time 0 because this stops the docker container faster; but it still takes ~ 2.4 seconds... how to stop faster?
	docker stop --timeout 0 speculos-port-$(1)
	@pkill -f "docker logs --follow speculos-port-$(1)" || true
endef

.PHONY: speculos_port_5001_start
speculos_port_5001_start:
	$(call run_announce,$@)
	$(call start_speculos_container,5001,40001)

.PHONY: speculos_port_5001_stop
speculos_port_5001_stop:
	$(call run_announce,$@)
	$(call stop_speculos_container,5001)




