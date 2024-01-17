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
testStep(" - - -", "Sign minimal fake devel transaction containing SHOW_DATA instructions - testnet");
{
    //INIT chainId=b20901380af44ef59c5918439a1f9a41d83669020319a80574b804a5f95cbd7e path=44'/235'/0'/0/0
    const buffer11 = getAPDUDataBuffer("", "b20901380af44ef59c5918439a1f9a41d83669020319a80574b804a5f95cbd7e052c000080eb000080000000800000000000000000");
    const promise11 = transport.send(215, 0x20, 0x01, 0, buffer11);
    await device.curlScreenShot();
    device.curlButton("both", "Confirm chain"); //!!!!!!
    const response11 = await promise11;
    assert.equal(response11.toString("hex"), "9000");

    //SHOW DATA 01-hexstring, 02-validate length, 0000000000000000-min, 0800000000000000-max, 05-policy, Key = "HexString" (09486578537472696e67)
    const buffer12 = getAPDUDataBuffer("0102000000000000000008000000000000000509486578537472696e67", "0011223344556677");
    const promise12 = transport.send(215, 0x20, 0x04, 0, buffer12);
    await device.curlScreenShot();
    device.curlButton("both", "Confirm message"); //!!!!!!
    const response12 = await promise12;
    assert.equal(response12.toString("hex"), "9000");

    //SHOW DATA 02-string, 01-no validation, 0000000000000000-min, 0000000000000000-max, 05-policy, Key = "String" (06537472696e67)
    const buffer13 = getAPDUDataBuffer("0201000000000000000000000000000000000506537472696e67", "4e69636520616e64206c6f6e67206c6f6e67206c6f6e67206c6f6e6720737472696e67");
    const promise13 = transport.send(215, 0x20, 0x04, 0, buffer13);
    await device.curlScreenShot();
    device.curlButton("both", "Confirm message"); //!!!!!!
    const response13 = await promise13;
    assert.equal(response13.toString("hex"), "9000");

    //SHOW DATA 03-name, 01-no validation, 0000000000000000-min, 0000000000000000-max, 05-policy, Key = "NameString" (0a4e616d65537472696e67) Shows: "fio.token"
    const buffer14 = getAPDUDataBuffer("030100000000000000000000000000000000050a4e616d65537472696e67", "0000980ad20ca85b");
    const promise14 = transport.send(215, 0x20, 0x04, 0, buffer14);
    await device.curlScreenShot();
    device.curlButton("both", "Confirm message"); //!!!!!!
    const response14 = await promise14;
    assert.equal(response14.toString("hex"), "9000");

    //SHOW DATA 10-amount, 01-no validation, 0000000000000000-min, 0000000000000000-max, 05-policy, Key = "Amount" (06416d6f756e74)
    const buffer15 = getAPDUDataBuffer("1001000000000000000000000000000000000506416d6f756e74", "0100000000000000");
    const promise15 = transport.send(215, 0x20, 0x04, 0, buffer15);
    await device.curlScreenShot();
    device.curlButton("both", "Confirm message"); //!!!!!!
    const response15 = await promise15;
    assert.equal(response15.toString("hex"), "9000");

    //SHOW DATA 14-uint64, 01-no validation, 0000000000000000-min, 0000000000000000-max, 05-policy, Key = "Number" (064e756d626572)
    const buffer16 = getAPDUDataBuffer("14010000000000000000000000000000000005064e756d626572", "0200000000000000");
    const promise16 = transport.send(215, 0x20, 0x04, 0, buffer16);
    await device.curlScreenShot();
    device.curlButton("both", "Confirm message"); //!!!!!!
    const response16 = await promise16;
    assert.equal(response16.toString("hex"), "9000");

    //This is to test do not show policy
    //SHOW DATA 14-uint64, 01-no validation, 0000000000000000-min, 0000000000000000-max, 02-policy, Key = "Number" (064e756d626572)
    const buffer17 = getAPDUDataBuffer("14010000000000000000000000000000000002064e756d626572", "0300000000000000");
    const promise17 = transport.send(215, 0x20, 0x04, 0, buffer17);
    const response17 = await promise17;
    assert.equal(response17.toString("hex"), "9000");
    
    //Finish
    const buffer19 = getAPDUDataBuffer("", "");
    const promise19 = transport.send(215, 0x20, 0x10, 0, buffer19);
    await device.curlScreenShot();
    await device.curlButtonAndScreenshot("both", "Confirm sign with");
    await device.curlButtonAndScreenshot("right", "Confirm sign with");
    const response19 = await promise19;

    //The signed message should contain chainId + 0102030405
    const msg1 = Buffer.from("b20901380af44ef59c5918439a1f9a41d83669020319a80574b804a5f95cbd7e"
                           + "0011223344556677" 
                           + "4e69636520616e64206c6f6e67206c6f6e67206c6f6e67206c6f6e6720737472696e67"
                           + "0000980ad20ca85b"
                           + "0100000000000000"
                           + "0200000000000000"
                           + "0300000000000000"
            , "hex");
    const hash1 = crypto.createHash('sha256').update(msg1).digest('hex')
    const ledgerSignature1 = Signature.fromHex(response19.slice(0, 65));
    assert.equal(response19.slice(65,65+32).toString("hex"), hash1);
    assert.equal(response19.slice(65+32,65+32+4).toString("hex"), "9000");
    assert.equal(ledgerSignature1.verify(msg1, publicKey), true);
}
//-------------------------------------------------------------------------------------
testStep(" - - -", "Unknown data type leads to failure");
{
    //INIT chainId=b20901380af44ef59c5918439a1f9a41d83669020319a80574b804a5f95cbd7e
    const buffer11 = getAPDUDataBuffer("", "b20901380af44ef59c5918439a1f9a41d83669020319a80574b804a5f95cbd7e052c000080eb000080000000800000000000000000");
    const promise11 = transport.send(215, 0x20, 0x01, 0, buffer11);
    await device.curlScreenShot();
    device.curlButton("both", "Confirm chain"); //!!!!!!
    const response11 = await promise11;
    assert.equal(response11.toString("hex"), "9000");

    //SHOW DATA 00-unknown, 02-validate length, 0000000000000000-min, 0800000000000000-max, 05-policy, Key = "HexString" (09486578537472696e67)
    const buffer12 = getAPDUDataBuffer("0002000000000000000008000000000000000509486578537472696e67", "0011223344556677");
    const promise12 = transport.send(215, 0x20, 0x04, 0, buffer12);
    await assert.rejects(promise12, err(0x6e07));

    await device.makeStartingScreenshot();
}     
//-------------------------------------------------------------------------------------
testStep(" - - -", "Buffer does not pass length validation");
{
    //INIT chainId=b20901380af44ef59c5918439a1f9a41d83669020319a80574b804a5f95cbd7e
    const buffer11 = getAPDUDataBuffer("", "b20901380af44ef59c5918439a1f9a41d83669020319a80574b804a5f95cbd7e052c000080eb000080000000800000000000000000");
    const promise11 = transport.send(215, 0x20, 0x01, 0, buffer11);
    await device.curlScreenShot();
    device.curlButton("both", "Confirm chain"); //!!!!!!
    const response11 = await promise11;
    assert.equal(response11.toString("hex"), "9000");

    //SHOW DATA 01-hexstring, 02-validate length, 0000000000000000-min, 0800000000000000-max, 05-policy, Key = "HexString" (09486578537472696e67)
    const buffer12 = getAPDUDataBuffer("0102000000000000000008000000000000000509486578537472696e67", "001122334455667788");
    const promise12 = transport.send(215, 0x20, 0x04, 0, buffer12);
    await assert.rejects(promise12, err(0x6e07));

    await device.makeStartingScreenshot();
}
//-------------------------------------------------------------------------------------
testStep(" - - -", "Key length does not match");
{
    //INIT chainId=b20901380af44ef59c5918439a1f9a41d83669020319a80574b804a5f95cbd7e
    const buffer11 = getAPDUDataBuffer("", "b20901380af44ef59c5918439a1f9a41d83669020319a80574b804a5f95cbd7e052c000080eb000080000000800000000000000000");
    const promise11 = transport.send(215, 0x20, 0x01, 0, buffer11);
    await device.curlScreenShot();
    device.curlButton("both", "Confirm chain"); //!!!!!!
    const response11 = await promise11;
    assert.equal(response11.toString("hex"), "9000");

    //SHOW DATA 01-hexstring, 02-validate length, 0000000000000000-min, 0800000000000000-max, 05-policy, Key = "HexString" 08(09)486578537472696e67
    const buffer12 = getAPDUDataBuffer("0102000000000000000008000000000000000508486578537472696e67", "0011223344556677");
    const promise12 = transport.send(215, 0x20, 0x04, 0, buffer12);
    await assert.rejects(promise12, err(0x6e07));

    await device.makeStartingScreenshot();
}
//-------------------------------------------------------------------------------------
testStep(" - - -", "Key contains invalid symbols");
{
    //INIT chainId=b20901380af44ef59c5918439a1f9a41d83669020319a80574b804a5f95cbd7e
    const buffer11 = getAPDUDataBuffer("", "b20901380af44ef59c5918439a1f9a41d83669020319a80574b804a5f95cbd7e052c000080eb000080000000800000000000000000");
    const promise11 = transport.send(215, 0x20, 0x01, 0, buffer11);
    await device.curlScreenShot();
    device.curlButton("both", "Confirm chain"); //!!!!!!
    const response11 = await promise11;
    assert.equal(response11.toString("hex"), "9000");

    //SHOW DATA 01-hexstring, 02-validate length, 0000000000000000-min, 0800000000000000-max, 05-policy, Key = "?exString" 0900(48)6578537472696e67
    const buffer12 = getAPDUDataBuffer("0102000000000000000008000000000000000509ff6578537472696e67", "0011223344556677");
    const promise12 = transport.send(215, 0x20, 0x04, 0, buffer12);
    await assert.rejects(promise12, err(0x6e07));

    await device.makeStartingScreenshot();
}
//-------------------------------------------------------------------------------------
testStep(" - - -", "Key too long");
{
    //INIT chainId=b20901380af44ef59c5918439a1f9a41d83669020319a80574b804a5f95cbd7e
    const buffer11 = getAPDUDataBuffer("", "b20901380af44ef59c5918439a1f9a41d83669020319a80574b804a5f95cbd7e052c000080eb000080000000800000000000000000");
    const promise11 = transport.send(215, 0x20, 0x01, 0, buffer11);
    await device.curlScreenShot();
    device.curlButton("both", "Confirm chain"); //!!!!!!
    const response11 = await promise11;
    assert.equal(response11.toString("hex"), "9000");

    //SHOW DATA 01-hexstring, 02-validate length, 0000000000000000-min, 0800000000000000-max, 05-policy, Key = "01234567890123456789"
    const buffer12 = getAPDUDataBuffer("01020000000000000000080000000000000005143031323334353637383930313233343536373839", "0011223344556677");
    const promise12 = transport.send(215, 0x20, 0x04, 0, buffer12);
    await assert.rejects(promise12, err(0x6e07));

    await device.makeStartingScreenshot();
}
//-------------------------------------------------------------------------------------
testStep(" - - -", "String value contains non readable characters");
{
    //INIT chainId=b20901380af44ef59c5918439a1f9a41d83669020319a80574b804a5f95cbd7e
    const buffer11 = getAPDUDataBuffer("", "b20901380af44ef59c5918439a1f9a41d83669020319a80574b804a5f95cbd7e052c000080eb000080000000800000000000000000");
    const promise11 = transport.send(215, 0x20, 0x01, 0, buffer11);
    await device.curlScreenShot();
    device.curlButton("both", "Confirm chain"); //!!!!!!
    const response11 = await promise11;
    assert.equal(response11.toString("hex"), "9000");

    //SHOW DATA 02-string, 01-no validation, 0000000000000000-min, 0000000000000000-max, 05-policy, Key = "String" (06537472696e67)
    const buffer13 = getAPDUDataBuffer("0201000000000000000000000000000000000506537472696e67", "4eff636520616e64206c6f6e67206c6f6e67206c6f6e67206c6f6e6720737472696e67");
    const promise13 = transport.send(215, 0x20, 0x04, 0, buffer13);
    await assert.rejects(promise13, err(0x6e07));

    await device.makeStartingScreenshot();
}
//-------------------------------------------------------------------------------------
testStep(" - - -", "Name string has incorrect length");
{
    //INIT chainId=b20901380af44ef59c5918439a1f9a41d83669020319a80574b804a5f95cbd7e
    const buffer11 = getAPDUDataBuffer("", "b20901380af44ef59c5918439a1f9a41d83669020319a80574b804a5f95cbd7e052c000080eb000080000000800000000000000000");
    const promise11 = transport.send(215, 0x20, 0x01, 0, buffer11);
    await device.curlScreenShot();
    device.curlButton("both", "Confirm chain"); //!!!!!!
    const response11 = await promise11;
    assert.equal(response11.toString("hex"), "9000");

    //SHOW DATA 03-name, 01-no validation, 0000000000000000-min, 0000000000000000-max, 05-policy, Key = "NameString" (0a4e616d65537472696e67) Shows: "fio.token"
    const buffer14 = getAPDUDataBuffer("030100000000000000000000000000000000050a4e616d65537472696e67", "00980ad20ca85b");
    const promise14 = transport.send(215, 0x20, 0x04, 0, buffer14);
    await assert.rejects(promise14, err(0x6e07));

    await device.makeStartingScreenshot();
}
//-------------------------------------------------------------------------------------
testStep(" - - -", "Amount incorrect length");
{
    //INIT chainId=b20901380af44ef59c5918439a1f9a41d83669020319a80574b804a5f95cbd7e
    const buffer11 = getAPDUDataBuffer("", "b20901380af44ef59c5918439a1f9a41d83669020319a80574b804a5f95cbd7e052c000080eb000080000000800000000000000000");
    const promise11 = transport.send(215, 0x20, 0x01, 0, buffer11);
    await device.curlScreenShot();
    device.curlButton("both", "Confirm chain"); //!!!!!!
    const response11 = await promise11;
    assert.equal(response11.toString("hex"), "9000");

    //SHOW DATA 10-amount, 01-no validation, 0000000000000000-min, 0000000000000000-max, 05-policy, Key = "Amount" (06416d6f756e74)
    const buffer15 = getAPDUDataBuffer("1001000000000000000000000000000000000506416d6f756e74", "010000000000000000");
    const promise15 = transport.send(215, 0x20, 0x04, 0, buffer15);
    await assert.rejects(promise15, err(0x6e07));

    await device.makeStartingScreenshot();
}
//-------------------------------------------------------------------------------------
testStep(" - - -", "UInt64 incorrect length");
{
    //INIT chainId=b20901380af44ef59c5918439a1f9a41d83669020319a80574b804a5f95cbd7e
    const buffer11 = getAPDUDataBuffer("", "b20901380af44ef59c5918439a1f9a41d83669020319a80574b804a5f95cbd7e052c000080eb000080000000800000000000000000");
    const promise11 = transport.send(215, 0x20, 0x01, 0, buffer11);
    await device.curlScreenShot();
    device.curlButton("both", "Confirm chain"); //!!!!!!
    const response11 = await promise11;
    assert.equal(response11.toString("hex"), "9000");

    //SHOW DATA 14-uint64, 01-no validation, 0000000000000000-min, 0000000000000000-max, 05-policy, Key = "Number" (064e756d626572)
    const buffer16 = getAPDUDataBuffer("14010000000000000000000000000000000005064e756d626572", "02000000000000");
    const promise16 = transport.send(215, 0x20, 0x04, 0, buffer16);
    await assert.rejects(promise16, err(0x6e07));

    await device.makeStartingScreenshot();
}
//-------------------------------------------------------------------------------------
testStep(" - - -", "Policy show if not empty empty check");
{
    //INIT chainId=b20901380af44ef59c5918439a1f9a41d83669020319a80574b804a5f95cbd7e
    const buffer11 = getAPDUDataBuffer("", "b20901380af44ef59c5918439a1f9a41d83669020319a80574b804a5f95cbd7e052c000080eb000080000000800000000000000000");
    const promise11 = transport.send(215, 0x20, 0x01, 0, buffer11);
    await device.curlScreenShot();
    device.curlButton("both", "Confirm chain"); //!!!!!!
    const response11 = await promise11;
    assert.equal(response11.toString("hex"), "9000");

    //SHOW DATA 02-string, 01-no validation, 0000000000000000-min, 0000000000000000-max, 06-policy, Key = "String" (06537472696e67)
    const buffer16 = getAPDUDataBuffer("0201000000000000000000000000000000000606537472696e67", "");
    const promise16 = transport.send(215, 0x20, 0x04, 0, buffer16);
    const response16 = await promise16;
    assert.equal(response16.toString("hex"), "9000");

    //SHOW DATA 02-string, 01-no validation, 0000000000000000-min, 0000000000000000-max, 06-policy, Key = "String" (06537472696e67)
    const buffer17 = getAPDUDataBuffer("0201000000000000000000000000000000000606537472696e67", "53");
    const promise17 = transport.send(215, 0x20, 0x04, 0, buffer17);
    await device.curlScreenShot();
    device.curlButton("both", "Comfirm String");
    const response17 = await promise17;
    assert.equal(response17.toString("hex"), "9000");

    //SHOW DATA 02-string, 01-no validation, 0000000000000000-min, 0000000000000000-max, 06-policy, Key = "String" (06537472696e67)
    const buffer18 = getAPDUDataBuffer("0201000000000000000000000000000000000606537472696e67", "ff");
    const promise18 = transport.send(215, 0x20, 0x04, 0, buffer18);
    await assert.rejects(promise18, err(0x6e07));

    await device.makeStartingScreenshot();
}
//-------------------------------------------------------------------------------------


await transport.close();
testEnd(scriptName);
process.stdin.pause();