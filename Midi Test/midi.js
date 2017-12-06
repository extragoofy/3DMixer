let frequencies = [];
let ppq;
let mpqn = '';
let bpm;
let startTime = 0;
let currentTime = 0;

let request = new XMLHttpRequest(); 
request.open('GET', "../instruments/moog bass.mid", true); 
request.responseType = 'arraybuffer';
request.onload = function () {
    console.log(request.response);
    let undecodedAudio = request.response; 
    if (request.response instanceof ArrayBuffer){
			let byteArray = new Uint8Array(request.response);
            console.log(byteArray);
            // get ppq
            ppq = byteArray[13];
            for(let i = 0; i < byteArray.length; i++) {
                // get mpqn and calculate bpm
                if(byteArray[i] === 255 && byteArray[i+1] === 81){
                    for(let z = 0; z < byteArray[i+2]; z++){
                        mpqn += byteArray[i+3+z].toString(16);
                    }
                    mpqn = parseInt(mpqn, 16);
                    bpm = 60000000 / mpqn;
                }
                // get midi notes
                if(byteArray[i] === 144){
                    frequency = midiNoteToFrequency(byteArray[i+1]);
                    const duration = (60 / (bpm * ppq)) * byteArray[i+3];
                    frequencies.push({
                        frequency: frequency,
                        duration: duration,
                        time: currentTime,
                    });
                    currentTime += duration;
                }
            }
            console.log(frequencies);
		}
};
request.send();

function midiNoteToFrequency (note) {
    return Math.pow(2, ((note - 69) / 12)) * 440;
}