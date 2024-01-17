import { testStart, testStep, testEnd, getScriptName, getSpeculosDefaultConf, getAPDUDataBuffer } from "./speculos-common.js"
import { getTransport } from "./speculos-transport.js"
import { getButtonsAndSnapshots } from "./speculos-buttons-and-snapshots.js"
import { fileURLToPath } from 'url';
import assert from 'assert/strict';
import PublicKey from '@fioprotocol/fiojs/dist/ecc/key_public.js';
import crypto from "crypto"
import Signature from '@fioprotocol/fiojs/dist/ecc/signature.js';

const scriptName = getScriptName(fileURLToPath(import.meta.url));
testStart(scriptName);

const speculosConf = getSpeculosDefaultConf();
const transport = await getTransport(speculosConf);
const device = getButtonsAndSnapshots(scriptName, speculosConf);

//We will use 44'/235'/0'/0/0 in this test
const publicKeyHex = "04a9a222bc3b1a5a58ada17d10069b3961ebd0f917d4b2106031a061915ca9cc24a06941e0a4c0d5e266850ff980ad349ab8b027c93bf4aead1984168ad43e30ab";
const publicKey = PublicKey(Buffer.from(publicKeyHex,"hex"))

//this validates errors:
function err(errno) {
    return (err) => {
        assert.strictEqual(err.name, 'TransportStatusError');
        assert.strictEqual(err.statusCode, errno);
        return true;
    }
}

await device.makeStartingScreenshot();

console.log("This test requires app in DEVEL mode.")

//This test is not completely standardized
//!!!!!! - indicates places where test may reasonably break as Speculos sometimes does not react to every buttonpress.

//-------------------------------------------------------------------------------------
testStep(" - - -", "Sign transaction using storage");
{
    //INIT chainId=b20901380af44ef59c5918439a1f9a41d83669020319a80574b804a5f95cbd7e path=44'/235'/0'/0/0
    const buffer11 = getAPDUDataBuffer("", "b20901380af44ef59c5918439a1f9a41d83669020319a80574b804a5f95cbd7e052c000080eb000080000000800000000000000000");
    console.log(buffer11.toString("hex"))
    const promise11 = transport.send(215, 0x20, 0x01, 0, buffer11);
    await device.curlScreenShot();
    device.curlButton("both", "Confirm chain"); //!!!!!!
    const response11 = await promise11;
    assert.equal(response11.toString("hex"), "9000");

    //Store data to register1
    const buffer12 = getAPDUDataBuffer("", "001122334455");
    const promise12 = transport.send(215, 0x20, 0x07, 0x01, buffer12);
    const response12 = await promise12;
    assert.equal(response12.toString("hex"), "9000");

    //Store data to register3
    const buffer13 = getAPDUDataBuffer("", "00112233445566778899aa");
    const promise13 = transport.send(215, 0x20, 0x07, 0x03, buffer13);
    const response13 = await promise13;
    assert.equal(response13.toString("hex"), "9000");

    //SHOW DATA 01-hexstring, 01-no validation, 0000000000000000-min, 0000000000000000-max, 15-policy, Key = "HexString" (09486578537472696e67)
    const buffer14 = getAPDUDataBuffer("0101000000000000000000000000000000001509486578537472696e67", "001122334455");
    const promise14 = transport.send(215, 0x20, 0x04, 0, buffer14);
    await device.curlScreenShot();
    device.curlButton("both", "Confirm message"); //!!!!!!
    const response14 = await promise14;
    assert.equal(response14.toString("hex"), "9000");

    //SHOW DATA 02-hexstring, 01-no validation, 0000000000000000-min, 0000000000000000-max, 35-policy, Key = "HexString" (09486578537472696e67)
    const buffer15 = getAPDUDataBuffer("0101000000000000000000000000000000003509486578537472696e67", "00112233445566778899aa");
    const promise15 = transport.send(215, 0x20, 0x04, 0, buffer15);
    await device.curlScreenShot();
    device.curlButton("both", "Confirm message"); //!!!!!!
    const response15 = await promise15;
    assert.equal(response15.toString("hex"), "9000");
    
    //Finish 
    const buffer19 = getAPDUDataBuffer("", "");
    const promise19 = transport.send(215, 0x20, 0x10, 0, buffer19);
    await device.curlScreenShot();
    await device.curlButtonAndScreenshot("both", "Confirm sign with");
    await device.curlButtonAndScreenshot("right", "Confirm sign with");
    const response19 = await promise19;

    //The signed message should contain chainId + 0102030405
    const msg1 = Buffer.from("b20901380af44ef59c5918439a1f9a41d83669020319a80574b804a5f95cbd7e"
                            +"001122334455"
                            +"00112233445566778899aa", "hex");
    const hash1 = crypto.createHash('sha256').update(msg1).digest('hex')
    const ledgerSignature1 = Signature.fromHex(response19.slice(0, 65));
    assert.equal(response19.slice(65,65+32).toString("hex"), hash1);
    assert.equal(response19.slice(65+32,65+32+4).toString("hex"), "9000");
    assert.equal(ledgerSignature1.verify(msg1, publicKey), true);
}
//-------------------------------------------------------------------------------------
testStep(" - - -", "Storing too long data");
{
    //INIT chainId=b20901380af44ef59c5918439a1f9a41d83669020319a80574b804a5f95cbd7e path=44'/235'/0'/0/0
    const buffer11 = getAPDUDataBuffer("", "b20901380af44ef59c5918439a1f9a41d83669020319a80574b804a5f95cbd7e052c000080eb000080000000800000000000000000");
    console.log(buffer11.toString("hex"))
    const promise11 = transport.send(215, 0x20, 0x01, 0, buffer11);
    await device.curlScreenShot();
    device.curlButton("both", "Confirm chain"); //!!!!!!
    const response11 = await promise11;
    assert.equal(response11.toString("hex"), "9000");

    //Store data to register1
    const buffer12 = getAPDUDataBuffer("", "00112233445566778899");
    const promise12 = transport.send(215, 0x20, 0x07, 0x01, buffer12);
    await assert.rejects(promise12, err(0x6e07));

    await device.makeStartingScreenshot();
}
//-------------------------------------------------------------------------------------
testStep(" - - -", "Data do not match");
{
    //INIT chainId=b20901380af44ef59c5918439a1f9a41d83669020319a80574b804a5f95cbd7e path=44'/235'/0'/0/0
    const buffer11 = getAPDUDataBuffer("", "b20901380af44ef59c5918439a1f9a41d83669020319a80574b804a5f95cbd7e052c000080eb000080000000800000000000000000");
    console.log(buffer11.toString("hex"))
    const promise11 = transport.send(215, 0x20, 0x01, 0, buffer11);
    await device.curlScreenShot();
    device.curlButton("both", "Confirm chain"); //!!!!!!
    const response11 = await promise11;
    assert.equal(response11.toString("hex"), "9000");

    //Store data to register1
    const buffer12 = getAPDUDataBuffer("", "001122334455");
    const promise12 = transport.send(215, 0x20, 0x07, 0x01, buffer12);
    const response12 = await promise12;
    assert.equal(response12.toString("hex"), "9000");

    //SHOW DATA 01-hexstring, 01-no validation, 0000000000000000-min, 0000000000000000-max, 15-policy, Key = "HexString" (09486578537472696e67)
    const buffer14 = getAPDUDataBuffer("0101000000000000000000000000000000001509486578537472696e67", "001122334456");
    const promise14 = transport.send(215, 0x20, 0x04, 0, buffer14);
    await assert.rejects(promise14, err(0x6e07));

    await device.makeStartingScreenshot();
}
//-------------------------------------------------------------------------------------
testStep(" - - -", "Data do not match using name conversion");
{
    //INIT chainId=b20901380af44ef59c5918439a1f9a41d83669020319a80574b804a5f95cbd7e path=44'/235'/0'/0/0
    const buffer11 = getAPDUDataBuffer("", "b20901380af44ef59c5918439a1f9a41d83669020319a80574b804a5f95cbd7e052c000080eb000080000000800000000000000000");
    console.log(buffer11.toString("hex"))
    const promise11 = transport.send(215, 0x20, 0x01, 0, buffer11);
    await device.curlScreenShot();
    device.curlButton("both", "Confirm chain"); //!!!!!!
    const response11 = await promise11;
    assert.equal(response11.toString("hex"), "9000");

    //Store data to register1
    const buffer12 = getAPDUDataBuffer("", "0011223344556677");
    const promise12 = transport.send(215, 0x20, 0x07, 0x01, buffer12);
    const response12 = await promise12;
    assert.equal(response12.toString("hex"), "9000");

    //SHOW DATA 02-string, 01-no validation, 0000000000000000-min, 0000000000000000-max, 45-policy, Key = "HexString" (09486578537472696e67)
    const buffer14 = getAPDUDataBuffer("0201000000000000000000000000000000004509486578537472696e67", "0011223344556677");
    const promise14 = transport.send(215, 0x20, 0x04, 0, buffer14);
    await assert.rejects(promise14, err(0x6e07));

    await device.makeStartingScreenshot();
}


await transport.close();
testEnd(scriptName);
process.stdin.pause();

