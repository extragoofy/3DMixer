class Instrument {
    constructor(filePath) {
        this.filePath = filePath;
        this.frequencies = [];
        this.ppq = 0;
        this.mpqn = 0;
        this.bpm = 0;
        this.currentTime = 0;
        
        this.nextNotetime = 0; 
        this.startTime = 0;
        this.currentNote = 0;
        
        this.oscillator;
        this.context;
        
        this.timerID;
    }
    
    midiNoteToFrequency (note) {
        return Math.pow(2, ((note - 69) / 12)) * 440;
    }
  
//    loadMidi(){
//        let request = new XMLHttpRequest(); 
//        request.open('GET', this.filePath, true); 
//        request.responseType = 'arraybuffer';
//        request.onload = function () {
//            console.log(request.response);
//            let undecodedAudio = request.response; 
//            if (request.response instanceof ArrayBuffer){
//                    let byteArray = new Uint8Array(request.response);
//                    console.log(byteArray);
//                    // get ppq
//                    this.ppq = byteArray[13];
//                    let firstNote = true;
//                    for(let i = 0; i < byteArray.length; i++) {
//                        // get mpqn and calculate bpm
//                        if(byteArray[i] === 255 && byteArray[i+1] === 81){
//                            for(let z = 0; z < byteArray[i+2]; z++){
//                                this.mpqn += byteArray[i+3+z].toString(16);
//                            }
//                            this.mpqn = parseInt(this.mpqn, 16);
//                            this.bpm = 60000000 / this.mpqn;
//                        }
//                        // get midi notes
//                        if(byteArray[i] === 144){
//                            // if it's the first note, check how many beats will be played before playing that note
//                            if(firstNote){
//                                this.currentTime += (60 / (this.bpm * this.ppq)) * byteArray[i-1];
//                                firstNote = false;
//                            }
//                            let duration = 0;
//                            let frequency = midiNoteToFrequency(byteArray[i+1]);
////                            if(byteArray[i+4] === 144){
////                                duration = (60 / (this.bpm * this.ppq)) * byteArray[i+7];
////                            } else {
////                                duration = (60 / (this.bpm * this.ppq)) * byteArray[i+3];
////                            }      
//                            duration = (60 / (this.bpm * this.ppq)) * byteArray[i+3];
//                            this.frequencies.push({
//                                frequency: frequency,
//                                duration: duration,
//                                startTime: this.currentTime,
//                            });
//                            
////                            this.currentTime += ((60 / (this.bpm * this.ppq)) * byteArray[i+3]);
//
//                            if(!(byteArray[i+4] === 144)){
//                               this.currentTime += duration;
//                            }
//
////                             track note pauses
//                            if(byteArray[i+4] === 128 && byteArray[i+1] === byteArray[i+5]){
//                                const pause = (60 / (this.bpm * this.ppq)) * byteArray[i+7];
//                                this.currentTime += pause;
//                            }
//                        }
////                        } else if (byteArray[i] === 128){
////                            let noteOff = this.frequencies.find((note) => note.frequency === midiNoteToFrequency(byteArray[i+1]) && !note.duration);
////                            noteOff.duration = this.currentTime - noteOff.startTime;
////                            this.currentTime += ((60 / (this.bpm * this.ppq)) * byteArray[i+3]);
////                            console.log(this.filePath, (60 / (this.bpm * this.ppq)) * byteArray[i+3]);
////                        }
//                    }
//                    console.log(this.frequencies);
//                }
//        }.bind(this);
//        request.send();
//    }   
//    
    
    loadMidi(){
        MidiConvert.load(this.filePath).then((midi) => {
            this.frequencies = midi.tracks.find((track) => track.name !== undefined).notes;
            this.bpm = midi.header.bpm;
//            console.log(midi);
        });
    }
    
    playInstrument(startTime, context){
        this.nextNotetime = startTime;
        this.startTime = startTime;
        this.context = context;
        this.scheduler();
    }
    
    scheduler() {
        var secondsPerBeat = 60.0 / this.bpm;

        while(this.nextNotetime < this.context.currentTime + 0.1) {
            if(this.currentNote === this.frequencies.length){
                break;
                clearTimeout(this.timerID);
            }
            this.nextNotetime += 0.24 * secondsPerBeat;
            this.playSound(this.startTime + this.frequencies[this.currentNote].time);

        }
        this.timerID = window.setTimeout(() => this.scheduler(), 25.0);
    }

    playSound(time){
        console.log(this.filePath, time);
        this.oscillator = this.context.createOscillator();
        this.oscillator.frequency.value = this.midiNoteToFrequency(this.frequencies[this.currentNote].midi);
        this.oscillator.connect(this.context.destination);
        this.oscillator.start(time);
        this.oscillator.stop(time + this.frequencies[this.currentNote].duration);
        this.currentNote++;
    }
    
//    get returnFilePath() {
//        return this.filePath;
//    }

}