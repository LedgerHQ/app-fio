import { testStart, testStep, testEnd, getScriptName, getSpeculosDefaultConf } from "./speculos-common.js"
import { getTransport } from "./speculos-transport.js"
import { getButtonsAndSnapshots } from "./speculos-buttons-and-snapshots.js"
import { Fio, DeviceStatusError, HARDENED } from "ledgerjs-hw-app-fio"
import { fileURLToPath } from 'url';
import { Ecc } from '@fioprotocol/fiojs'
import assert from 'assert/strict'
import { createSharedCipher } from "@fioprotocol/fiojs/dist/encryption-fio.js";

const PrivateKey = Ecc.PrivateKey;

const scriptName = getScriptName(fileURLToPath(import.meta.url));
testStart(scriptName);

const speculosConf = getSpeculosDefaultConf();
const transport = await getTransport(speculosConf);
const app = new Fio(transport);
const device = getButtonsAndSnapshots(scriptName, speculosConf);

await device.makeStartingScreenshot();


const content1 = {
    payee_public_address: "Payee public address",
    amount: "Amount 100",
    chain_code: "BTC1",
    token_code: "BTC2",
    memo: "My memo",
    hash: undefined,
    offline_url: undefined,
}

const content2 = {
    payee_public_address: "Payee public address",
    amount: "Amount 100",
    chain_code: "BTC1",
    token_code: "BTC2",
    memo: undefined,
    hash: "My hash",
    offline_url: "Offline URL",
}

const content3 = {
    payee_public_address: "Payee public address",
    payer_public_address: "Payer public address",
    amount: "Amount 100",
    chain_code: "BTC1",
    token_code: "BTC2",
    status: "Status",
    obt_id: "Obt ID",
    memo: "My memo",
    hash: undefined,
    offline_url: undefined,
}

const content4 = {
    payee_public_address: "Payee public address is very long, long, long",
    payer_public_address: "Payer public address is very long, long, long",
    amount: "Amount 100",
    chain_code: "BTC1",
    token_code: "BTC2",
    status: "Status",
    obt_id: "Obt ID",
    memo: undefined,
    hash: "My hash is quite long too, too, too",
    offline_url: "Offline URL is quite long too, too",
}

const content5 = {
    payee_public_address: "Payee public address",
    amount: "Amount 100",
    chain_code: "BTC1",
    token_code: "BTC2",
    memo: "My memo",
    hash: "My hash",
    offline_url: "Offline URL",
}

const path = [44 + HARDENED, 235 + HARDENED, 0 + HARDENED, 0, 0]
const privateKeyDHex = "4d597899db76e87933e7c6841c2d661810f070bad20487ef20eb84e182695a3a" 
const privateKey = PrivateKey(Buffer.from(privateKeyDHex, "hex"))

const otherPath = [44 + HARDENED, 235 + HARDENED, 0 + HARDENED, 0, 1]
const otherPrivateKeyDHex = "90835ae980cd10e9ca7df05d0e3b3c22e0aed0e75527511337f7c53a9d0c6c69" 
const otherPrivateKey = PrivateKey(Buffer.from(otherPrivateKeyDHex,"hex"))
const otherPublicKey = otherPrivateKey.toPublic()

const sharedCipher = createSharedCipher({privateKey: privateKey.toBuffer(), publicKey: otherPublicKey.toString()})
const encryptedContent1 = sharedCipher.encrypt('new_funds_content', content1)
const encryptedContent2 = sharedCipher.encrypt('new_funds_content', content2)
const encryptedContent3 = sharedCipher.encrypt('record_obt_data_content', content3)
const encryptedContent4 = sharedCipher.encrypt('record_obt_data_content', content4)
const encryptedContent5 = sharedCipher.encrypt('new_funds_content', content5)

testStep(" - - -", "await app.decodeMessage() - newfundsreq memo");
{
    const decodeMessagePromise = app.decodeMessage({path: path, publicKeyHex: otherPublicKey.toUncompressed().toBuffer().toString("hex"), 
                                                    message: encryptedContent1, context: "newfundsreq"});
    await device.review([1, 1, 1, 1, 1, 1, 1], "Review decode message");
    const decodeMessageResponse = await decodeMessagePromise;
    assert.equal(decodeMessageResponse.message.toString("hex"), "145061796565207075626c696320616464726573730a416d6f756e74203130300442544331044254433201074d79206d656d6f0000")
}

testStep(" - - -", "await app.decodeMessage() - newfundsreq hash");
{
    const decodeMessagePromise = app.decodeMessage({path: path, publicKeyHex: otherPublicKey.toUncompressed().toBuffer().toString("hex"), 
                                                    message: encryptedContent2, context: "newfundsreq"});
    await device.review([1, 1, 1, 1, 1, 1, 1, 1], "Review decode message");
    const decodeMessageResponse = await decodeMessagePromise;
    assert.equal(decodeMessageResponse.message.toString("hex"), "145061796565207075626c696320616464726573730a416d6f756e7420313030044254433104425443320001074d792068617368010b4f66666c696e652055524c")    
}

testStep(" - - -", "await app.decodeMessage() - recordobt memo");
{
    const decodeMessagePromise = app.decodeMessage({path: path, publicKeyHex: otherPublicKey.toUncompressed().toBuffer().toString("hex"), 
                                                    message: encryptedContent3, context: "recordobt"});
    await device.review([1, 2, 1, 1, 1, 1, 1, 1, 1, 1], "Review decode message");
    const decodeMessageResponse = await decodeMessagePromise;
    assert.equal(decodeMessageResponse.message.toString("hex"), "145061796572207075626c69632061646472657373145061796565207075626c696320616464726573730a416d6f756e74203130300442544331044254433206537461747573064f627420494401074d79206d656d6f0000")
}

testStep(" - - -", "await app.decodeMessage() - recordobt hash");
{
    console.log(encryptedContent4)
    const decodeMessagePromise = app.decodeMessage({path: path, publicKeyHex: otherPublicKey.toUncompressed().toBuffer().toString("hex"), 
                                                    message: encryptedContent4, context: "recordobt"});
    await device.review([1, 2, 1, 1, 1, 1, 1, 1, 1, 1, 1], "Review decode message");
    const decodeMessageResponse = await decodeMessagePromise;
    assert.equal(decodeMessageResponse.message.toString("hex"), "2d5061796572207075626c696320616464726573732069732076657279206c6f6e672c206c6f6e672c206c6f6e672d5061796565207075626c696320616464726573732069732076657279206c6f6e672c206c6f6e672c206c6f6e670a416d6f756e74203130300442544331044254433206537461747573064f62742049440001234d792068617368206973207175697465206c6f6e6720746f6f2c20746f6f2c20746f6f01224f66666c696e652055524c206973207175697465206c6f6e6720746f6f2c20746f6f")    
}

testStep(" - - -", "await app.decodeMessage() - newfundsreq invalid both memo and hash");
{
    const decodeMessagePromise = app.decodeMessage({path: path, publicKeyHex: otherPublicKey.toUncompressed().toBuffer().toString("hex"), 
                                                    message: encryptedContent5, context: "newfundsreq"});
    await assert.rejects(decodeMessagePromise, DeviceStatusError); 
}

testStep(" - - -", "await app.decodeMessage() - newfundsreq rejected by user");
{
    const decodeMessagePromise = app.decodeMessage({path: path, publicKeyHex: otherPublicKey.toUncompressed().toBuffer().toString("hex"), 
                                                    message: encryptedContent1, context: "newfundsreq"});
    await device.reviewReject([1, 1, 1, 1, 1, 1, 1], "Review decode message");
    await assert.rejects(decodeMessagePromise, DeviceStatusError); 
}

await transport.close()
testEnd(scriptName);
process.stdin.pause()