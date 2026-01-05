import { execSync  } from 'child_process';
import assert from 'assert/strict';
import { basename } from 'path';

function humanTime() {
	const now = new Date();
	const pad = (n, z = 2) => String(n).padStart(z, '0');
	return pad(now.getHours()) + ':' + pad(now.getMinutes()) + ':' + pad(now.getSeconds()) + '.' + pad(now.getMilliseconds(), 3);
}

function syncBackTicks(command) {
	if (process.env.TEST_DEBUG >= 1) {
		console.log(humanTime() + " syncBackTicks() // command: " + command);
	}
	const curl_bash = execSync( command );
	const output = curl_bash.toString().trim();
	if (process.env.TEST_DEBUG >= 1) {
		console.log(humanTime() + " syncBackTicks() // command: " + output);
	}
	return output;
}

function testStart(scriptName) { // e.g. test-basic-slot-status-set.js
	console.log(humanTime() + " " + "vv".repeat(63) + " testStart() // " + scriptName);
	console.log(humanTime() + " // re-run with TEST_PNG_RE_GEN_FOR=" + scriptName + " to regenerate PNGs, TEST_IGNORE_SHA256_SUMS=1 to ignore all PNGs, TEST_DEBUG=1 for extra debug output");
	syncBackTicks('rm -f ' + scriptName + '.*.png.new.png');
	if (process.env.TEST_PNG_RE_GEN_FOR && (scriptName.substring(0, process.env.TEST_PNG_RE_GEN_FOR.length) == process.env.TEST_PNG_RE_GEN_FOR)) {
		console.log(humanTime() + " curlScreenShot() // TEST_PNG_RE_GEN_FOR detected; deleting PNGs for this test");
		syncBackTicks('rm -f ' + scriptName + '.*.png');
	}
}

function testCombo(scriptNameCombo) {
	console.log(humanTime() + " " + "v ".repeat(63) + " testCombo() // " + scriptNameCombo);
}

function testStep(asciiGraphic, scriptNameStep) {
	console.log(humanTime() + asciiGraphic.repeat(21) + "  testStep()  // " + scriptNameStep);
}

function testEnd(scriptName) { // e.g. test-basic-slot-status-set.js
	console.log(humanTime() + " " + "^^".repeat(63) + " testEnd()   // " + scriptName);
}


function hex2ascii(hex) {
	let str = '';
	for (let i = 0; i < hex.length; i += 2)
		str += String.fromCharCode(parseInt(hex.substr(i, 2), 16));
	return str;
}

function compare(givenHex, expected, whatGiven, parts) {
	//console.log(humanTime() + " compare() // givenHex:" + givenHex + " expected:" + expected);
	let givenHexExploded = "";
	let expectedExploded = "";
	let signatureCompact = "";
	let p = 0;
	let foundHexMismatch = "";
	let foundLenMismatch = "";
	for (const [key, value] of Object.entries(parts)) {
		const givenHexSubstring = givenHex.substring(p, p + (value * 2));
		const expectedSubstring = expected.substring(p, p + (value * 2));
		const expectedSubstringLength = (key == "unexpected") ? 0 : (value * 2);
		if ((key.substring(0, 15) != "do_not_compare_") && (givenHexSubstring != expectedSubstring)) {
			foundHexMismatch = key;
		}
		if (expectedSubstring.length != expectedSubstringLength) {
			foundLenMismatch = key;
		}
		givenHexExploded = givenHexExploded + key + ':' + givenHexSubstring + ' ';
		expectedExploded = expectedExploded + key + ':' + expectedSubstring + ' ';
		if (key == 'signatureCompact') {
			const hex = givenHex.substring(p, p + (value * 2));
			signatureCompact = "; signatureCompact.ascii:" + hex2ascii(hex);
		}
		p += value * 2;
	}
	console.log(humanTime() + " compare() // givenHexExploded:" + givenHexExploded + " <- " + whatGiven + signatureCompact);
	console.log(humanTime() + " compare() // expectedExploded:" + expectedExploded);
	if (foundHexMismatch != "") {
		console.log(humanTime() + " compare() // expected named part '" + foundHexMismatch + "' has WRONG hex digits");
		throw new Error();
	}
	if (foundLenMismatch != "") {
		console.log(humanTime() + " compare() // expected named part '" + foundLenMismatch + "' has WRONG length");
		throw new Error();
	}
}

function compareInAPDU(transport, expected, whatGiven, parts) {
	const givenHex = transport.hexApduCommandIn.shift();
	compare(givenHex, expected, whatGiven, parts);
}

function compareOutAPDU(transport, expected, whatGiven, parts) {
	const givenHex = transport.hexApduCommandOut.shift();
	compare(givenHex, expected, whatGiven, parts);
}

function noMoreAPDUs(transport) {
	if ((transport.hexApduCommandIn.length !== 0) || (transport.hexApduCommandOut.length !== 0)) {
		throw new Error();
	}
}

function compareGetVersionAPDUs(transport) {
	let hexExpected = "3300000000";
	compareOutAPDU(transport, hexExpected, "apdu command", {cla:1, ins:1, p1:1, p2:1, len:1, unexpected:9999});
	hexExpected = "00xxxxxx00xxxxxxxx9000"; 
	compareInAPDU(transport, hexExpected, "apdu response", {testMode:1, do_not_compare_major:1, do_not_compare_minor:1, do_not_compare_patch:1, deviceLocked:1, do_not_compare_targetId:4, returnCode:2, unexpected:9999});
}



function timeout(ms) {
	return new Promise(resolve => setTimeout(resolve, ms));
}

async function sleep(ms, what) {
	if (process.env.TEST_DEBUG >= 1) {console.log(humanTime() + " sleep() // " + ms + "ms <- " + what);}
	await timeout(ms);
}

function getScriptName(path) {
    return "snapshots/"+basename(path).replace(".js", "");
}

function getSpeculosDefaultConf() {
	return {
        testOn: process.env.TEST_ON_DEVICE ? "ledger": "speculos",
	    speculosApiPort: process.env.TEST_SPECULOS_API_PORT ? process.env.TEST_SPECULOS_API_PORT : 5000,
	    speculosApduPort: process.env.TEST_SPECULOS_APDU_PORT ? process.env.TEST_SPECULOS_APDU_PORT : 40000,
	    deviceType: process.env.TEST_DEVICE, //nanos, nanox, nanosp
		snapshotName: process.env.TEST_DEVICE,
	};
}

function getAPDUDataBuffer(constHex, varHex) {
	assert.equal(constHex.length % 2, 0);
	assert.equal(varHex.length % 2, 0);
    const constBuffer = Buffer.from(constHex, "hex")
    const varBuffer = Buffer.from(varHex, "hex")
	const buf = Buffer.allocUnsafe(2);	
	buf.writeUInt8(constBuffer.length, 0);
	buf.writeUInt8(varBuffer.length, 1);
	return Buffer.concat([buf, constBuffer, varBuffer])
}

export {testStart, testCombo, testStep, testEnd, compareInAPDU, compareOutAPDU, noMoreAPDUs, compareGetVersionAPDUs, humanTime, sleep, getScriptName, syncBackTicks, getSpeculosDefaultConf, getAPDUDataBuffer};
