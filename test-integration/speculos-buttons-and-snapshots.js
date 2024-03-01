import { syncBackTicks, sleep, humanTime } from "./speculos-common.js"

const fioWaitingForCommandsSHA = {
    "nanos": "sha256:13bd32a0f8a2eb3d5723b7e131e439105d63875272e952f703a268a0f1e00728",
    "nanox": "sha256:ce937171040b94097e5d805f76eda47fe8eeb41e50215706634939417214544c",
    "nanosp": "sha256:86fa19f6aa42fb59d1058cc245e95132629b88adb42efea49af289ddeb651405",
} 

const fioWarningDevelSHA = {
    "nanos": "sha256:df7553b0b614d9d3ff0dcb5facde9e1e7e308e2691be9669d206a241f958a999",
    "nanox": "sha256:bc21ced95ca0a8fcea97428b4a840c35db373ed2b6c67654b5de66b330e466f9", 
    "nanosp": "sha256:2bb665c41bcb7e7abda8fc30255f28b35144d26997f314074290eb24b23e37fa",
} 

const fioThreeDotsSHA = {
    "nanos": "sha256:77d4d2651ac7327eee85219c9d25da7b40cf476fad1a67e7eeacb74b37221efe",
    "nanox": "sha256:c650a1475392bdc2ff484341c43bb3aa532ea5262ddb9331f219a24314bc014f", 
    "nanosp": "sha256:c650a1475392bdc2ff484341c43bb3aa532ea5262ddb9331f219a24314bc014f",
} 

const fioEmptyScreenSHA = {
    "nanos": "sha256:6dde663afd5a4b7cf8f4955a8a4b035d358affcb661f18bda910ec837a70ee77",
    "nanox": "sha256:6dde663afd5a4b7cf8f4955a8a4b035d358affcb661f18bda910ec837a70ee77", 
    "nanosp": "sha256:6dde663afd5a4b7cf8f4955a8a4b035d358affcb661f18bda910ec837a70ee77",
} 

class ButtonsAndSnapshots {
    scriptName;
    pngNum = 1;
    pngSha256Previous = "";
    speculosButtonsPort;
	deviceType;

	fioReadySHA;
	approveSHA;
    
    constructor(scriptName, conf) {
        this.scriptName = scriptName;
        this.speculosButtonsPort = conf.speculosApiPort;
		this.deviceType = conf.deviceType;
		this.snapshotName = conf.snapshotName;
		this.fioWaitingSHA = fioWaitingForCommandsSHA[this.deviceType];
		this.fioWarningSHA = fioWarningDevelSHA[this.deviceType];
		this.fioThreeDots = [fioThreeDotsSHA[this.deviceType], fioEmptyScreenSHA[this.deviceType]];
    }

	curlButton(which, hint) { // e.g. which: 'left', 'right', or 'both'
		console.log(humanTime() + " curlButton() // " + which + hint);
		const output = syncBackTicks('curl --silent --show-error --max-time 60 --data \'{"action":"press-and-release"}\' http://127.0.0.1:' + this.speculosButtonsPort + '/button/' + which + ' 2>&1');
		if (output != '{}') {
			console.log(humanTime() + " ERROR: unexpected curl stdout: " + output);
			throw new Error();
		}
	}

	async curlButtonAndScreenshot(which, hint) {
		this.curlButton(which, hint);
		return await this.curlScreenShot(which);
	}

	async curlScreenShot(lastButton = "") {
		const test_device = this.snapshotName; 
		const originalScreenshotSHA = this.pngSha256Previous;
		// e.g. test-transactions.staking-sign-ts.02-transfer-top-shot-moment-p256-sha3-256/nanos.01.png
		const png = this.scriptName + "/" + test_device + "." + this.pngNum.toString(10).padStart(2, '0') + ".png"
		console.log(humanTime() + " curlScreenShot() // " + png + ".new.png");

		const makeScreenshot = (process.env.TEST_PNG_RE_GEN_FOR && (this.scriptName.substring(0, process.env.TEST_PNG_RE_GEN_FOR.length) == process.env.TEST_PNG_RE_GEN_FOR));
		const oldSHAcmd = makeScreenshot ? "" : "echo sha256:`sha256sum $PNG`";

        let generateNewScreenshotFromNextCapture = 0;
		let loops = 0;
		do {
			// get screenshot
			const output = syncBackTicks('export PNG=' + png + ' ; curl --silent --show-error --output $PNG.new.png http://127.0.0.1:' + this.speculosButtonsPort + '/screenshot 2>&1 ; echo sha256:`sha256sum $PNG.new.png` ; '+ oldSHAcmd);

			const errorArray = output.match(/Empty reply from server/gi);
			if (null != errorArray) {
				console.log(humanTime() + " curl: screen shot: warning: curl failed to grab screen shot");
				throw new Error();
			}
			const regex = /sha256:[^\s]*/gm;
			const sha256Array = output.match(regex); // e.g. ['sha256:f3916e7cbbf8502b3eedbdf40cc6d6063b90f0e4a4814e34f2e7029bdaa4eaac','sha256:f3916e7cbbf8502b3eedbdf40cc6d6063b90f0e4a4814e34f2e7029bdaa4eaac']

			// verify, that the screenshot is not the same as previous one
			if (sha256Array[0] /* newly generated PNG */ == this.pngSha256Previous) {
				loops += 1;
				generateNewScreenshotFromNextCapture = 0
				if (loops < 20) {
					if (loops == 15 && lastButton != "" && sha256Array[0] == originalScreenshotSHA) {
						await sleep(100);
						console.log(humanTime() + " Retrying last button press: " +lastButton);
						this.curlButton(lastButton, " Retry last button press.");
						await sleep(100);
					}
					console.log(humanTime() + " curlScreenShot() // matches previous screen shot SHA256 (" + this.pngSha256Previous + "); so requesting another screen shot");
					await sleep(90+10*loops)
					continue;
				} else {
					console.log(humanTime() + " curlScreenShot() // matches previous screen shot SHA256 (" +  + "); ERROR: giving up because too many tries; curl one-liner output:");
					console.log(output);
					console.log(png);
					console.log(humanTime() + " curlScreenShot() // NOTE: re-run with TEST_PNG_RE_GEN_FOR=" + this.scriptName + " to regenerate PNGs");
					throw new Error();
				}
			}

			if (sha256Array[0] /* newly generated PNG */ == this.fioThreeDots[0] || sha256Array == this.fioThreeDots[1]) {
				await sleep(90+10*loops)
				continue;
			}

			// if we generate this screenshot ...
			if (makeScreenshot) {
				// the screenshot we have may be partial capture
				// the tests made suggest, that when we make another screenshot, it will be OK
				if (generateNewScreenshotFromNextCapture == 0) {
					generateNewScreenshotFromNextCapture = 1;
					continue;
				}
				this.pngSha256Previous = sha256Array[0];

				// second try, we believe the screenshot is correct
				generateNewScreenshotFromNextCapture = 0;
				syncBackTicks('export PNG=' + png + ' ; cp $PNG.new.png $PNG');
				break;
			}
			// if we want to compare this screenshot
			else {
				this.pngSha256Previous = sha256Array[0];
			
				// if we have it, we are done
				if (sha256Array[0] == sha256Array[1]) {
					break;
				}

				//ignore DEVEL/nonDEVEL mismatch
				if ((sha256Array[0] == this.fioWaitingSHA && sha256Array[1] == this.fioWarningSHA) ||
				        (sha256Array[1] == this.fioWaitingSHA && sha256Array[0] == this.fioWarningSHA)) {
					break
				}
				// if we want to ignore the test we are done
				if (process.env.TEST_IGNORE_SHA256_SUMS >= 1) {
					console.log(humanTime() + " curlScreenShot() // running tests with TEST_IGNORE_SHA256_SUMS=1 to ignore all PNG differences");
					break;
				}
				// otherwise, we will try again (this deals with partial capture)
				loops += 1;
				if (loops < 20) {
					await sleep(100+10*loops)
					console.log(humanTime() + " curlScreenShot() // screen shot: warning: sha256 sums are different; could be partially rendered screen, so re-requesting screen shot // re-run with TEST_IGNORE_SHA256_SUMS=1 to ignore all PNGs");
					this.pngSha256Previous = sha256Array[0];
					continue;
				} else {
					console.log(humanTime() + " curlScreenShot() // screen shot: warning: sha256 sums are different; ERROR: re-requested screen shot too many times // re-run with TEST_IGNORE_SHA256_SUMS=1 to ignore all PNGs");
					console.log(png);
					throw new Error();
				}
			}
		} while (true);
		console.log(humanTime() + " png " + this.pngNum + " captured, SHA: " + this.pngSha256Previous + ".");
		this.pngNum++;
		return this.pngSha256Previous;
	}

    //higher level functions to be used in the tests
    //Each step should end on "FIO Ready" screen
    checkFioReadyScreen(sha) {
		if (sha != this.fioWaitingSHA && sha != this.fioWarningSHA) {
			throw new Error();
		}
	}

    async makeStartingScreenshot() {
        console.log(humanTime() + " screen shot before sending first apdu command");
        const sha = await this.curlScreenShot();
		this.checkFioReadyScreen(sha);
    }

	async _reviewInternal(counts, textWhat) {
        for(let i=0; i<counts.length; i++) {
			if (this.deviceType == "nanos") {
				await this.curlButtonAndScreenshot("both", " Scroll "+textWhat+" [from screen "+(i+1)+" to "+(i+2)+"]");
			}
			else {
				//for NanoX/S+ we navigate combining right and both
				for(let j=0; j<counts[i]-1; j++) {
					await this.curlButtonAndScreenshot("right", " Scroll "+textWhat+" [screen "+(i+1)+"]");
				}
				await this.curlButtonAndScreenshot("both", " Scroll "+textWhat+" [from screen "+(i+1)+" to "+(i+2)+"]");
			}
        }
	}

    async review(count, textWhat) {
        await this.curlScreenShot();
		await this._reviewInternal(count, textWhat);
		if (this.deviceType == "nanos") {
			await this.curlButtonAndScreenshot("right", "Approve: "+textWhat);
		}
		else {
			await this.curlButtonAndScreenshot("both", "Approve: "+textWhat);
		}
        console.log(humanTime() + " back to main screen");
    }

	async review2(count1, count2, textWhat) {
        await this.curlScreenShot();
		await this._reviewInternal(count1, textWhat+" part1");
		if (this.deviceType == "nanos") {
			await this.curlButtonAndScreenshot("right", "Approve: "+textWhat);
		}
		else {
			await this.curlButtonAndScreenshot("both", "Approve: "+textWhat);
		}
		await this._reviewInternal(count2, textWhat+" part2");
		if (this.deviceType == "nanos") {
			await this.curlButtonAndScreenshot("right", "Approve: "+textWhat);
		}
		else {
			await this.curlButtonAndScreenshot("both", "Approve: "+textWhat);
		}
        console.log(humanTime() + " back to main screen");
    }

	async reviewReject(count, textWhat) {
        await this.curlScreenShot();
		await this._reviewInternal(count, textWhat);
		if (this.deviceType == "nanos") {
			await this.curlButtonAndScreenshot("left", "Reject: "+textWhat);
		}
		else {
			await this.curlButtonAndScreenshot("right", "Move to reject"+textWhat);
			await this.curlButtonAndScreenshot("both", "Reject: "+textWhat);
		}
        console.log(humanTime() + " back to main screen");
    }

    async reviewPartial(count, textWhat) {
        await this.curlScreenShot();
		await this._reviewInternal(count, textWhat);
        console.log(humanTime() + " back to main screen");
    }
}

class LedgerButtonsAndSnapshots {
	constructor () {
	    this.wait = async (msg) => {
			await sleep(200);
			console.log(msg)

			process.stdin.setRawMode(true)
			return new Promise(resolve => process.stdin.once('data', (d) => {
    			process.stdin.setRawMode(false)
				resolve()
			}))
//  		    await sleep(5000);
		};
	}
	curlButton(which, hint) {}
	async curlButtonAndScreenshot(which, hint) {}
	async curlScreenShot(lastButton = "") {}
    async makeStartingScreenshot() {}

	async review(textWhat) {
		await this.wait("Please, review the transaction on the device.")
	}

	async review2(textWhat) {
		await this.wait("Please, review the transaction on the device.")
	}

	async reviewPartial(textWhat) {
		await this.wait("Please, review part of the transaction till error occours.")
	}

	async reviewReject(count, textWhat) {
		await this.wait("Please, review the transaction clink through this and reject it. (You need to click through this first)")
	}

	async toggleExpertMode(textWhat) { 
		await this.wait("Please, toggle expert mode ("+textWhat+")")
	}

	async enterMenuElementAndReview(menuElementIndex, textWhat) {
		await this.wait("Please, go to menu element "+menuElementIndex+" ("+textWhat+") and review the screens.")
	}
}

function getButtonsAndSnapshots(scriptName, conf) {
	if (conf.testOn === "ledger") {
		return new LedgerButtonsAndSnapshots()
	}
	return new ButtonsAndSnapshots(scriptName, conf)
}

export {getButtonsAndSnapshots};
