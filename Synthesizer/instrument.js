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
        
        this.filters = {};
        
        
        this.songDuration = songDuration;
    }
    
    midiNoteToFrequency (note) {
        return Math.pow(2, ((note - 69) / 12)) * 440;
    }
    
    playInstrument(){
        this.filters = {
            lowpassFilter: this.configs.filter.cutoff,
            oscillatorAVolume: this.configs.oscillatorA.volume,
            oscillatorBVolume: this.configs.oscillatorB.volume,
            oscillatorADetune: this.configs.oscillatorA.detune,
            oscillatorBDetune: this.configs.oscillatorB.detune,
            oscillatorAVoices: this.configs.oscillatorA.voices,
            oscillatorBVoices: this.configs.oscillatorB.voices,
//            attack: this.configs.ampEnv.attack,
//            decay: this.configs.ampEnv.decay,
        };
            
        this.nextNotetime = this.audioContext.currentTime;
        this.startTime = this.audioContext.currentTime;
        this.currentSongTime = this.audioContext.currentTime;
        this.currentNote = 0;
   
        if(this.configs !== undefined){
            this.detune = this.configs.oscillatorA.detune;
            
            this.gainNode = this.audioContext.createGain();
            this.convolver = this.audioContext.createConvolver();
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

        while((this.startTime + this.notes[this.currentNote].time) < this.audioContext.currentTime + 1) {
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
            this.biquadFilter.Q.value = 1;
            this.biquadFilter.frequency.value = this.filters.lowpassFilter;

            this.gainNode.gain.setValueAtTime(0, time);
            this.gainNode.gain.linearRampToValueAtTime(this.volume, time + this.configs.ampEnv.attack); //attack
//            this.gainNode.gain.setTargetAtTime(1, time, this.configs.ampEnv.attack);
            
            this.gainNode.gain.setTargetAtTime(0, this.notes[this.currentNote].duration, this.configs.ampEnv.decay);
           
//        this.gainNode.gain.linearRampToValueAtTime(0, time + this.notes[this.currentNote].duration + this.notes[this.currentNote].duration * this.configs.ampEnv.decay); //decay
        
            for(let i = 0; i < this.filters.oscillatorAVoices; i++){
                this.oscillatorsA[i] = this.audioContext.createOscillator();
                
                if(this.configs.oscillatorA.octave === '-1'){
                    this.oscillatorsA[i].frequency.value = (this.midiNoteToFrequency(this.notes[this.currentNote].midi) / 2);
                } else if(this.configs.oscillatorA.octave === '+1'){
                    this.oscillatorsA[i].frequency.value = this.midiNoteToFrequency(this.notes[this.currentNote].midi) * 2;
                } else {
                    this.oscillatorsA[i].frequency.value = this.midiNoteToFrequency(this.notes[this.currentNote].midi);
                }
                
                this.oscillatorsA[i].type = this.configs.oscillatorA.waveform;
                
                this.oscillatorsA[i].detune.value = (this.filters.oscillatorADetune * 100) + (i * 2 * (this.filters.oscillatorADetune * 100)) / (this.filters.oscillatorAVoices);
                
//                this.oscillatorsA[i].detune.value = (this.detune * 100) + (i * 2 * (this.detune * 100)) / (this.configs.oscillatorA.voices);

                this.oscillatorsA[i].connect(this.biquadFilter);

                this.oscillatorsA[i].start(time);
                this.oscillatorsA[i].stop(time + this.notes[this.currentNote].duration);
            }
        
            for(let i = 0; i < this.filters.oscillatorBVoices; i++){
                this.oscillatorsB[i] = this.audioContext.createOscillator();

                if(this.configs.oscillatorB.octave === '-1'){
                    this.oscillatorsB[i].frequency.value = (this.midiNoteToFrequency(this.notes[this.currentNote].midi) / 2);
                } else if(this.configs.oscillatorB.octave === '+1'){
                    this.oscillatorsB[i].frequency.value = this.midiNoteToFrequency(this.notes[this.currentNote].midi) * 2;
                } else {
                    this.oscillatorsB[i].frequency.value = this.midiNoteToFrequency(this.notes[this.currentNote].midi);
                }
                this.oscillatorsB[i].type = this.configs.oscillatorB.waveform;
                this.oscillatorsB[i].detune.value = (this.filters.oscillatorBDetune * 100) + (i * 2 * (this.filters.oscillatorBDetune * 100)) / (this.filters.oscillatorBVoices);

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
        this.filters[this.configs['X-Axis']] = (24000 / 127) * x;
        this.filters[this.configs['Y-Axis']] = (1 / 127) * y;
//        this.filters[this.configs['Y-Axis']] = Math.round( y / 12.7);
        this.filters[this.configs['Z-Axis']] = (1 / 127) * z;
//        console.log(this.filters.decay);
//        console.log(x);
//        console.log(y);
//        console.log(z);

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