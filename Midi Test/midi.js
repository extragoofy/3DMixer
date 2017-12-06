let frequencies = [];

let request = new XMLHttpRequest(); 
request.open('GET', "../instruments/moog bass.mid", true); 
request.responseType = 'arraybuffer';
request.onload = function () {
    console.log(request.response);
    let undecodedAudio = request.response; 
    if (request.response instanceof ArrayBuffer){
			let byteArray = new Uint8Array(request.response);
            console.log(byteArray);
            for(let i = 0; i < byteArray.length; i++) {
                if(byteArray[i] === 144){
                    frequency = midiNoteToFrequency(byteArray[i+1]);
                    frequencies.push(frequency);
                }
            }
		}
};
request.send();

function midiNoteToFrequency (note) {
    return Math.pow(2, ((note - 69) / 12)) * 440;
}