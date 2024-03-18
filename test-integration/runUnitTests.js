import { testStart, testStep, testEnd, getScriptName, getSpeculosDefaultConf } from "./speculos-common.js";
import { getButtonsAndSnapshots } from "./speculos-buttons-and-snapshots.js";
import { Fio } from "ledgerjs-hw-app-fio"
import { fileURLToPath } from 'url';
import { getTransport } from "./speculos-transport.js";

const scriptName = getScriptName(fileURLToPath(import.meta.url));
testStart(scriptName);

const speculosConf = getSpeculosDefaultConf();
const transport = await getTransport(speculosConf)
const app = new Fio(transport);
const device = getButtonsAndSnapshots(scriptName, speculosConf);

await device.makeStartingScreenshot();

testStep(" - - -", "await app.runTests()");
await app.runTests();

await transport.close()
testEnd(scriptName);
process.stdin.pause()