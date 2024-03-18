import { testStart, testStep, testEnd, getScriptName, getSpeculosDefaultConf, getAPDUDataBuffer, sleep } from "./speculos-common.js"
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
testStep(" - - -", "Sign minimal fake devel transaction containing INIT, APPEND_CONST_DATA, SHOW_MESSAGE, FINISH instructions - testnet");
{
    //INIT chainId=b20901380af44ef59c5918439a1f9a41d83669020319a80574b804a5f95cbd7e path=44'/235'/0'/0/0
    const buffer11 = getAPDUDataBuffer("", "b20901380af44ef59c5918439a1f9a41d83669020319a80574b804a5f95cbd7e052c000080eb000080000000800000000000000000");
    console.log(buffer11.toString("hex"))
    const promise11 = transport.send(215, 0x20, 0x01, 0, buffer11);
    await device.curlScreenShot();
    device.curlButton("both", "Confirm chain"); //!!!!!!
    const response11 = await promise11;
    assert.equal(response11.toString("hex"), "9000");

    //Append "0102030405" to transaction
    const buffer12 = getAPDUDataBuffer("0102030405", "");
    const promise12 = transport.send(215, 0x20, 0x02, 0, buffer12);
    const response12 = await promise12;
    assert.equal(response12.toString("hex"), "9000");

    //Show "Test Key" "Test Value" to transaction hex: 0854657374204b6579, 0a546573742056616c7565 (total length 0x14)
    const buffer13 = getAPDUDataBuffer("0854657374204b65790a546573742056616c7565", "");
    const promise13 = transport.send(215, 0x20, 0x03, 0, buffer13);
    await device.curlScreenShot();
    device.curlButton("both", "Confirm message"); //!!!!!!
    const response13 = await promise13;
    assert.equal(response13.toString("hex"), "9000");

    //Finish 
    const buffer14 = getAPDUDataBuffer("", "");
    const promise14 = transport.send(215, 0x20, 0x10, 0, buffer14);
    await device.curlScreenShot();
    await device.curlButtonAndScreenshot("both", "Confirm sign with");
    await device.curlButtonAndScreenshot("right", "Confirm sign with");
    const response14 = await promise14;

    //The signed message should contain chainId + 0102030405
    const msg1 = Buffer.from("b20901380af44ef59c5918439a1f9a41d83669020319a80574b804a5f95cbd7e"+"0102030405", "hex");
    const hash1 = crypto.createHash('sha256').update(msg1).digest('hex')
    const ledgerSignature1 = Signature.fromHex(response14.slice(0, 65));
    assert.equal(response14.slice(65,65+32).toString("hex"), hash1);
    assert.equal(response14.slice(65+32,65+32+4).toString("hex"), "9000");
    assert.equal(ledgerSignature1.verify(msg1, publicKey), true);
}
//-------------------------------------------------------------------------------------
testStep(" - - -", "Sign minimal fake devel transaction containing INIT, APPEND_CONST_DATA, SHOW_MESSAGE, FINISH instructions - mainnet");
{
    //INIT chainId=21dcae42c0182200e93f954a074011f9048a7624c6fe81d3c9541a614a88bd1c 
    const buffer11 = getAPDUDataBuffer("", "21dcae42c0182200e93f954a074011f9048a7624c6fe81d3c9541a614a88bd1c052c000080eb000080000000800000000000000000");
    const promise11 = transport.send(215, 0x20, 0x01, 0, buffer11);
    await device.curlScreenShot();
    device.curlButton("both", "Confirm chain"); //!!!!!!
    const response11 = await promise11;
    assert.equal(response11.toString("hex"), "9000");

    //Append "0102030405" to transaction
    const buffer12 = getAPDUDataBuffer("0102030405", "");
    const promise12 = transport.send(215, 0x20, 0x02, 0, buffer12);
    const response12 = await promise12;
    assert.equal(response12.toString("hex"), "9000");

    //Show "Test Key" "Test Value" to transaction hex: 0854657374204b6579, 0a546573742056616c7565 (total length 0x14)
    const buffer13 = getAPDUDataBuffer("0854657374204b65790a546573742056616c7565", "");
    const promise13 = transport.send(215, 0x20, 0x03, 0, buffer13);
    await device.curlScreenShot();
    device.curlButton("both", "Confirm message"); //!!!!!!
    const response13 = await promise13;
    assert.equal(response13.toString("hex"), "9000");

    //Finish 
    const buffer14 = getAPDUDataBuffer("", "");
    const promise14 = transport.send(215, 0x20, 0x10, 0, buffer14);
    await device.curlScreenShot();
    await device.curlButtonAndScreenshot("both", "Confirm sign with");
    await device.curlButtonAndScreenshot("right", "Confirm sign with");
    const response14 = await promise14;

    //The signed message should contain chainId + 0102030405
    const msg1 = Buffer.from("21dcae42c0182200e93f954a074011f9048a7624c6fe81d3c9541a614a88bd1c0102030405", "hex");
    const hash1 = crypto.createHash('sha256').update(msg1).digest('hex')
    const ledgerSignature1 = Signature.fromHex(response14.slice(0, 65));
    assert.equal(response14.slice(65,65+32).toString("hex"), hash1);
    assert.equal(response14.slice(65+32,65+32+4).toString("hex"), "9000");
    assert.equal(ledgerSignature1.verify(msg1, publicKey), true);
}
//-------------------------------------------------------------------------------------
testStep(" - - -", "One byte constant data difference should cause integrity validation error (Test Value->Uest Value)");
{
    //INIT chainId=b20901380af44ef59c5918439a1f9a41d83669020319a80574b804a5f95cbd7e
    const buffer11 = getAPDUDataBuffer("", "b20901380af44ef59c5918439a1f9a41d83669020319a80574b804a5f95cbd7e052c000080eb000080000000800000000000000000");
    const promise11 = transport.send(215, 0x20, 0x01, 0, buffer11);
    await device.curlScreenShot();
    device.curlButton("both", "Confirm chain"); //!!!!!!
    const response11 = await promise11;
    assert.equal(response11.toString("hex"), "9000");

    //Append "0102030405" to transaction
    const buffer12 = getAPDUDataBuffer("0102030405", "");
    const promise12 = transport.send(215, 0x20, 0x02, 0, buffer12);
    const response12 = await promise12;
    assert.equal(response12.toString("hex"), "9000");

    //Show "Test Key" "Test Walue" to transaction hex: 0854657374204b6579, 0a55(54)6573742056616c7565 (total length 0x14)
    const buffer13 = getAPDUDataBuffer("0854657374204b65790a556573742056616c7565", "");
    const promise13 = transport.send(215, 0x20, 0x03, 0, buffer13);
    await device.curlScreenShot();
    device.curlButton("both", "Confirm message"); //!!!!!!
    const response13 = await promise13;
    assert.equal(response13.toString("hex"), "9000");

    //Finish path=44'/235'/0'/0/0
    const buffer14 = getAPDUDataBuffer("", "");
    const promise14 = transport.send(215, 0x20, 0x10, 0, buffer14);
    await assert.rejects(promise14, err(0x6e08));

    await device.makeStartingScreenshot();
} 
//-------------------------------------------------------------------------------------
testStep(" - - -", "Incorrect chain should result in immediate failure");
{
    //INIT chainId=b20901380af44ef59c5918439a1f9a41d83669020319a80574b804a5f95cbd7f incorrect chain - last bit
    const buffer11 = getAPDUDataBuffer("", "b20901380af44ef59c5918439a1f9a41d83669020319a80574b804a5f95cbd7f052c000080eb000080000000800000000000000000");
    const promise11 = transport.send(215, 0x20, 0x01, 0, buffer11);
    await assert.rejects(promise11, err(0x6e07));
}
//-------------------------------------------------------------------------------------
testStep(" - - -", "Incorrect lengths should lead to failure");
{
    //INIT chainId=21dcae42c0182200e93f954a074011f9048a7624c6fe81d3c9541a614a88bd1c
    const buffer11 = getAPDUDataBuffer("", "21dcae42c0182200e93f954a074011f9048a7624c6fe81d3c9541a614a88bd1c052c000080eb000080000000800000000000000000");
    const promise11 = transport.send(215, 0x20, 0x01, 0, buffer11);
    await device.curlScreenShot();
    device.curlButton("both", "Confirm chain"); //!!!!!!
    const response11 = await promise11;
    assert.equal(response11.toString("hex"), "9000");

    //Append "0102030405(06)" to transaction
    const buffer12 = Buffer.from("0501010203040506", "hex");
    const promise12 = transport.send(215, 0x20, 0x02, 0, buffer12);
    await assert.rejects(promise12, err(0x6e07));

    await device.makeStartingScreenshot();
}
//-------------------------------------------------------------------------------------
testStep(" - - -", "Non ASCII character in message");
{
    //INIT chainId=b20901380af44ef59c5918439a1f9a41d83669020319a80574b804a5f95cbd7e
    const buffer11 = getAPDUDataBuffer("", "b20901380af44ef59c5918439a1f9a41d83669020319a80574b804a5f95cbd7e052c000080eb000080000000800000000000000000");
    const promise11 = transport.send(215, 0x20, 0x01, 0, buffer11);
    await device.curlScreenShot();
    device.curlButton("both", "Confirm chain"); //!!!!!!
    const response11 = await promise11;
    assert.equal(response11.toString("hex"), "9000");

    //Show "Test Key" "Test Val_e" to transaction hex: 0854657374204b6579, 0a546573742056616c(00)65
    const buffer13 = getAPDUDataBuffer("0854657374204b65790a546573742056616c0065", "");
    const promise13 = transport.send(215, 0x20, 0x03, 0, buffer13);
    await assert.rejects(promise13, err(0x6e07));

    await device.makeStartingScreenshot();
} 
//-------------------------------------------------------------------------------------
testStep(" - - -", "incorrect path should result in failure");
{
    //INIT chainId=21dcae42c0182200e93f954a074011f9048a7624c6fe81d3c9541a614a88bd1c
    const buffer11 = getAPDUDataBuffer("", "21dcae42c0182200e93f954a074011f9048a7624c6fe81d3c9541a614a88bd1c058000002c800000ec800000000000000000000000");
    const promise11 = transport.send(215, 0x20, 0x01, 0, buffer11);
    await assert.rejects(promise11, err(0x6e10));
}
//-------------------------------------------------------------------------------------


await transport.close();
testEnd(scriptName);
process.stdin.pause();