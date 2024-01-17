import { testStart, testStep, testEnd, getScriptName, getSpeculosDefaultConf, getAPDUDataBuffer, sleep } from "./speculos-common.js"
import { getTransport } from "./speculos-transport.js"
import { getButtonsAndSnapshots } from "./speculos-buttons-and-snapshots.js"
import { fileURLToPath } from 'url';
import assert from 'assert/strict';
import PrivateKey from '@fioprotocol/fiojs/dist/ecc/key_private.js';
import PublicKey from '@fioprotocol/fiojs/dist/ecc/key_public.js';
import { checkEncrypt } from "@fioprotocol/fiojs/dist/encryption-check.js"
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
testStep(" - - -", "Sign minimal devel DH tranaction");
{
    //INIT chainId=b20901380af44ef59c5918439a1f9a41d83669020319a80574b804a5f95cbd7e path=44'/235'/0'/0/0
    const buffer11 = getAPDUDataBuffer("", "b20901380af44ef59c5918439a1f9a41d83669020319a80574b804a5f95cbd7e052c000080eb000080000000800000000000000000");
    console.log(buffer11.toString("hex"))
    const promise11 = transport.send(215, 0x20, 0x01, 0, buffer11);
    await device.curlScreenShot();
    device.curlButton("both", "Confirm chain"); //!!!!!!
    const response11 = await promise11;
    assert.equal(response11.toString("hex"), "9000");

    const otherPublicKey = "0484e52dfea57b8f1787488a356374cd8e8515b8ad8db3dd4f9088d8e42ed2fb6d571e8894cccbdbf15e1bd84f8b4362f52d1b5b712b9775c0a51cdd5ee9a9e8ca";
    //START DH encryption //this is 9ubkey for path=44'/235'/0'/0/2000
    const buffer12 = getAPDUDataBuffer("", otherPublicKey);
    const promise12 = transport.send(215, 0x20, 0x08, 0, buffer12);
    await device.curlScreenShot();
    device.curlButton("both", "message");
    const response12 = await promise12;
    assert.equal(response12.slice(-2).toString("hex"), "9000");
    let dhEncodedMsg = response12.slice(0, -2).toString("hex");

    //Append "0102030405" to transaction
    const buffer13 = getAPDUDataBuffer("0102030405", "");
    const promise13 = transport.send(215, 0x20, 0x02, 0, buffer13);
    const response13 = await promise13;
    assert.equal(response13.slice(-2).toString("hex"), "9000");
    dhEncodedMsg += response13.slice(0, -2).toString("hex");

    //SHOW DATA 02-string, 01-no validation, 0000000000000000-min, 0000000000000000-max, 05-policy, Key = "String" (06537472696e67)
    const buffer14 = getAPDUDataBuffer("0201000000000000000000000000000000000506537472696e67", "4e69636520616e64206c6f6e67206c6f6e67206c6f6e67206c6f6e6720737472696e67");
    const promise14 = transport.send(215, 0x20, 0x04, 0, buffer14);
    await device.curlScreenShot();
    device.curlButton("both", "Confirm message"); //!!!!!!
    const response14 = await promise14;
    assert.equal(response14.slice(-2).toString("hex"), "9000");
    dhEncodedMsg += response14.slice(0, -2).toString("hex");

    //END DH ENCRYPTION
    const buffer15 = getAPDUDataBuffer("", "");
    const promise15 = transport.send(215, 0x20, 0x09, 0, buffer15);
    await device.curlScreenShot();
    device.curlButton("right", "Confirm create shared secret"); //!!!!!!
    const response15 = await promise15;
    assert.equal(response15.slice(-2).toString("hex"), "9000");
    dhEncodedMsg += response15.slice(0, -2).toString("hex");

    // Validate DH encoded secret
    const privateKey = PrivateKey(Buffer.from("4d597899db76e87933e7c6841c2d661810f070bad20487ef20eb84e182695a3a", "hex"))
    const sharedSecret = privateKey.getSharedSecret(PublicKey(Buffer.from(otherPublicKey, "hex")));
    const IV = Buffer.from(Buffer.from(dhEncodedMsg, "hex").toString(), "base64").slice(0, 16);
    const msg = Buffer.from("0102030405" + "4e69636520616e64206c6f6e67206c6f6e67206c6f6e67206c6f6e6720737472696e67", "hex");
    const encrypt = checkEncrypt(sharedSecret, Buffer.from(msg, "hex"), IV);
    assert.equal(encrypt.toString("base64"), Buffer.from(dhEncodedMsg, "hex").toString());
    
    // Finish 
    const buffer16 = getAPDUDataBuffer("", "");
    const promise16 = transport.send(215, 0x20, 0x10, 0, buffer16);
    await device.curlScreenShot();
    await device.curlButtonAndScreenshot("both", "Our Path");
    await device.curlButtonAndScreenshot("right", "Confirm sign with");
    const response16 = await promise16;

    //The signed message should contain chainId + dhEncodedMsg
    const msg1 = Buffer.from("b20901380af44ef59c5918439a1f9a41d83669020319a80574b804a5f95cbd7e"+dhEncodedMsg, "hex");
    const hash1 = crypto.createHash('sha256').update(msg1).digest('hex')
    const ledgerSignature1 = Signature.fromHex(response16.slice(0, 65));
    assert.equal(response16.slice(65,65+32).toString("hex"), hash1);
    assert.equal(response16.slice(65+32,65+32+4).toString("hex"), "9000");
    assert.equal(ledgerSignature1.verify(msg1, publicKey), true);
}
//-------------------------------------------------------------------------------------
testStep(" - - -", "Ending DH encoding without beggining it does not work");
{
    //INIT chainId=b20901380af44ef59c5918439a1f9a41d83669020319a80574b804a5f95cbd7e path=44'/235'/0'/0/0
    const buffer11 = getAPDUDataBuffer("", "b20901380af44ef59c5918439a1f9a41d83669020319a80574b804a5f95cbd7e052c000080eb000080000000800000000000000000");
    console.log(buffer11.toString("hex"))
    const promise11 = transport.send(215, 0x20, 0x01, 0, buffer11);
    await device.curlScreenShot();
    device.curlButton("both", "Confirm chain"); //!!!!!!
    const response11 = await promise11;
    assert.equal(response11.toString("hex"), "9000");

    //END DH ENCRYPTION
    const buffer15 = getAPDUDataBuffer("", "");
    const promise15 = transport.send(215, 0x20, 0x09, 0, buffer15);
    await assert.rejects(promise15, err(0x6e06));

    await device.makeStartingScreenshot();
}
//-------------------------------------------------------------------------------------
testStep(" - - -", "Nested DH encryption disallowed");
{
    //INIT chainId=b20901380af44ef59c5918439a1f9a41d83669020319a80574b804a5f95cbd7e path=44'/235'/0'/0/0
    const buffer11 = getAPDUDataBuffer("", "b20901380af44ef59c5918439a1f9a41d83669020319a80574b804a5f95cbd7e052c000080eb000080000000800000000000000000");
    console.log(buffer11.toString("hex"))
    const promise11 = transport.send(215, 0x20, 0x01, 0, buffer11);
    await device.curlScreenShot();
    device.curlButton("both", "Confirm chain"); //!!!!!!
    const response11 = await promise11;
    assert.equal(response11.toString("hex"), "9000");

    const otherPublicKey = "0484e52dfea57b8f1787488a356374cd8e8515b8ad8db3dd4f9088d8e42ed2fb6d571e8894cccbdbf15e1bd84f8b4362f52d1b5b712b9775c0a51cdd5ee9a9e8ca";
    //START DH encryption //this is 9ubkey for path=44'/235'/0'/0/2000
    const buffer12 = getAPDUDataBuffer("", otherPublicKey);
    const promise12 = transport.send(215, 0x20, 0x08, 0, buffer12);
    await device.curlScreenShot();
    device.curlButton("both", "message");
    const response12 = await promise12;
    assert.equal(response12.slice(-2).toString("hex"), "9000");

    //START DH encryption //this is 9ubkey for path=44'/235'/0'/0/2000
    const buffer13 = getAPDUDataBuffer("", otherPublicKey);
    const promise13 = transport.send(215, 0x20, 0x08, 0, buffer13);
    await assert.rejects(promise13, err(0x6e06));
}
//-------------------------------------------------------------------------------------
testStep(" - - -", "You can restart DH encryption. You cannot finish the transaction without finishind DH encoding");
{
    //INIT chainId=b20901380af44ef59c5918439a1f9a41d83669020319a80574b804a5f95cbd7e path=44'/235'/0'/0/0
    const buffer11 = getAPDUDataBuffer("", "b20901380af44ef59c5918439a1f9a41d83669020319a80574b804a5f95cbd7e052c000080eb000080000000800000000000000000");
    console.log(buffer11.toString("hex"))
    const promise11 = transport.send(215, 0x20, 0x01, 0, buffer11);
    await device.curlScreenShot();
    device.curlButton("both", "Confirm chain"); //!!!!!!
    const response11 = await promise11;
    assert.equal(response11.toString("hex"), "9000");

    const otherPublicKey = "0484e52dfea57b8f1787488a356374cd8e8515b8ad8db3dd4f9088d8e42ed2fb6d571e8894cccbdbf15e1bd84f8b4362f52d1b5b712b9775c0a51cdd5ee9a9e8ca";
    //START DH encryption //this is 9ubkey for path=44'/235'/0'/0/2000
    const buffer12 = getAPDUDataBuffer("", otherPublicKey);
    const promise12 = transport.send(215, 0x20, 0x08, 0, buffer12);
    await device.curlScreenShot();
    device.curlButton("both", "message");
    const response12 = await promise12;
    assert.equal(response12.slice(-2).toString("hex"), "9000");

    //END DH ENCRYPTION
    const buffer13 = getAPDUDataBuffer("", "");
    const promise13 = transport.send(215, 0x20, 0x09, 0, buffer13);
    await device.curlScreenShot();
    device.curlButton("right", "Confirm create shared secret"); //!!!!!!
    const response13 = await promise13;
    assert.equal(response13.slice(-2).toString("hex"), "9000");

    //START DH encryption //this is 9ubkey for path=44'/235'/0'/0/2000
    const buffer14 = getAPDUDataBuffer("", otherPublicKey);
    const promise14 = transport.send(215, 0x20, 0x08, 0, buffer14);
    await device.curlScreenShot();
    device.curlButton("both", "message");
    const response14 = await promise14;
    assert.equal(response14.slice(-2).toString("hex"), "9000");

    // Finish 
    const buffer16 = getAPDUDataBuffer("", "");
    const promise16 = transport.send(215, 0x20, 0x10, 0, buffer16);
    await assert.rejects(promise16, err(0x6e06));

    await device.makeStartingScreenshot();
}
//-------------------------------------------------------------------------------------
testStep(" - - -", "If you reject DH encryption it fails imediately, without exposing last blocks");
{
    //INIT chainId=b20901380af44ef59c5918439a1f9a41d83669020319a80574b804a5f95cbd7e path=44'/235'/0'/0/0
    const buffer11 = getAPDUDataBuffer("", "b20901380af44ef59c5918439a1f9a41d83669020319a80574b804a5f95cbd7e052c000080eb000080000000800000000000000000");
    console.log(buffer11.toString("hex"))
    const promise11 = transport.send(215, 0x20, 0x01, 0, buffer11);
    await device.curlScreenShot();
    device.curlButton("both", "Confirm chain"); //!!!!!!
    const response11 = await promise11;
    assert.equal(response11.toString("hex"), "9000");

    const otherPublicKey = "0484e52dfea57b8f1787488a356374cd8e8515b8ad8db3dd4f9088d8e42ed2fb6d571e8894cccbdbf15e1bd84f8b4362f52d1b5b712b9775c0a51cdd5ee9a9e8ca";
    //START DH encryption //this is 9ubkey for path=44'/235'/0'/0/2000
    const buffer12 = getAPDUDataBuffer("", otherPublicKey);
    const promise12 = transport.send(215, 0x20, 0x08, 0, buffer12);
    await device.curlScreenShot();
    device.curlButton("both", "message");
    const response12 = await promise12;
    assert.equal(response12.slice(-2).toString("hex"), "9000");

    //END DH ENCRYPTION
    const buffer13 = getAPDUDataBuffer("", "");
    const promise13 = transport.send(215, 0x20, 0x09, 0, buffer13);
    await device.curlScreenShot();
    device.curlButton("left", "Reject create shared secret"); //!!!!!!
    await assert.rejects(promise13, err(0x6e09));

    await device.makeStartingScreenshot();
}
//-------------------------------------------------------------------------------------
testStep(" - - -", "Modifying anything within DH block should lead to integrity check failure");
{
    //INIT chainId=b20901380af44ef59c5918439a1f9a41d83669020319a80574b804a5f95cbd7e path=44'/235'/0'/0/0
    const buffer11 = getAPDUDataBuffer("", "b20901380af44ef59c5918439a1f9a41d83669020319a80574b804a5f95cbd7e052c000080eb000080000000800000000000000000");
    console.log(buffer11.toString("hex"))
    const promise11 = transport.send(215, 0x20, 0x01, 0, buffer11);
    await device.curlScreenShot();
    device.curlButton("both", "Confirm chain"); //!!!!!!
    const response11 = await promise11;
    assert.equal(response11.toString("hex"), "9000");

    const otherPublicKey = "0484e52dfea57b8f1787488a356374cd8e8515b8ad8db3dd4f9088d8e42ed2fb6d571e8894cccbdbf15e1bd84f8b4362f52d1b5b712b9775c0a51cdd5ee9a9e8ca";
    //START DH encryption //this is 9ubkey for path=44'/235'/0'/0/2000
    const buffer12 = getAPDUDataBuffer("", otherPublicKey);
    const promise12 = transport.send(215, 0x20, 0x08, 0, buffer12);
    await device.curlScreenShot();
    device.curlButton("both", "message");
    const response12 = await promise12;
    assert.equal(response12.slice(-2).toString("hex"), "9000");
    let dhEncodedMsg = response12.slice(0, -2).toString("hex");

    //Append "0102030406" to transaction - this should be 0102030405
    const buffer13 = getAPDUDataBuffer("0102030406", "");
    const promise13 = transport.send(215, 0x20, 0x02, 0, buffer13);
    const response13 = await promise13;
    assert.equal(response13.slice(-2).toString("hex"), "9000");
    dhEncodedMsg += response13.slice(0, -2).toString("hex");

    //SHOW DATA 02-string, 01-no validation, 0000000000000000-min, 0000000000000000-max, 05-policy, Key = "String" (06537472696e67)
    const buffer14 = getAPDUDataBuffer("0201000000000000000000000000000000000506537472696e67", "4e69636520616e64206c6f6e67206c6f6e67206c6f6e67206c6f6e6720737472696e67");
    const promise14 = transport.send(215, 0x20, 0x04, 0, buffer14);
    await device.curlScreenShot();
    device.curlButton("both", "Confirm message"); //!!!!!!
    const response14 = await promise14;
    assert.equal(response14.slice(-2).toString("hex"), "9000");
    dhEncodedMsg += response14.slice(0, -2).toString("hex");

    //END DH ENCRYPTION
    const buffer15 = getAPDUDataBuffer("", "");
    const promise15 = transport.send(215, 0x20, 0x09, 0, buffer15);
    await assert.rejects(promise15, err(0x6e08));

    await device.makeStartingScreenshot();
}
//-------------------------------------------------------------------------------------

await transport.close();
testEnd(scriptName);
process.stdin.pause();