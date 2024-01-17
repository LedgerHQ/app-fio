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
const Signature = Ecc.Signature;
const arrayToHex = fiojs.Numeric.arrayToHex;
import { JsSignatureProvider } from "@fioprotocol/fiojs/dist/chain-jssig.js"

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
const abiAddressMainnet = await (await fetch(httpEndpointMainnet + '/v1/chain/get_abi', {
    body: `{"account_name": "fio.address"}`,
    method: 'POST',
})).json()
const abiAddressTestnet = await (await fetch(httpEndpointTestnet + '/v1/chain/get_abi', {
    body: `{"account_name": "fio.address"}`,
    method: 'POST',
})).json()

// Get a Map of all the types from fio.address
const typesFioAddressTestnet = ser.getTypesFromAbi(ser.createInitialTypes(), abiFioAddressTestnet.abi)
const typesTransactionTestnet = ser.getTypesFromAbi(ser.createInitialTypes(), abiMsigTestnet.abi)
const typesFioAddressMainnet = ser.getTypesFromAbi(ser.createInitialTypes(), abiFioAddressMainnet.abi)
const typesTransactionMainnet = ser.getTypesFromAbi(ser.createInitialTypes(), abiMsigMainnet.abi)
const typesTransaction2Mainnet = ser.getTypesFromAbi(ser.createInitialTypes(), abiAddressMainnet.abi)
const typesTransaction2Testnet = ser.getTypesFromAbi(ser.createInitialTypes(), abiAddressTestnet.abi)

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




// Serializes and signs transaction using fiojs
async function buildTxAndSignatureFioJs(network, tx, txtype, pubkey) {
    // We serialize the transaction
    // Get the action type
    const actionType = networkInfo[network].typesTransaction2.get(txtype)

    // Serialize the actions[] "data" field (This example assumes a single action, though transactions may hold an array of actions.)
    const buffer = new ser.SerialBuffer({textEncoder, textDecoder})
    actionType.serialize(buffer, tx.actions[0].data)
    const serializedData = arrayToHex(buffer.asUint8Array())

    // Get the actions parameter from the transaction and replace the data field with the serialized data field
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

    // Get the transaction action type
    const txnaction = networkInfo[network].typesTransaction.get('transaction')

    // Serialize the transaction
    const buffer2 = new ser.SerialBuffer({textEncoder, textDecoder})
    txnaction.serialize(buffer2, rawTransaction)
    const serializedTransaction = buffer2.asUint8Array()



    //Lets compute hash in using Signature.sign
    const msg = Buffer.concat([Buffer.from(networkInfo[network].chainId, "hex"), serializedTransaction, Buffer.allocUnsafe(32).fill(0)])
    const hash = crypto.createHash('sha256').update(msg).digest('hex')

    
    
    //Now using signatureProvider.sign
    const signatureProvider = new JsSignatureProvider([
        PrivateKey.fromHex(privateKeyDHex).toString(),
        PrivateKey.fromHex(otherPrivateKeyDHex).toString()
    ]);
    const requiredKeys = [pubkey.toString()]
    const serializedContextFreeData = null

    const signedTxn = await signatureProvider.sign({
        chainId: networkInfo[network].chainId,
        requiredKeys: requiredKeys,
        serializedTransaction: serializedTransaction,
        serializedContextFreeData: serializedContextFreeData,
    })

    return {
        serializedTx: serializedTransaction,
        fullMsg: msg,
        hash: crypto.createHash('sha256').update(msg).digest('hex'),
        signature: signedTxn.signatures[0],
    }
}


const path = [44 + HARDENED, 235 + HARDENED, 0 + HARDENED, 0, 0]
const privateKeyDHex = "4d597899db76e87933e7c6841c2d661810f070bad20487ef20eb84e182695a3a" 
const privateKey = PrivateKey(Buffer.from(privateKeyDHex, "hex"))
//const privateKey = PrivateKey(hex_to_buf(privateKeyDHex))
const publicKey = privateKey.toPublic()

const otherPath = [44 + HARDENED, 235 + HARDENED, 0 + HARDENED, 0, 1]
const otherPrivateKeyDHex = "90835ae980cd10e9ca7df05d0e3b3c22e0aed0e75527511337f7c53a9d0c6c69" 
//const otherPrivateKey = PrivateKey(hex_to_buf(otherPrivateKeyDHex))
const otherPrivateKey = PrivateKey(Buffer.from(otherPrivateKeyDHex,"hex"))
const otherPublicKey = otherPrivateKey.toPublic()

const basicTx = {
    expiration: "2021-08-28T12:50:36.686",
    ref_block_num: 0x1122,
    ref_block_prefix: 0x33445566,
    context_free_actions: [],
    transaction_extensions: [],
}

const scriptName = getScriptName(fileURLToPath(import.meta.url));
testStart(scriptName);

const speculosConf = getSpeculosDefaultConf();
const transport = await getTransport(speculosConf);
const app = new Fio(transport);
const device = getButtonsAndSnapshots(scriptName, speculosConf);

await device.makeStartingScreenshot();


testStep(" - - -", "Sign testnet transaction - remalladdr");
{
    const network = "TESTNET"
    const tx = {
        ...basicTx,
        actions: [{
            account: "fio.address",
            name: "remalladdr",
            authorization: [{
                actor: "aftyershcu22",
                permission: "active",
            }],
            data: {
                fio_address: "FIO8PRe4WRZJj5mkem6qVGKyvNFgPsNnjNN6kPhh6EaCpzCVin5Jj",
                max_fee: 0x11223344,
                tpid: "rewards@wallet",
                actor: "aftyershcu22",
            },
        }],
    
    }

    // Lets sign the transaction with fiojs
    const {serializedTx, fullMsg, hash, signature} = await buildTxAndSignatureFioJs(network, tx, tx.actions[0].name, publicKey)
    console.log("Full message:")
    console.log(fullMsg.toString("hex"));

    // Lets sign the transaction with ledger
    const chainId = networkInfo[network].chainId
    const ledgerPromise = app.signTransaction({path, chainId, tx})
    await device.review([1, 1, 2, 1, 2], "Review sign");
    const ledgerResponse = await ledgerPromise;
    const signatureLedger = Signature.fromHex(ledgerResponse.witness.witnessSignatureHex)

    assert.equal(ledgerResponse.txHashHex, hash);
    assert.equal(signatureLedger.verify(fullMsg, publicKey), true);
    assert.equal(signatureLedger.verify(fullMsg, otherPublicKey), false);
}

testStep(" - - -", "Sign testnet transaction - addbundles");
{
    const network = "TESTNET"
    const tx = {
        ...basicTx,
        actions: [{
            account: "fio.address",
            name: "addbundles",
            authorization: [{
                actor: "aftyershcu22",
                permission: "active",
            }],
            data: {
                fio_address: "FIO8PRe4WRZJj5mkem6qVGKyvNFgPsNnjNN6kPhh6EaCpzCVin5Jj",
                bundle_sets: 0x33223344,
                max_fee: 0x11223344,
                tpid: "rewards@wallet",
                actor: "aftyershcu22",
            },
        }],    
    }

    // Lets sign the transaction with fiojs
    const {serializedTx, fullMsg, hash, signature} = await buildTxAndSignatureFioJs(network, tx, tx.actions[0].name, publicKey)
    console.log("Full message:")
    console.log(fullMsg.toString("hex"));

    // Lets sign the transaction with ledger
    const chainId = networkInfo[network].chainId
    const ledgerPromise = app.signTransaction({path, chainId, tx})
    await device.review([1, 1, 2, 1, 1, 2], "Review sign");
    const ledgerResponse = await ledgerPromise;
    const signatureLedger = Signature.fromHex(ledgerResponse.witness.witnessSignatureHex)

    assert.equal(ledgerResponse.txHashHex, hash);
    assert.equal(signatureLedger.verify(fullMsg, publicKey), true);
    assert.equal(signatureLedger.verify(fullMsg, otherPublicKey), false);
}

testStep(" - - -", "Sign testnet transaction - regaddress");
{
    const network = "TESTNET"
    const tx = {
        ...basicTx,
        actions: [{
            account: "fio.address",
            name: "regaddress",
            authorization: [{
                actor: "aftyershcu22",
                permission: "active",
            }],
            data: {
                fio_address: "FIO8PRe4WRZJj5mkem6qVGKyvNFgPsNnjNN6kPhh6EaCpzCVin5Jj",
                owner_fio_public_key: "My FIO Public Key",
                max_fee: 0x11223344,
                tpid: "rewards@wallet",
                actor: "aftyershcu22",
            },
        }],    
    }

    // Lets sign the transaction with fiojs
    const {serializedTx, fullMsg, hash, signature} = await buildTxAndSignatureFioJs(network, tx, tx.actions[0].name, publicKey)
    console.log("Full message:")
    console.log(fullMsg.toString("hex"));

    // Lets sign the transaction with ledger
    const chainId = networkInfo[network].chainId
    const ledgerPromise = app.signTransaction({path, chainId, tx})
    await device.review([1, 1, 2, 1, 1, 2], "Review sign");
    const ledgerResponse = await ledgerPromise;
    const signatureLedger = Signature.fromHex(ledgerResponse.witness.witnessSignatureHex)

    assert.equal(ledgerResponse.txHashHex, hash);
    assert.equal(signatureLedger.verify(fullMsg, publicKey), true);
    assert.equal(signatureLedger.verify(fullMsg, otherPublicKey), false);
}

testStep(" - - -", "Sign testnet transaction - xferaddress");
{
    const network = "TESTNET"
    const tx = {
        ...basicTx,
        actions: [{
            account: "fio.address",
            name: "xferaddress",
            authorization: [{
                actor: "aftyershcu22",
                permission: "active",
            }],
            data: {
                fio_address: "FIO8PRe4WRZJj5mkem6qVGKyvNFgPsNnjNN6kPhh6EaCpzCVin5Jj",
                new_owner_fio_public_key: "My FIO Public Key",
                max_fee: 0x11223344,
                tpid: "rewards@wallet",
                actor: "aftyershcu22",
            },
        }],    
    }

    // Lets sign the transaction with fiojs
    const {serializedTx, fullMsg, hash, signature} = await buildTxAndSignatureFioJs(network, tx, tx.actions[0].name, publicKey)
    console.log("Full message:")
    console.log(fullMsg.toString("hex"));

    // Lets sign the transaction with ledger
    const chainId = networkInfo[network].chainId
    const ledgerPromise = app.signTransaction({path, chainId, tx})
    await device.review([1, 1, 2, 1, 1, 2], "Review sign");
    const ledgerResponse = await ledgerPromise;
    const signatureLedger = Signature.fromHex(ledgerResponse.witness.witnessSignatureHex)

    assert.equal(ledgerResponse.txHashHex, hash);
    assert.equal(signatureLedger.verify(fullMsg, publicKey), true);
    assert.equal(signatureLedger.verify(fullMsg, otherPublicKey), false);
}

testStep(" - - -", "Sign mainnet transaction - regdomain");
{
    const network = "MAINNET"
    const tx = {
        ...basicTx,
        actions: [{
            account: "fio.address",
            name: "regdomain",
            authorization: [{
                actor: "aftyershcu22",
                permission: "active",
            }],
            data: {
                fio_domain: "FIO DOMAIN",
                owner_fio_public_key: "My FIO Public Key",
                max_fee: 0x11223344,
                tpid: "rewards@wallet",
                actor: "aftyershcu22",
            },
        }],    
    }

    // Lets sign the transaction with fiojs
    const {serializedTx, fullMsg, hash, signature} = await buildTxAndSignatureFioJs(network, tx, tx.actions[0].name, publicKey)
    console.log("Full message:")
    console.log(fullMsg.toString("hex"));

    // Lets sign the transaction with ledger
    const chainId = networkInfo[network].chainId
    const ledgerPromise = app.signTransaction({path, chainId, tx})
    await device.review([1, 1, 1, 1, 1, 2], "Review sign");
    const ledgerResponse = await ledgerPromise;
    const signatureLedger = Signature.fromHex(ledgerResponse.witness.witnessSignatureHex)

    assert.equal(ledgerResponse.txHashHex, hash);
    assert.equal(signatureLedger.verify(fullMsg, publicKey), true);
    assert.equal(signatureLedger.verify(fullMsg, otherPublicKey), false);
}

testStep(" - - -", "Sign mainnet transaction - renewdomain");
{
    const network = "MAINNET"
    const tx = {
        ...basicTx,
        actions: [{
            account: "fio.address",
            name: "renewdomain",
            authorization: [{
                actor: "aftyershcu22",
                permission: "active",
            }],
            data: {
                fio_domain: "FIO DOMAIN",
                max_fee: 0x11223344,
                tpid: "rewards@wallet",
                actor: "aftyershcu22",
            },
        }],    
    }

    // Lets sign the transaction with fiojs
    const {serializedTx, fullMsg, hash, signature} = await buildTxAndSignatureFioJs(network, tx, tx.actions[0].name, publicKey)
    console.log("Full message:")
    console.log(fullMsg.toString("hex"));

    // Lets sign the transaction with ledger
    const chainId = networkInfo[network].chainId
    const ledgerPromise = app.signTransaction({path, chainId, tx})
    await device.review([1, 1, 1, 1, 2], "Review sign");
    const ledgerResponse = await ledgerPromise;
    const signatureLedger = Signature.fromHex(ledgerResponse.witness.witnessSignatureHex)

    assert.equal(ledgerResponse.txHashHex, hash);
    assert.equal(signatureLedger.verify(fullMsg, publicKey), true);
    assert.equal(signatureLedger.verify(fullMsg, otherPublicKey), false);
}

testStep(" - - -", "Sign mainnet transaction - setdomainpub true");
{
    const network = "MAINNET"
    const tx = {
        ...basicTx,
        actions: [{
            account: "fio.address",
            name: "setdomainpub",
            authorization: [{
                actor: "aftyershcu22",
                permission: "active",
            }],
            data: {
                fio_domain: "FIO DOMAIN",
                is_public: 0x01,
                max_fee: 0x11223344,
                tpid: "rewards@wallet",
                actor: "aftyershcu22",
            },
        }],    
    }

    // Lets sign the transaction with fiojs
    const {serializedTx, fullMsg, hash, signature} = await buildTxAndSignatureFioJs(network, tx, tx.actions[0].name, publicKey)
    console.log("Full message:")
    console.log(fullMsg.toString("hex"));

    // Lets sign the transaction with ledger
    const chainId = networkInfo[network].chainId
    const ledgerPromise = app.signTransaction({path, chainId, tx})
    await device.review([1, 1, 1, 1, 1, 2], "Review sign");
    const ledgerResponse = await ledgerPromise;
    const signatureLedger = Signature.fromHex(ledgerResponse.witness.witnessSignatureHex)

    assert.equal(ledgerResponse.txHashHex, hash);
    assert.equal(signatureLedger.verify(fullMsg, publicKey), true);
    assert.equal(signatureLedger.verify(fullMsg, otherPublicKey), false);
}

testStep(" - - -", "Sign testnet transaction - setdomainpub false");
{
    const network = "TESTNET"
    const tx = {
        ...basicTx,
        actions: [{
            account: "fio.address",
            name: "setdomainpub",
            authorization: [{
                actor: "aftyershcu22",
                permission: "active",
            }],
            data: {
                fio_domain: "FIO DOMAIN",
                is_public: 0x00,
                max_fee: 0x11223344,
                tpid: "rewards@wallet",
                actor: "aftyershcu22",
            },
        }],    
    }

    // Lets sign the transaction with fiojs
    const {serializedTx, fullMsg, hash, signature} = await buildTxAndSignatureFioJs(network, tx, tx.actions[0].name, publicKey)
    console.log("Full message:")
    console.log(fullMsg.toString("hex"));

    // Lets sign the transaction with ledger
    const chainId = networkInfo[network].chainId
    const ledgerPromise = app.signTransaction({path, chainId, tx})
    await device.review([1, 1, 1, 1, 1, 2], "Review sign");
    const ledgerResponse = await ledgerPromise;
    const signatureLedger = Signature.fromHex(ledgerResponse.witness.witnessSignatureHex)

    assert.equal(ledgerResponse.txHashHex, hash);
    assert.equal(signatureLedger.verify(fullMsg, publicKey), true);
    assert.equal(signatureLedger.verify(fullMsg, otherPublicKey), false);
}

testStep(" - - -", "Sign testnet transaction - xferdomain");
{
    const network = "TESTNET"
    const tx = {
        ...basicTx,
        actions: [{
            account: "fio.address",
            name: "xferdomain",
            authorization: [{
                actor: "aftyershcu22",
                permission: "active",
            }],
            data: {
                fio_domain: "FIO DOMAIN",
                new_owner_fio_public_key: "My FIO Public Key",
                max_fee: 0x11223344,
                tpid: "rewards@wallet",
                actor: "aftyershcu22",
            },
        }],    
    }

    // Lets sign the transaction with fiojs
    const {serializedTx, fullMsg, hash, signature} = await buildTxAndSignatureFioJs(network, tx, tx.actions[0].name, publicKey)
    console.log("Full message:")
    console.log(fullMsg.toString("hex"));

    // Lets sign the transaction with ledger
    const chainId = networkInfo[network].chainId
    const ledgerPromise = app.signTransaction({path, chainId, tx})
    await device.review([1, 1, 1, 1, 1, 2], "Review sign");
    const ledgerResponse = await ledgerPromise;
    const signatureLedger = Signature.fromHex(ledgerResponse.witness.witnessSignatureHex)

    assert.equal(ledgerResponse.txHashHex, hash);
    assert.equal(signatureLedger.verify(fullMsg, publicKey), true);
    assert.equal(signatureLedger.verify(fullMsg, otherPublicKey), false);
}

testStep(" - - -", "Sign testnet transaction - remallnfts");
{
    const network = "TESTNET"
    const tx = {
        ...basicTx,
        actions: [{
            account: "fio.address",
            name: "remallnfts",
            authorization: [{
                actor: "aftyershcu22",
                permission: "active",
            }],
            data: {
                fio_address: "FIO8PRe4WRZJj5mkem6qVGKyvNFgPsNnjNN6kPhh6EaCpzCVin5Jj",
                max_fee: 0x11223344,
                tpid: "rewards@wallet",
                actor: "aftyershcu22",
            },
        }],    
    }

    // Lets sign the transaction with fiojs
    const {serializedTx, fullMsg, hash, signature} = await buildTxAndSignatureFioJs(network, tx, tx.actions[0].name, publicKey)
    console.log("Full message:")
    console.log(fullMsg.toString("hex"));

    // Lets sign the transaction with ledger
    const chainId = networkInfo[network].chainId
    const ledgerPromise = app.signTransaction({path, chainId, tx})
    await device.review([1, 1, 2, 1, 2], "Review sign");
    const ledgerResponse = await ledgerPromise;
    const signatureLedger = Signature.fromHex(ledgerResponse.witness.witnessSignatureHex)

    assert.equal(ledgerResponse.txHashHex, hash);
    assert.equal(signatureLedger.verify(fullMsg, publicKey), true);
    assert.equal(signatureLedger.verify(fullMsg, otherPublicKey), false);
}

await transport.close()
testEnd(scriptName);
process.stdin.pause()