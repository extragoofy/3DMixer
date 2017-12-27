//class Instrument {
//    constructor(midiFilePath, jsonFilePath, audioContext){
//        this.midiFilePath = midiFilePath;
//        this.jsonFilePath = jsonFilePath;
//        this.audioContext = audioContext;
//        
//        this.bpm;
//        this.notes;
//        
//        this.instrumentConfigs;
//        
//        this.currentNote = 0;
//        this.currentSongTime = 0;
//    }
//    
//    midiNoteToFrequency (note) {
//        return Math.pow(2, ((note - 69) / 12)) * 440;
//    }
//    
//    loadMidi(){
//        MidiConvert.load(this.midiFilePath).then((midi) => {
////            this.notes = midi.tracks.find((track) => track.name !== undefined).notes;
////            this.bpm = midi.header.bpm;
//            console.log(midi);
//        });
//    }
//    
//    loadJSON(){
//        var xobj = new XMLHttpRequest();
//        xobj.overrideMimeType("application/json");
//        xobj.open('GET', this.jsonFilePath, true);
//        xobj.onreadystatechange = function () {
//            if (xobj.readyState == 4 && xobj.status == "200") {
//                this.instrumentConfigs = JSON.parse(xobj.responseText);
//            }
//        }.bind(this);
//        xobj.send(null);  
//    }
//    
//    playInstrument(){
//        this.nextNotetime = this.audioContext.currentTime;
//        this.startTime = this.audioContext.currentTime;
//        this.currentSongTime = this.audioContext.currentTime;
//        this.currentNote = 0;
//        this.scheduler();
//    }
//
//    scheduler() {
//        var secondsPerBeat = 60.0 / this.bpm;
//
//        while(this.nextNotetime < this.audioContext.currentTime + 0.1) {
////            if(this.currentNote === this.notes.length){
////                this.currentNote = 0;
////                this.startTime = this.startTime + this.notes[this.notes.length - 1].time + this.notes[this.notes.length - 1].duration;
////            }
//            this.nextNotetime += 0.24 * secondsPerBeat;
//            this.playSound(this.startTime + this.notes[this.currentNote].time);
//        }
//        this.timerID = window.setTimeout(() => this.scheduler(), 25.0);
//    }
//    
//    playSound(time){
//        let oscillator = this.audioContext.createOscillator();
//        oscillator.frequency.value = this.midiNoteToFrequency(this.notes[this.currentNote].midi);
//        oscillator.connect(this.audioContext.destination);
//        oscillator.start(time);
//        oscillator.stop(time + this.notes[this.currentNote].duration);
//        this.currentNote++;
//    }
// 
//    get midiFilePathValue(){
//        return this.midiFilePath;
//    }
//}


class Instrument{
    constructor(notes, audioContext, bpm, songDuration){
        this.notes = notes;
        this.audioContext = audioContext;
        this.currentNote = 0;
        
        this.bpm = bpm
        
        this.startTime;
        this.currentSongTime;
        this.nextNotetime;
        
        this.songDuration = songDuration;
    }
    
    midiNoteToFrequency (note) {
        return Math.pow(2, ((note - 69) / 12)) * 440;
    }
    
    playInstrument(){
        this.nextNotetime = this.audioContext.currentTime;
        this.startTime = this.audioContext.currentTime;
        this.currentSongTime = this.audioContext.currentTime;
        this.currentNote = 0;
        this.scheduler();
    }
    
    scheduler() {
        var secondsPerBeat = 60.0 / this.bpm;

        while(this.nextNotetime < this.audioContext.currentTime + 0.1) {
            if(this.currentNote === this.notes.length){
                this.currentNote = 0;
                this.startTime = this.startTime + this.songDuration;
            }
            this.nextNotetime += 0.24 * secondsPerBeat;
            this.playSound(this.startTime + this.notes[this.currentNote].time);
        }
        this.timerID = window.setTimeout(() => this.scheduler(), 25.0);
    }
    
    playSound(time){
        let oscillator = this.audioContext.createOscillator();
        oscillator.frequency.value = this.midiNoteToFrequency(this.notes[this.currentNote].midi);
        oscillator.connect(this.audioContext.destination);
        oscillator.start(time);
        oscillator.stop(time + this.notes[this.currentNote].duration);
        this.currentNote++;
    }
}