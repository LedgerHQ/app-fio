import { testStart, testStep, testEnd, getScriptName, getSpeculosDefaultConf } from "./speculos-common.js"
import { getTransport } from "./speculos-transport.js"
import { getButtonsAndSnapshots } from "./speculos-buttons-and-snapshots.js"
import { Fio, DeviceStatusError, InvalidData, HARDENED } from "ledgerjs-hw-app-fio"
import { fileURLToPath } from 'url';
import { Ecc } from '@fioprotocol/fiojs'
import assert from 'assert/strict'

const scriptName = getScriptName(fileURLToPath(import.meta.url));
testStart(scriptName);

const speculosConf = getSpeculosDefaultConf();
const transport = await getTransport(speculosConf);
const app = new Fio(transport);
const device = getButtonsAndSnapshots(scriptName, speculosConf);

await device.makeStartingScreenshot();

const path = [44 + HARDENED, 235 + HARDENED, 0 + HARDENED, 0, 0]
const pubKey = "04a9a222bc3b1a5a58ada17d10069b3961ebd0f917d4b2106031a061915ca9cc24a06941e0a4c0d5e266850ff980ad349ab8b027c93bf4aead1984168ad43e30ab"

testStep(" - - -", "await app.getPublicKey() path:"+path+" do not show");
const getPubkeyPromise = app.getPublicKey({path: path, show_or_not: false});
const getPubkeyResponse = await getPubkeyPromise;
assert.equal(getPubkeyResponse.publicKeyHex, pubKey)
assert.equal(Ecc.PublicKey(getPubkeyResponse.publicKeyWIF).toUncompressed().toBuffer().toString('hex'), pubKey)

testStep(" - - -", "await app.getPublicKey() path:"+path+" show");
const getPubkeyPromise2 = app.getPublicKey({path: path, show_or_not: true});
await device.review([2,], "Review pubkey");
const getPubkeyResponse2 = await getPubkeyPromise2;
assert.equal(getPubkeyResponse2.publicKeyHex, pubKey)
assert.equal(Ecc.PublicKey(getPubkeyResponse2.publicKeyWIF).toUncompressed().toBuffer().toString('hex'), pubKey)

{
    testStep(" - - -", "await app.getPublicKey() show reject");
    const getPubkeyPromise2 = app.getPublicKey({path: path, show_or_not: true});
    await device.reviewReject([2,], "Review pubkey");
    await assert.rejects(getPubkeyPromise2, DeviceStatusError, "Action rejected by user");    
}

const path2 = [44 + HARDENED, 235 + HARDENED, 0 + HARDENED, 0, 2000]
const pubKey2 = "0484e52dfea57b8f1787488a356374cd8e8515b8ad8db3dd4f9088d8e42ed2fb6d571e8894cccbdbf15e1bd84f8b4362f52d1b5b712b9775c0a51cdd5ee9a9e8ca"

testStep(" - - -", "await app.getPublicKey() path:"+path2+" do not show");
const getPubkeyPromise3 = app.getPublicKey({path: path2, show_or_not: false});
await device.review([1, 1, 2,], "Review pubkey");
const getPubkeyResponse3 = await getPubkeyPromise3;
assert.equal(getPubkeyResponse3.publicKeyHex, pubKey2)
assert.equal(Ecc.PublicKey(getPubkeyResponse3.publicKeyWIF).toUncompressed().toBuffer().toString('hex'), pubKey2)

testStep(" - - -", "await app.getPublicKey() path:"+path2+" show");
const getPubkeyPromise4 = app.getPublicKey({path: path2, show_or_not: true});
await device.review([1, 1, 2,], "Review pubkey");
const getPubkeyResponse4 = await getPubkeyPromise4;
assert.equal(getPubkeyResponse4.publicKeyHex, pubKey2)
assert.equal(Ecc.PublicKey(getPubkeyResponse4.publicKeyWIF).toUncompressed().toBuffer().toString('hex'), pubKey2)


testStep(" - - -", "Should reject invalid paths.");

testStep(" - - -", "path shorter than 5 indexes");
const promise1 = app.getPublicKey({path: [44 + HARDENED, 235 + HARDENED, 0 + HARDENED, 0], show_or_not: false});
await assert.rejects(promise1, DeviceStatusError, "Action rejected by Ledger's security policy");
    
testStep(" - - -", "path contains non-zero address");
const promise2 = app.getPublicKey({path: [44 + HARDENED, 235 + HARDENED, 1 + HARDENED, 0, 0], show_or_not: false})
await assert.rejects(promise2, DeviceStatusError, "Action rejected by Ledger's security policy");

testStep(" - - -", "path contains non-hardened address");
const promise3 = app.getPublicKey({path: [44 + HARDENED, 235 + HARDENED, 0 , 0, 0], show_or_not: false})
await assert.rejects(promise3, DeviceStatusError, "Action rejected by Ledger's security policy");

testStep(" - - -", "path contains non-zero chain");
const promise4 = app.getPublicKey({path: [44 + HARDENED, 235 + HARDENED, 0 + HARDENED, 1, 0], show_or_not: false})
await assert.rejects(promise4, DeviceStatusError, "Action rejected by Ledger's security policy");

testStep(" - - -", "path too long");
const promise5 = app.getPublicKey({path: [44 + HARDENED, 235 + HARDENED, 0 + HARDENED, 0, 0, 0], show_or_not: false})
await assert.rejects(promise5, InvalidData, "invalid path"); //js parser does not allow this

testStep(" - - -", "path too long via direct APDU send.");
//we circumnavigate JS parser to validate that ledger itself handles this case correctly
const promise6 = app._send({ins: 0x10, 
    p1:0x02, 
    p2:0x00, 
    data:Buffer.from("068000002c800000eb80000000000000000000000000000000)", "hex"), 
    expectedResponseLength: 0
});
await assert.rejects(promise6, DeviceStatusError, "Action rejected by Ledger's security policy");

await transport.close()
testEnd(scriptName);
process.stdin.pause()