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
testStep(" - - -", "Sign minimal fake devel transaction cotaining COUNTED_SECTION instructions");
{
    //INIT chainId=b20901380af44ef59c5918439a1f9a41d83669020319a80574b804a5f95cbd7e path=44'/235'/0'/0/0
    const buffer11 = getAPDUDataBuffer("", "b20901380af44ef59c5918439a1f9a41d83669020319a80574b804a5f95cbd7e052c000080eb000080000000800000000000000000");
    const promise11 = transport.send(215, 0x20, 0x01, 0, buffer11);
    await device.curlScreenShot();
    device.curlButton("both", "Confirm chain"); //!!!!!!
    const response11 = await promise11;
    assert.equal(response11.toString("hex"), "9000");

    //START_COUNTED_SECTION 17-varuint32, 01-no validation, 0000000000000000-min, 0800000000000000-max
    const buffer12 = getAPDUDataBuffer("170100000000000000000000000000000000", "8001"); // value - 128
    const promise12 = transport.send(215, 0x20, 0x05, 0, buffer12);
    const response12 = await promise12;
    assert.equal(response12.toString("hex"), "9000");

    //Append to transaction (32 bytes)
    const buffer13 = getAPDUDataBuffer("0000000000000000000000000000000000000000000000000000000000000000", "");
    const promise13 = transport.send(215, 0x20, 0x02, 0, buffer13);
    const response13 = await promise13;
    assert.equal(response13.toString("hex"), "9000");

    //START_COUNTED_SECTION 17-varuint32, 01-no validation, 0000000000000000-min, 0800000000000000-max
    const buffer14 = getAPDUDataBuffer("170100000000000000000000000000000000", "40"); // value - 64
    const promise14 = transport.send(215, 0x20, 0x05, 0, buffer14);
    const response14 = await promise14;
    assert.equal(response14.toString("hex"), "9000");

    //START_COUNTED_SECTION 17-varuint32, 01-no validation, 0000000000000000-min, 0800000000000000-max
    const buffer15 = getAPDUDataBuffer("170100000000000000000000000000000000", "20"); // value - 32
    const promise15 = transport.send(215, 0x20, 0x05, 0, buffer15);
    const response15 = await promise15;
    assert.equal(response15.toString("hex"), "9000");

    //Append  to transaction (32 bytes)
    const buffer16 = getAPDUDataBuffer("0000000000000000000000000000000000000000000000000000000000000000", "");
    const promise16 = transport.send(215, 0x20, 0x02, 0, buffer16);
    const response16 = await promise16;
    assert.equal(response16.toString("hex"), "9000");

    //END_COUNTED_SECTION
    const buffer17 = getAPDUDataBuffer("", "");
    const promise17 = transport.send(215, 0x20, 0x06, 0, buffer17);
    const response17 = await promise17;
    assert.equal(response17.toString("hex"), "9000");

    //Append to transaction (31 bytes)
    const buffer18 = getAPDUDataBuffer("00000000000000000000000000000000000000000000000000000000000000", "");
    const promise18 = transport.send(215, 0x20, 0x02, 0, buffer18);
    const response18 = await promise18;
    assert.equal(response18.toString("hex"), "9000");

    //END_COUNTED_SECTION
    const buffer19 = getAPDUDataBuffer("", ""); 
    const promise19 = transport.send(215, 0x20, 0x06, 0, buffer19);
    const response19 = await promise19;
    assert.equal(response19.toString("hex"), "9000");

    //Append to transaction (31 bytes)
    const buffer20 = getAPDUDataBuffer("00000000000000000000000000000000000000000000000000000000000000", "");
    const promise20 = transport.send(215, 0x20, 0x02, 0, buffer20);
    const response20 = await promise20;
    assert.equal(response20.toString("hex"), "9000");
    
    //END_COUNTED_SECTION
    const buffer21 = getAPDUDataBuffer("", ""); 
    const promise21 = transport.send(215, 0x20, 0x06, 0, buffer21);
    const response21 = await promise21;
    assert.equal(response21.toString("hex"), "9000");

    //Finish 
    const buffer99 = getAPDUDataBuffer("", "");
    const promise99 = transport.send(215, 0x20, 0x10, 0, buffer99);
    await device.curlScreenShot();
    await device.curlButtonAndScreenshot("both", "Confirm sign with");
    await device.curlButtonAndScreenshot("right", "Confirm sign with");
    const response99 = await promise99;

    //The signed message should contain chainId + 0102030405
    const msg1 = Buffer.from("b20901380af44ef59c5918439a1f9a41d83669020319a80574b804a5f95cbd7e"
                           + "8001" 
                           + "0000000000000000000000000000000000000000000000000000000000000000"
                           + "40"
                           + "20"
                           + "0000000000000000000000000000000000000000000000000000000000000000"
                           + "00000000000000000000000000000000000000000000000000000000000000"
                           + "00000000000000000000000000000000000000000000000000000000000000"
            , "hex");
    const hash1 = crypto.createHash('sha256').update(msg1).digest('hex')
    const ledgerSignature1 = Signature.fromHex(response99.slice(0, 65));
    assert.equal(response99.slice(65,65+32).toString("hex"), hash1);
    assert.equal(response99.slice(65+32,65+32+4).toString("hex"), "9000");
    assert.equal(ledgerSignature1.verify(msg1, publicKey), true);
}
//-------------------------------------------------------------------------------------
testStep(" - - -", "Validation failure");
{
    //INIT chainId=b20901380af44ef59c5918439a1f9a41d83669020319a80574b804a5f95cbd7e
    const buffer11 = getAPDUDataBuffer("", "b20901380af44ef59c5918439a1f9a41d83669020319a80574b804a5f95cbd7e052c000080eb000080000000800000000000000000");
    const promise11 = transport.send(215, 0x20, 0x01, 0, buffer11);
    await device.curlScreenShot();
    device.curlButton("both", "Confirm chain"); //!!!!!!
    const response11 = await promise11;
    assert.equal(response11.toString("hex"), "9000");

    //START_COUNTED_SECTION 17-varuint32, 03-number validation, 0000000000000000-min, 0800000000000000-max
    const buffer12 = getAPDUDataBuffer("170300000000000000007f00000000000000", "8001"); // value - 128, 127 is max
    const promise12 = transport.send(215, 0x20, 0x05, 0, buffer12);
    await assert.rejects(promise12, err(0x6e07));

    await device.makeStartingScreenshot();
}
//-------------------------------------------------------------------------------------
testStep(" - - -", "VarInt32 incorrect format");
{
    //INIT chainId=b20901380af44ef59c5918439a1f9a41d83669020319a80574b804a5f95cbd7e
    const buffer11 = getAPDUDataBuffer("", "b20901380af44ef59c5918439a1f9a41d83669020319a80574b804a5f95cbd7e052c000080eb000080000000800000000000000000");
    const promise11 = transport.send(215, 0x20, 0x01, 0, buffer11);
    await device.curlScreenShot();
    device.curlButton("both", "Confirm chain"); //!!!!!!
    const response11 = await promise11;
    assert.equal(response11.toString("hex"), "9000");

    //START_COUNTED_SECTION 17-varuint32, 01-no validation, 0000000000000000-min, 0000000000000000-max
    const buffer12 = getAPDUDataBuffer("170100000000000000000000000000000000", "8080"); 
    const promise12 = transport.send(215, 0x20, 0x05, 0, buffer12);
    await assert.rejects(promise12, err(0x6e07));

    await device.makeStartingScreenshot();
}
//-------------------------------------------------------------------------------------
testStep(" - - -", "VarInt32 too many bytes");
{
    //INIT chainId=b20901380af44ef59c5918439a1f9a41d83669020319a80574b804a5f95cbd7e
    const buffer11 = getAPDUDataBuffer("", "b20901380af44ef59c5918439a1f9a41d83669020319a80574b804a5f95cbd7e052c000080eb000080000000800000000000000000");
    const promise11 = transport.send(215, 0x20, 0x01, 0, buffer11);
    await device.curlScreenShot();
    device.curlButton("both", "Confirm chain"); //!!!!!!
    const response11 = await promise11;
    assert.equal(response11.toString("hex"), "9000");

    //START_COUNTED_SECTION 17-varuint32, 01-no validation, 0000000000000000-min, 0000000000000000-max
    const buffer12 = getAPDUDataBuffer("170100000000000000000000000000000000", "808080808080808001"); //more than 9 bytes
    const promise12 = transport.send(215, 0x20, 0x05, 0, buffer12);
    await assert.rejects(promise12, err(0x6e07));

    await device.makeStartingScreenshot();
}
//-------------------------------------------------------------------------------------
testStep(" - - -", "Too big for UInt32");
{
    //INIT chainId=b20901380af44ef59c5918439a1f9a41d83669020319a80574b804a5f95cbd7e
    const buffer11 = getAPDUDataBuffer("", "b20901380af44ef59c5918439a1f9a41d83669020319a80574b804a5f95cbd7e052c000080eb000080000000800000000000000000");
    const promise11 = transport.send(215, 0x20, 0x01, 0, buffer11);
    await device.curlScreenShot();
    device.curlButton("both", "Confirm chain"); //!!!!!!
    const response11 = await promise11;
    assert.equal(response11.toString("hex"), "9000");

    //START_COUNTED_SECTION 17-varuint32, 01-no validation, 0000000000000000-min, 0000000000000000-max
    const buffer12 = getAPDUDataBuffer("170100000000000000000000000000000000", "8080808080808001");
    const promise12 = transport.send(215, 0x20, 0x05, 0, buffer12);
    await assert.rejects(promise12, err(0x6e07));

    await device.makeStartingScreenshot();
}
//-------------------------------------------------------------------------------------
testStep(" - - -", "too much nesting");
{
    //INIT chainId=b20901380af44ef59c5918439a1f9a41d83669020319a80574b804a5f95cbd7e
    const buffer11 = getAPDUDataBuffer("", "b20901380af44ef59c5918439a1f9a41d83669020319a80574b804a5f95cbd7e052c000080eb000080000000800000000000000000");
    const promise11 = transport.send(215, 0x20, 0x01, 0, buffer11);
    await device.curlScreenShot();
    device.curlButton("both", "Confirm chain"); //!!!!!!
    const response11 = await promise11;
    assert.equal(response11.toString("hex"), "9000");

    {
        //START_COUNTED_SECTION 17-varuint32, 01-no validation, 0000000000000000-min, 0800000000000000-max
        const buffer12 = getAPDUDataBuffer("170100000000000000000000000000000000", "8001"); // value - 128
        const promise12 = transport.send(215, 0x20, 0x05, 0, buffer12);
        const response12 = await promise12;
        assert.equal(response12.toString("hex"), "9000");
    }

    {
        //START_COUNTED_SECTION 17-varuint32, 01-no validation, 0000000000000000-min, 0800000000000000-max
        const buffer12 = getAPDUDataBuffer("170100000000000000000000000000000000", "8001"); // value - 128
        const promise12 = transport.send(215, 0x20, 0x05, 0, buffer12);
        const response12 = await promise12;
        assert.equal(response12.toString("hex"), "9000");
    }

    {
        //START_COUNTED_SECTION 17-varuint32, 01-no validation, 0000000000000000-min, 0800000000000000-max
        const buffer12 = getAPDUDataBuffer("170100000000000000000000000000000000", "8001"); // value - 128
        const promise12 = transport.send(215, 0x20, 0x05, 0, buffer12);
        const response12 = await promise12;
        assert.equal(response12.toString("hex"), "9000");
    }

    {
        //START_COUNTED_SECTION 17-varuint32, 01-no validation, 0000000000000000-min, 0800000000000000-max
        const buffer12 = getAPDUDataBuffer("170100000000000000000000000000000000", "8001"); // value - 128
        const promise12 = transport.send(215, 0x20, 0x05, 0, buffer12);
        const response12 = await promise12;
        assert.equal(response12.toString("hex"), "9000");
    }

    {
        //START_COUNTED_SECTION 17-varuint32, 01-no validation, 0000000000000000-min, 0800000000000000-max
        const buffer12 = getAPDUDataBuffer("170100000000000000000000000000000000", "8001"); // value - 128
        const promise12 = transport.send(215, 0x20, 0x05, 0, buffer12);
        const response12 = await promise12;
        assert.equal(response12.toString("hex"), "9000");
    }

    {
        //START_COUNTED_SECTION 17-varuint32, 01-no validation, 0000000000000000-min, 0800000000000000-max
        const buffer12 = getAPDUDataBuffer("170100000000000000000000000000000000", "8001"); // value - 128
        const promise12 = transport.send(215, 0x20, 0x05, 0, buffer12);
        await assert.rejects(promise12, err(0x6e07));
        await device.makeStartingScreenshot();
    }
}
//-------------------------------------------------------------------------------------
testStep(" - - -", "Unexpected end counted section");
{
    //INIT chainId=b20901380af44ef59c5918439a1f9a41d83669020319a80574b804a5f95cbd7e
    const buffer11 = getAPDUDataBuffer("", "b20901380af44ef59c5918439a1f9a41d83669020319a80574b804a5f95cbd7e052c000080eb000080000000800000000000000000");
    const promise11 = transport.send(215, 0x20, 0x01, 0, buffer11);
    await device.curlScreenShot();
    device.curlButton("both", "Confirm chain"); //!!!!!!
    const response11 = await promise11;
    assert.equal(response11.toString("hex"), "9000");

    //END_COUNTED_SECTION
    const buffer12 = getAPDUDataBuffer("", ""); 
    const promise12 = transport.send(215, 0x20, 0x06, 0, buffer12);
    await assert.rejects(promise12, err(0x6e07));

    await device.makeStartingScreenshot();
}

//-------------------------------------------------------------------------------------
testStep(" - - -", "Length mismatch");
{
    //INIT chainId=b20901380af44ef59c5918439a1f9a41d83669020319a80574b804a5f95cbd7e
    const buffer11 = getAPDUDataBuffer("", "b20901380af44ef59c5918439a1f9a41d83669020319a80574b804a5f95cbd7e052c000080eb000080000000800000000000000000");
    const promise11 = transport.send(215, 0x20, 0x01, 0, buffer11);
    await device.curlScreenShot();
    device.curlButton("both", "Confirm chain"); //!!!!!!
    const response11 = await promise11;
    assert.equal(response11.toString("hex"), "9000");

    //START_COUNTED_SECTION 17-varuint32, 01-no validation, 0000000000000000-min, 0800000000000000-max
    const buffer12 = getAPDUDataBuffer("170100000000000000000000000000000000", "8001"); // value - 128
    const promise12 = transport.send(215, 0x20, 0x05, 0, buffer12);
    const response12 = await promise12;
    assert.equal(response12.toString("hex"), "9000");

    //END_COUNTED_SECTION
    const buffer13 = getAPDUDataBuffer("", ""); 
    const promise13 = transport.send(215, 0x20, 0x06, 0, buffer13);
    await assert.rejects(promise13, err(0x6e07));

    await device.makeStartingScreenshot();
}

await transport.close();
testEnd(scriptName);
process.stdin.pause();

