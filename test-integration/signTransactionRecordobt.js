import { testStart, testStep, testEnd, getScriptName, getSpeculosDefaultConf } from "./speculos-common.js"
import { getTransport } from "./speculos-transport.js"
import { getButtonsAndSnapshots } from "./speculos-buttons-and-snapshots.js"
import { Fio, DeviceStatusError, HARDENED } from "ledgerjs-hw-app-fio"
import { fileURLToPath } from 'url';
import assert from 'assert/strict';
import fetch from "node-fetch"
import crypto from "crypto"

import textenc from "text-encoding"
const TextEncoder = textenc.TextEncoder;
const TextDecoder = textenc.TextDecoder;

import fiojs from '@fioprotocol/fiojs'
const ser = fiojs.Serialize;
const Ecc = fiojs.Ecc
const PrivateKey = Ecc.PrivateKey;
const PublicKey = Ecc.PublicKey;
const Signature = Ecc.Signature;
const arrayToHex = fiojs.Numeric.arrayToHex;
import { JsSignatureProvider } from "@fioprotocol/fiojs/dist/chain-jssig.js"
import { createSharedCipher } from "@fioprotocol/fiojs/dist/encryption-fio.js";
import { checkDecrypt } from "@fioprotocol/fiojs/dist/encryption-check.js";

//import {base64ToBinary, arrayToHex} from "@fioprotocol/fiojs/dist/chain-numeric"



// We initialize chain constantsconstants
const textDecoder = new TextDecoder()
const textEncoder = new TextEncoder()

const httpEndpointTestnet = 'http://testnet.fioprotocol.io'
const httpEndpointMainnet = 'https://fio.greymass.com'

const infoTestnet = await (await fetch(httpEndpointTestnet + '/v1/chain/get_info')).json()
const infoMainnet = await (await fetch(httpEndpointMainnet + '/v1/chain/get_info')).json()

const abiFioAddressTestnet = await (await fetch(httpEndpointTestnet + '/v1/chain/get_abi', {
    body: `{"account_name": "fio.token"}`,
    method: 'POST',
})).json()
const abiMsigTestnet = await (await fetch(httpEndpointTestnet + '/v1/chain/get_abi', {
    body: `{"account_name": "eosio.msig"}`,
    method: 'POST',
})).json()
const abiFioAddressMainnet = await (await fetch(httpEndpointMainnet + '/v1/chain/get_abi', {
    body: `{"account_name": "fio.token"}`,
    method: 'POST',
})).json()
const abiMsigMainnet = await (await fetch(httpEndpointMainnet + '/v1/chain/get_abi', {
    body: `{"account_name": "eosio.msig"}`,
    method: 'POST',
})).json()
const abiReqobtMainnet = await (await fetch(httpEndpointMainnet + '/v1/chain/get_abi', {
    body: `{"account_name": "fio.reqobt"}`,
    method: 'POST',
})).json()
const abiReqobtTestnet = await (await fetch(httpEndpointTestnet + '/v1/chain/get_abi', {
    body: `{"account_name": "fio.reqobt"}`,
    method: 'POST',
})).json()

// Get a Map of all the types from fio.address
const typesFioAddressTestnet = ser.getTypesFromAbi(ser.createInitialTypes(), abiFioAddressTestnet.abi)
const typesTransactionTestnet = ser.getTypesFromAbi(ser.createInitialTypes(), abiMsigTestnet.abi)
const typesFioAddressMainnet = ser.getTypesFromAbi(ser.createInitialTypes(), abiFioAddressMainnet.abi)
const typesTransactionMainnet = ser.getTypesFromAbi(ser.createInitialTypes(), abiMsigMainnet.abi)
const typesTransaction2Mainnet = ser.getTypesFromAbi(ser.createInitialTypes(), abiReqobtMainnet.abi)
const typesTransaction2Testnet = ser.getTypesFromAbi(ser.createInitialTypes(), abiReqobtTestnet.abi)

/*console.log(typesFioAddressMainnet)
console.log(typesFioAddressMainnet)
console.log(typesTransactionMainnet)
console.log(typesTransaction2Mainnet)
console.log(typesTransaction2Mainnet.get('recordobt'))*/


const networkInfo = {
    "TESTNET": {
        chainId: infoTestnet.chain_id,
        typesFioAddress: typesFioAddressTestnet,
        typesTransaction: typesTransactionTestnet,
        typesTransaction2: typesTransaction2Testnet,
    },
    "MAINNET": {
        chainId: infoMainnet.chain_id,
        typesFioAddress: typesFioAddressMainnet,
        typesTransaction: typesTransactionMainnet,
        typesTransaction2: typesTransaction2Mainnet,
    },
}

const path = [44 + HARDENED, 235 + HARDENED, 0 + HARDENED, 0, 0]
const privateKeyDHex = "4d597899db76e87933e7c6841c2d661810f070bad20487ef20eb84e182695a3a" 
const privateKey = PrivateKey(Buffer.from(privateKeyDHex, "hex"))
const publicKey = privateKey.toPublic()

const otherPath = [44 + HARDENED, 235 + HARDENED, 0 + HARDENED, 0, 1]
const otherPrivateKeyDHex = "90835ae980cd10e9ca7df05d0e3b3c22e0aed0e75527511337f7c53a9d0c6c69" 
const otherPrivateKey = PrivateKey(Buffer.from(otherPrivateKeyDHex,"hex"))
const otherPublicKey = otherPrivateKey.toPublic()


//------------------- TWO TRANSACTIONS ------------------------------------------------

const txMemo = {
    expiration: "2021-08-28T12:50:36.686",
    ref_block_num: 0x1122,
    ref_block_prefix: 0x33445566,
    context_free_actions: [],
    actions: [{
        account: "fio.reqobt",
        name: "recordobt",
        authorization: [{
            actor: "aftyershcu22",
            permission: "active",
        }],
        data: {
            fio_request_id: "Fio request ID",
            payer_fio_address: "My payer address",
            payee_fio_address:  "My payee address",
            max_fee: 0x11223344,
            tpid: "rewards@wallet",
            actor: "aftyershcu22",

            other_public_key: otherPublicKey.toUncompressed().toBuffer().toString("hex"),
            payer_public_address: "My payer public address",
            payee_public_address: "My payee public address",
            amount: "amount 1000",
            chain_code: "BTC",
            token_code: "BTC",
            status: "status",
            obt_id: "obt ID",
            memo: "I have memo",
        },
    }],
}

const txHash = {
    expiration: "2021-08-28T12:50:36.686",
    ref_block_num: 0x1122,
    ref_block_prefix: 0x33445566,
    context_free_actions: [],
    actions: [{
        account: "fio.reqobt",
        name: "recordobt",
        authorization: [{
            actor: "aftyershcu22",
            permission: "active",
        }],
        data: {
            fio_request_id: "",
            payer_fio_address: "My payer address",
            payee_fio_address:  "My payee address",
            max_fee: 0x11223344,
            tpid: "rewards@wallet",
            actor: "aftyershcu22",

            other_public_key: otherPublicKey.toUncompressed().toBuffer().toString("hex"),
            payer_public_address: "My payer public address",
            payee_public_address: "My payee public address",
            amount: "amount 1000",
            chain_code: "BTC",
            token_code: "BTC",
            status: "status",
            obt_id: "obt ID",
            hash: "I have hash",
            offline_url: "I have url",
        },
    }],
}

//------------------- SERIALIZE TRANSACTION ------------------------------------------------

async function buildTxUsingFioJs(network, tx, iv) {
    const content = {
        payer_public_address: tx.actions[0].data.payer_public_address,
        payee_public_address: tx.actions[0].data.payee_public_address,
        amount: tx.actions[0].data.amount,
        chain_code: tx.actions[0].data.chain_code,
        token_code: tx.actions[0].data.token_code,
        status: tx.actions[0].data.status,
        obt_id: tx.actions[0].data.obt_id,
        memo: tx.actions[0].data.memo,
        hash: tx.actions[0].data.hash,
        offline_url: tx.actions[0].data.offline_url,
    }

    const pk = PublicKey(Buffer.from(tx.actions[0].data.other_public_key, "hex")).toString()
    const sharedCipher = createSharedCipher({privateKey: privateKey.toBuffer(), publicKey: pk})
    const encryptedContent = sharedCipher.encrypt('record_obt_data_content', content, iv)

    const data = {
        fio_request_id: tx.actions[0].data.fio_request_id,
        payer_fio_address: tx.actions[0].data.payer_fio_address,
        payee_fio_address: tx.actions[0].data.payee_fio_address,
        content: encryptedContent,
        max_fee: tx.actions[0].data.max_fee,
        tpid: tx.actions[0].data.tpid,
        actor: tx.actions[0].data.actor,
    }

    const actionAddress = networkInfo[network].typesTransaction2.get('recordobt')
    const buffer = new ser.SerialBuffer({textEncoder, textDecoder})
    actionAddress.serialize(buffer, data)
    const serializedData = arrayToHex(buffer.asUint8Array())

    let serializedAction = tx.actions[0]
    serializedAction = {
        ...serializedAction,
        data: serializedData,
    }

    const rawTransaction = {
        ...tx,
        max_net_usage_words: 0x00,
        max_cpu_usage_ms: 0x00,
        delay_sec: 0x00,
        context_free_actions: [],
        actions: [serializedAction],     //Actions have to be an array
        transaction_extensions: [],
    }

    const txTransaction = networkInfo[network].typesTransaction.get('transaction')
    const buffer2 = new ser.SerialBuffer({textEncoder, textDecoder})
    txTransaction.serialize(buffer2, rawTransaction)
    const serializedTransaction = buffer2.asUint8Array()

    return {tx: Buffer.from(serializedTransaction), enc: encryptedContent}
}


//---------------------------TESTS---------------------------------------------------------

const scriptName = getScriptName(fileURLToPath(import.meta.url));
testStart(scriptName);

const speculosConf = getSpeculosDefaultConf();
const transport = await getTransport(speculosConf);
const app = new Fio(transport);
const device = getButtonsAndSnapshots(scriptName, speculosConf);

await device.makeStartingScreenshot();

async function runTxTest(network, tx, review1, review2) {
    // Lets sign the transaction with ledger
    const chainId = networkInfo[network].chainId
    const ledgerPromise = app.signTransaction({path, chainId, tx})
    await device.review2(review1, review2, "Review sign");
    const ledgerResponse = await ledgerPromise;
    console.log(ledgerResponse)

    const iv = Buffer.from(ledgerResponse.dhEncryptedData, "base64").slice(0, 16)

    const pair = await buildTxUsingFioJs(network, tx, iv)
    const serTx = pair.tx
    const encContent = pair.enc
    console.log("Test data:")
    console.log(tx)
    console.log(serTx.toString("hex"))
    console.log(encContent)

    const pk = PublicKey(Buffer.from(tx.actions[0].data.other_public_key, "hex")).toString()
    const sharedCipher = createSharedCipher({privateKey: privateKey.toBuffer(), publicKey: pk})
    const plaintextFio = checkDecrypt(sharedCipher.sharedSecret, Buffer.from(encContent, "base64"))
    const plaintextLedger = checkDecrypt(sharedCipher.sharedSecret, Buffer.from(ledgerResponse.dhEncryptedData, "base64"))
    console.log(Buffer.from(plaintextFio).toString("hex"))
    console.log(Buffer.from(plaintextLedger).toString("hex"))
    assert.equal(Buffer.from(plaintextFio).toString("hex"), Buffer.from(plaintextLedger).toString("hex"))

    const fullMsg = Buffer.concat([Buffer.from(networkInfo[network].chainId, "hex"), serTx, Buffer.allocUnsafe(32).fill(0)])
    console.log(fullMsg.toString("hex"))
    const hash = crypto.createHash('sha256').update(fullMsg).digest('hex')
    assert.equal(ledgerResponse.txHashHex, hash);

    const signatureLedger = Signature.fromHex(ledgerResponse.witness.witnessSignatureHex)
    assert.equal(signatureLedger.verify(fullMsg, publicKey), true);
    assert.equal(signatureLedger.verify(fullMsg, otherPublicKey), false);
}

const longSequence = [1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1];
const longSequenceHash = [1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1]; //has empty fio_request_id
const secondSequence = [1, 2]

testStep(" - - -", "Sign testnet transaction - memo");
{
    await runTxTest("TESTNET", txMemo, longSequence, secondSequence)
}

testStep(" - - -", "Sign testnet mainnet - memo");
{
    await runTxTest("MAINNET", txMemo, longSequence, secondSequence)
}

testStep(" - - -", "Sign testnet transaction - hash");
{
    await runTxTest("TESTNET", txHash, longSequenceHash, secondSequence)
}

testStep(" - - -", "Sign testnet mainnet - hash");
{
    await runTxTest("MAINNET", txHash, longSequenceHash, secondSequence)
}

await transport.close()
testEnd(scriptName);
process.stdin.pause();
