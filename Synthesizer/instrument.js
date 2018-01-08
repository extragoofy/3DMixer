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
        
        this.detune;
        this.lowpassFilter;
        this.volume;
        
        
        this.songDuration = songDuration;
    }
    
    midiNoteToFrequency (note) {
        return Math.pow(2, ((note - 69) / 12)) * 440;
    }
    
    playInstrument(){
        console.log("start");
        this.nextNotetime = this.audioContext.currentTime;
        this.startTime = this.audioContext.currentTime;
        this.currentSongTime = this.audioContext.currentTime;
        this.currentNote = 0;
        
        if(this.configs !== undefined){
            this.detune = this.configs.oscillatorA.detune;
            
            this.gainNode = this.audioContext.createGain();
            this.biquadFilter = this.audioContext.createBiquadFilter();
            this.biquadFilter.connect(this.gainNode);
            this.gainNode.connect(this.audioContext.destination);
            
            this.lowpassFilter = 1000;
            this.volume = 1;
        }
        
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

           
            
            this.biquadFilter.type = this.configs.filter.type;

            this.biquadFilter.frequency.value = this.lowpassFilter;
            this.biquadFilter.connect(this.gainNode);

            this.gainNode.gain.setValueAtTime(0, time);
            this.gainNode.gain.linearRampToValueAtTime(this.volume, time + this.configs.ampEnv.attack); //attack

           
        
//        this.gainNode.gain.linearRampToValueAtTime(0, time + this.frequencies[this.currentNote].duration + this.frequencies[this.currentNote].duration * this.configs.ampEnv.decay); //decay
        
        
            for(let i = 0; i < this.configs.oscillatorA.voices; i++){
                this.oscillatorsA[i] = this.audioContext.createOscillator();

                this.oscillatorsA[i].frequency.value = this.midiNoteToFrequency(this.notes[this.currentNote].midi);
                this.oscillatorsA[i].type = this.configs.oscillatorA.waveform;
//                this.oscillatorsA[i].detune.value = (this.configs.oscillatorA.detune * 100) + (i * 2 * (this.configs.oscillatorA.detune * 100)) / (this.configs.oscillatorA.voices);
                
                this.oscillatorsA[i].detune.value = (this.detune * 100) + (i * 2 * (this.detune * 100)) / (this.configs.oscillatorA.voices);

                this.oscillatorsA[i].connect(this.biquadFilter);

                this.oscillatorsA[i].start(time);
                this.oscillatorsA[i].stop(time + this.notes[this.currentNote].duration);
            }
        
            for(let i = 0; i < this.configs.oscillatorB.voices; i++){
                this.oscillatorsB[i] = this.audioContext.createOscillator();

                this.oscillatorsB[i].frequency.value = this.midiNoteToFrequency(this.notes[this.currentNote].midi);
                this.oscillatorsB[i].type = this.configs.oscillatorB.waveform;
                this.oscillatorsB[i].detune.value = (this.configs.oscillatorB.detune * 100) + (i * 2 * (this.configs.oscillatorB.detune * 100)) / (this.configs.oscillatorB.voices);

                this.oscillatorsB[i].connect(this.biquadFilter);
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
    
    changeAxis(x, y, z){
        this.lowpassFilter = (24000 / 127) * x;
        console.log(x);
        console.log(y);
        console.log(z);

    }
    
    changeXAxis(value){
        this.detune = 10;
    }
    
    changeXAxis(value){
        console.log(value);
    }
    
    changeZAxis(value){
        console.log(value);
    }
}