//class Instrument {
//    constructor(midiFilePath, jsonFilePath, audioContext){
//        this.midiFilePath = midiFilePath;
//        this.jsonFilePath = jsonFilePath;
//        this.audioContext = audioContext;
//        
//        this.bpm;
//        this.notes;
//        
//        this.configs;
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
//                this.configs = JSON.parse(xobj.responseText);
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
    constructor(notes, configs, audioContext, bpm, songDuration, name){
        this.notes = notes;
        this.audioContext = audioContext;
        this.currentNote = 0;
        this.configs = configs;
        this.name = name;
        
        this.bpm = bpm
        
        this.startTime;
        this.currentSongTime;
        this.nextNotetime;
        
        this.oscillator;
        this.oscillatorsA = [];
        this.oscillatorsB = [];
        
        
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
//        if(this.name === 'flute'){
//            console.log(this.name + ' + ' + (this.startTime + this.notes[this.currentNote].time), this.audioContext.currentTime);
//        }
//        while(this.nextNotetime < this.audioContext.currentTime + 0.1) {
        while((this.startTime + this.notes[this.currentNote].time) < this.audioContext.currentTime + 1) {
            if(this.name === 'flute'){
                console.log(this.oscillatorsA);
            }
            this.nextNotetime += 0.24 * secondsPerBeat;
            this.playSound(this.startTime + this.notes[this.currentNote].time);
        }
        this.timerID = window.setTimeout(() => this.scheduler(), 25.0);
    }
    
    playSound(time){
        if(this.configs === undefined){
            this.oscillator = this.audioContext.createOscillator();
            this.oscillator.frequency.value = this.midiNoteToFrequency(this.notes[this.currentNote].midi);
            this.oscillator.connect(this.audioContext.destination);
            this.oscillator.start(time);
            this.oscillator.stop(time + this.notes[this.currentNote].duration);
        } else {
            this.gainNode = this.audioContext.createGain();
//            this.biquadFilter = this.audioContext.createBiquadFilter();
//            
//            this.biquadFilter.type = this.configs.filter.type;
//            this.biquadFilter.frequency.value = 1000;
//            this.biquadFilter.connect(this.gainNode);

            this.gainNode.gain.setValueAtTime(0, time);
            this.gainNode.gain.linearRampToValueAtTime(0.2, time + this.configs.ampEnv.attack); //attack

            this.gainNode.connect(this.audioContext.destination);
        
//        this.gainNode.gain.linearRampToValueAtTime(0, time + this.frequencies[this.currentNote].duration + this.frequencies[this.currentNote].duration * this.configs.ampEnv.decay); //decay
        
        
            for(let i = 0; i < this.configs.oscillatorA.voices; i++){
                this.oscillatorsA[i] = this.audioContext.createOscillator();

                this.oscillatorsA[i].frequency.value = this.midiNoteToFrequency(this.notes[this.currentNote].midi);
                this.oscillatorsA[i].type = this.configs.oscillatorA.waveform;
                this.oscillatorsA[i].detune.value = (this.configs.oscillatorA.detune * 100) + (i * 2 * (this.configs.oscillatorA.detune * 100)) / (this.configs.oscillatorA.voices);

                this.oscillatorsA[i].connect(this.gainNode);

                this.oscillatorsA[i].start(time);
                this.oscillatorsA[i].stop(time + this.notes[this.currentNote].duration);
            }
        
            for(let i = 0; i < this.configs.oscillatorB.voices; i++){
                this.oscillatorsB[i] = this.audioContext.createOscillator();

                this.oscillatorsB[i].frequency.value = this.midiNoteToFrequency(this.notes[this.currentNote].midi);
                this.oscillatorsB[i].type = this.configs.oscillatorB.waveform;
                this.oscillatorsB[i].detune.value = (this.configs.oscillatorB.detune * 100) + (i * 2 * (this.configs.oscillatorB.detune * 100)) / (this.configs.oscillatorB.voices);

                this.oscillatorsB[i].connect(this.gainNode);
                this.oscillatorsB[i].start(time);
                this.oscillatorsB[i].stop(time + this.notes[this.currentNote].duration);
            }
        }
        this.currentNote++;
        if(this.currentNote === this.notes.length){
            this.currentNote = 0;
            this.startTime = this.startTime + this.songDuration;
        }
    }
}