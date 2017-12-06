let frequencies = [];
let ppq;
let mpqn = '';
let bpm;
let currentTime = 0;

let startTime;
let nextNotetime;

let context = new AudioContext();
let oscillator;
let currentNote = 0;

let request = new XMLHttpRequest(); 
request.open('GET', "song1_flute.mid", true); 
request.responseType = 'arraybuffer';
request.onload = function () {
    console.log(request.response);
    let undecodedAudio = request.response; 
    if (request.response instanceof ArrayBuffer){
			let byteArray = new Uint8Array(request.response);
            console.log(byteArray);
            // get ppq
            ppq = byteArray[13];
            let firstNote = true;
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
                    // if it's the first note, check how many beats will be played before playing that note
                    if(firstNote){
                        currentTime += (60 / (bpm * ppq)) * byteArray[i-1];
                        firstNote = false;
                    }
                    
                    frequency = midiNoteToFrequency(byteArray[i+1]);
                    const duration = (60 / (bpm * ppq)) * byteArray[i+3];
                    frequencies.push({
                        frequency: frequency,
                        duration: duration,
                        time: currentTime,
                    });
                    currentTime += duration;
                    
                    // track note pauses
                    if(byteArray[i+4] === 128 && byteArray[i+1] === byteArray[i+5]){
                        const pause = (60 / (bpm * ppq)) * byteArray[i+7];
                        currentTime += pause;
                    }
                }
            }
            console.log(frequencies);
		}
};
request.send();

function midiNoteToFrequency (note) {
    return Math.pow(2, ((note - 69) / 12)) * 440;
}

document.getElementById("play").addEventListener('click', function(){
    nextNotetime = context.currentTime;
    startTime = context.currentTime;
    scheduler();
});

function scheduler() {
    var secondsPerBeat = 60.0 / bpm;

    while(nextNotetime < context.currentTime + 0.1) {
        nextNotetime += 0.24 * secondsPerBeat;
        playSound(startTime + frequencies[currentNote].time);
       
    }

   timerID = window.setTimeout(scheduler, 25.0);
}

function playSound(time){
    if(currentNote === frequencies.length){
        currentNote = 0;
        clearTimeout(timerID);
    }
    oscillator = context.createOscillator();
    oscillator.frequency.value = frequencies[currentNote].frequency;
    oscillator.connect(context.destination);
    oscillator.start(time);
    oscillator.stop(time + frequencies[currentNote].duration);
    currentNote++;
}