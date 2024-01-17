'use strict';
import SpeculosTransport from "@ledgerhq/hw-transport-node-speculos";
import TransportNodeHid from "@ledgerhq/hw-transport-node-hid"

async function getTransport(speculosConf) {
	let transport = 0;
	if (speculosConf.testOn === "ledger") {
		transport = await TransportNodeHid.default.create(1000);
	}
	else {
		transport = await SpeculosTransport.default.open({ apduPort: speculosConf.speculosApduPort });
	}
    return transport;	
}

export {getTransport};
