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
            currentFilterEnv: this.configs.currentFilterEnv,
//            attack: this.configs.ampEnv.attack,
//            decay: this.configs.ampEnv.decay,
        };
            
        this.nextNotetime = this.audioContext.currentTime;
        this.startTime = this.audioContext.currentTime;
        this.currentSongTime = this.audioContext.currentTime;
        this.currentNote = 0;
   
        
        this.detune = this.configs.oscillatorA.detune;
        
        
        this.gainNodeA = this.audioContext.createGain();
        this.gainNodeB = this.audioContext.createGain();
        
        this.filter1 = this.audioContext.createBiquadFilter();
        this.filter2 = this.audioContext.createBiquadFilter();
        
        this.gainNodeA.connect(this.filter1);
        this.gainNodeB.connect(this.filter1);
        this.filter1.connect(this.filter2);
        
        this.modFilterGain = this.audioContext.createGain();
        this.modFilterGain.connect(this.filter1.detune);
        this.modFilterGain.connect(this.filter2.detune);
        
        this.envelope = this.audioContext.createGain();
        
        this.filter2.connect(this.envelope);
        
        this.envelope.connect(this.audioContext.destination);

        
        
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
        this.filter1.type = this.configs.filter.type;
        this.filter1.Q.value = 0;
        this.filter1.frequency.value = this.filters.lowpassFilter;
        
//        this.filter2.type = this.configs.filter.type;
//        this.filter2.Q.value = 0;
//        this.filter2.frequency.value = this.filters.lowpassFilter;
//  
        this.gainNodeA.gain.value = this.configs.oscillatorA.volume;
        this.gainNodeB.gain.value = this.configs.oscillatorB.volume;
//        
//        
//        this.envelope.gain.value = 0.0;
//        this.envelope.gain.setValueAtTime( 0.0, time );
//        this.envelope.gain.linearRampToValueAtTime( 1.0, time + this.configs.ampEnv.attack);
//        this.envelope.gain.setTargetAtTime( (this.configs.ampEnv.sustain/100.0), this.notes[this.currentNote].duration, this.configs.ampEnv.decay );
//        
        this.modFilterGain.gain.value = this.configs.modFilterGain*24;
        
        var envAttackEnd = time + (this.configs.currentEnvA/20.0);

        this.envelope.gain.value = 0.0;
        this.envelope.gain.setValueAtTime( 0.0, time );
        this.envelope.gain.linearRampToValueAtTime( 1.0, envAttackEnd );
        this.envelope.gain.setTargetAtTime( (this.configs.currentEnvS/100), time + envAttackEnd, (this.configs.currentEnvD/100.0)+0.001 );

        var filterAttackLevel = this.filters.currentFilterEnv*72;  // Range: 0-7200: 6-octave range
        var filterSustainLevel = filterAttackLevel* this.configs.currentFilterEnvS / 100.0; // range: 0-7200
        var filterAttackEnd = (this.configs.currentFilterEnvA/20.0);

        if (!filterAttackEnd) 
                    filterAttackEnd=0.05; // tweak to get target decay to work properly
        this.filter1.detune.setValueAtTime( 0, time );
        this.filter1.detune.linearRampToValueAtTime( filterAttackLevel, time+filterAttackEnd );
        this.filter2.detune.setValueAtTime( 0, time );
        this.filter2.detune.linearRampToValueAtTime( filterAttackLevel, time+filterAttackEnd );
        this.filter1.detune.setTargetAtTime( filterSustainLevel, time+filterAttackEnd, (this.configs.currentFilterEnvD/100.0) );
        this.filter2.detune.setTargetAtTime( filterSustainLevel, time+filterAttackEnd, (this.configs.currentFilterEnvD/100.0) );
////        
        this.modOsc = this.audioContext.createOscillator();
        this.modOsc.connect(this.modFilterGain);

        
        
        
//            this.biquadFilter.type = this.configs.filter.type;
//            this.biquadFilter.Q.value = 1;
//            this.biquadFilter.frequency.value = this.filters.lowpassFilter;
        
    
//
//            this.gainNode.gain.setValueAtTime(0, time);
//            this.gainNode.gain.linearRampToValueAtTime(1, time + this.configs.ampEnv.attack); //attack
////            this.gainNode.gain.setTargetAtTime(1, time, this.configs.ampEnv.attack);
//            
//            this.gainNode.gain.setTargetAtTime(0, this.notes[this.currentNote].duration, this.configs.ampEnv.decay);
           
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

                this.oscillatorsA[i].connect(this.gainNodeA);

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

                this.oscillatorsB[i].connect(this.gainNodeB);
                this.oscillatorsB[i].start(time);
                this.oscillatorsB[i].stop(time + this.notes[this.currentNote].duration);
            }
        
        this.modOsc.start(time);
        this.modOsc.stop(time + this.notes[this.currentNote].duration);
        
        this.currentNote++;
        if(this.currentNote === this.notes.length){
            this.currentNote = 0;
            this.startTime = this.startTime + this.songDuration;
        }
    }
    
    changeAxis(x, y, z){
//        this.filters[this.configs['X-Axis']] = (24000 / 127) * x;
        this.filters[this.configs['X-Axis']] = (100 / 127) * x;
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