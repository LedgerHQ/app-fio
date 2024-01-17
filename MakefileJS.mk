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

.PHONY: js-yarn
js-yarn:
	cd ledgerjs-fio && yarn && cd ..

.PHONY: js-prepack
js-prepack:
	cd ledgerjs-fio && yarn prepack && cd ..
	
.PHONY: js-lint
js-lint:
	cd ledgerjs-fio && yarn lint && cd ..

.PHONY: js-clean
js-clean:
	cd ledgerjs-fio && yarn clean && cd ..

.PHONY: js-build
js-build:
	cd ledgerjs-fio && yarn build && cd ..

.PHONY: js-build-flowtypes
js-build-flowtypes:
	cd ledgerjs-fio && yarn build:flowtypes && cd ..

.PHONY: js-flow
js-flow:
	cd ledgerjs-fio && yarn flow && cd ..

.PHONY: js-gen-docs
js-gen-docs:
	cd ledgerjs-fio && yarn gen-docs && cd ..

.PHONY: js-prepublish
js-prepublish:
	cd ledgerjs-fio && yarn prepublish && cd ..

.PHONY: js-run-example
js-run-example:
	cd ledgerjs-fio && yarn run-example && cd ..

