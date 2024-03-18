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

.PHONY: test-yarn
test-yarn:
	cd test-integration && yarn && yarn upgrade ledgerjs-hw-app-fio && cd ..
	
TESTS_SPECULOS_DIR=test-integration

define run_nodejs_test
	@cd $(TESTS_SPECULOS_DIR) \
	&& { { { \
          TEST_SPECULOS_API_PORT=$(1) TEST_SPECULOS_APDU_PORT=$(2) TEST_DEVICE=$(TEST_DEVICE) \
          APPVERSION_M=$(APPVERSION_M) APPVERSION_N=$(APPVERSION_N) APPVERSION_P=$(APPVERSION_P) \
          node $(3) 2>&1; echo $$? >&3; \
        } | tee -a ../speculos-port-$(1).log >&4; } 3>&1 | { read xs; exit $$xs; } } 4>&1
endef

.PHONY: speculos_port_5001_test_internal
speculos_port_5001_test_internal:
	$(call run_announce,$@)
#	$(call run_nodejs_test,5001,40001,getVersion.js)
	$(call run_nodejs_test,5001,40001,getSerial.js)
	$(call run_nodejs_test,5001,40001,getPublicKey.js)
	$(call run_nodejs_test,5001,40001,decodeMessage.js)
	$(call run_nodejs_test,5001,40001,signTransactionTrnsfiopubky.js)
	$(call run_nodejs_test,5001,40001,signTransactionNewfundsreq.js)
	$(call run_nodejs_test,5001,40001,signTransactionRecordobt.js)
	$(call run_nodejs_test,5001,40001,signTransactionAddaddress.js)
	$(call run_nodejs_test,5001,40001,signTransactionRemaddress.js)
	$(call run_nodejs_test,5001,40001,signTransactionAddnft.js)
	$(call run_nodejs_test,5001,40001,signTransactionRemnft.js)
	$(call run_nodejs_test,5001,40001,signTransactionOtherFioAddress.js)	
	$(call run_nodejs_test,5001,40001,signTransactionOtherFioReqobt.js)	
	$(call run_nodejs_test,5001,40001,signTransactionOtherFioStaking.js)	
	$(call run_nodejs_test,5001,40001,signTransactionOtherEosio.js)	
	$(call run_nodejs_test,5001,40001,signTransactionOtherFioOracle.js)	
	@echo "# ALL TESTS COMPLETED!" | tee -a speculos-port-5001.log

.PHONY: speculos_port_5001_unit_test_internal
speculos_port_5001_unit_test_internal:
	$(call run_announce,$@)
	$(call run_nodejs_test,5001,40001,runUnitTests.js)
	$(call run_nodejs_test,5001,40001,signTransactionCommandsBasic.js)
	$(call run_nodejs_test,5001,40001,signTransactionCommandsShowData.js)
	$(call run_nodejs_test,5001,40001,signTransactionCommandsCountedSection.js)
	$(call run_nodejs_test,5001,40001,signTransactionCommandsStorage.js)
	$(call run_nodejs_test,5001,40001,signTransactionCommandsDH.js)
	$(call run_nodejs_test,5001,40001,signTransactionCommandsDHAndCountedSections.js)
	@echo "# ALL TESTS COMPLETED!" | tee -a speculos-port-5001.log

.PHONY: speculos_port_5001_unit_test
speculos_port_5001_unit_test:
	$(call run_announce,$@)
	$(MAKE) --no-print-directory speculos_port_5001_start && ($(MAKE) --no-print-directory speculos_port_5001_unit_test_internal; ret=$$?;$(MAKE) --no-print-directory speculos_port_5001_stop;$(call run_announce,note: logs: cat /speculos-port-5001.log);cat speculos-port-5001.log; exit $$ret)

.PHONY: speculos_port_5001_test
speculos_port_5001_test:
	$(call run_announce,$@)
	$(MAKE) --no-print-directory speculos_port_5001_start && ($(MAKE) --no-print-directory speculos_port_5001_test_internal; ret=$$?;$(MAKE) --no-print-directory speculos_port_5001_stop;$(call run_announce,note: logs: cat speculos-port-5001.log);cat speculos-port-5001.log; exit $$ret)

.PHONY: get_integrity_hashes_from_logs
get_integrity_hashes_from_logs:
	sed -n -e  's/^.*Integrity check for: //p' speculos-port-5001.log

.PHONY: get_allowed_sequences_from_logs
get_allowed_sequences_from_logs:
	grep -e "vvvvvv testStart() // snapshots/signTransaction" -e "\^\^\^\^\^\^ testEnd()   // snapshots/signTransaction" -e "integrityCheckProcessInstruction:322" -e "Integrity check for" speculos-port-5001.log


#Test on physical device

.PHONY: ledger_test
ledger_test:
	$(call run_announce,$@)
	@cd $(TESTS_SPECULOS_DIR) && TEST_ON_DEVICE=LEDGER TEST_DEVICE=$(TEST_DEVICE) APPVERSION_M=$(APPVERSION_M) APPVERSION_N=$(APPVERSION_N) APPVERSION_P=$(APPVERSION_P) node getVersion.js
	@cd $(TESTS_SPECULOS_DIR) && TEST_ON_DEVICE=LEDGER TEST_DEVICE=$(TEST_DEVICE) APPVERSION_M=$(APPVERSION_M) APPVERSION_N=$(APPVERSION_N) APPVERSION_P=$(APPVERSION_P) node getSerial.js
	@cd $(TESTS_SPECULOS_DIR) && TEST_ON_DEVICE=LEDGER TEST_DEVICE=$(TEST_DEVICE) APPVERSION_M=$(APPVERSION_M) APPVERSION_N=$(APPVERSION_N) APPVERSION_P=$(APPVERSION_P) node getPublicKey.js
	@cd $(TESTS_SPECULOS_DIR) && TEST_ON_DEVICE=LEDGER TEST_DEVICE=$(TEST_DEVICE) APPVERSION_M=$(APPVERSION_M) APPVERSION_N=$(APPVERSION_N) APPVERSION_P=$(APPVERSION_P) node decodeMessage.js
	@cd $(TESTS_SPECULOS_DIR) && TEST_ON_DEVICE=LEDGER TEST_DEVICE=$(TEST_DEVICE) APPVERSION_M=$(APPVERSION_M) APPVERSION_N=$(APPVERSION_N) APPVERSION_P=$(APPVERSION_P) node signTransactionTrnsfiopubky.js
	@cd $(TESTS_SPECULOS_DIR) && TEST_ON_DEVICE=LEDGER TEST_DEVICE=$(TEST_DEVICE) APPVERSION_M=$(APPVERSION_M) APPVERSION_N=$(APPVERSION_N) APPVERSION_P=$(APPVERSION_P) node signTransactionNewfundsreq.js
	@cd $(TESTS_SPECULOS_DIR) && TEST_ON_DEVICE=LEDGER TEST_DEVICE=$(TEST_DEVICE) APPVERSION_M=$(APPVERSION_M) APPVERSION_N=$(APPVERSION_N) APPVERSION_P=$(APPVERSION_P) node signTransactionRecordobt.js
	@cd $(TESTS_SPECULOS_DIR) && TEST_ON_DEVICE=LEDGER TEST_DEVICE=$(TEST_DEVICE) APPVERSION_M=$(APPVERSION_M) APPVERSION_N=$(APPVERSION_N) APPVERSION_P=$(APPVERSION_P) node signTransactionAddaddress.js
	@cd $(TESTS_SPECULOS_DIR) && TEST_ON_DEVICE=LEDGER TEST_DEVICE=$(TEST_DEVICE) APPVERSION_M=$(APPVERSION_M) APPVERSION_N=$(APPVERSION_N) APPVERSION_P=$(APPVERSION_P) node signTransactionRemaddress.js
	@cd $(TESTS_SPECULOS_DIR) && TEST_ON_DEVICE=LEDGER TEST_DEVICE=$(TEST_DEVICE) APPVERSION_M=$(APPVERSION_M) APPVERSION_N=$(APPVERSION_N) APPVERSION_P=$(APPVERSION_P) node signTransactionAddnft.js
	@cd $(TESTS_SPECULOS_DIR) && TEST_ON_DEVICE=LEDGER TEST_DEVICE=$(TEST_DEVICE) APPVERSION_M=$(APPVERSION_M) APPVERSION_N=$(APPVERSION_N) APPVERSION_P=$(APPVERSION_P) node signTransactionRemaddress.js
	@cd $(TESTS_SPECULOS_DIR) && TEST_ON_DEVICE=LEDGER TEST_DEVICE=$(TEST_DEVICE) APPVERSION_M=$(APPVERSION_M) APPVERSION_N=$(APPVERSION_N) APPVERSION_P=$(APPVERSION_P) node signTransactionOtherFioAddress.js
	@cd $(TESTS_SPECULOS_DIR) && TEST_ON_DEVICE=LEDGER TEST_DEVICE=$(TEST_DEVICE) APPVERSION_M=$(APPVERSION_M) APPVERSION_N=$(APPVERSION_N) APPVERSION_P=$(APPVERSION_P) node signTransactionOtherFioReqobt.js
	@cd $(TESTS_SPECULOS_DIR) && TEST_ON_DEVICE=LEDGER TEST_DEVICE=$(TEST_DEVICE) node APPVERSION_M=$(APPVERSION_M) APPVERSION_N=$(APPVERSION_N) APPVERSION_P=$(APPVERSION_P) signTransactionOtherFioStaking.js
	#We don't do signTransactionEosio as it is too time consuming
	$(call run_nodejs_test,5001,40001,signTransactionOtherEosio.js)	
	@echo "# ALL TESTS COMPLETED!"
	
.PHONY: ledger_unit_test
ledger_unit_test:
	$(call run_announce,$@)
	@cd $(TESTS_SPECULOS_DIR) && TEST_ON_DEVICE=LEDGER TEST_DEVICE=$(TEST_DEVICE) node runUnitTests.js


