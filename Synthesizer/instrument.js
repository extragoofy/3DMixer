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
    
    // get the start values for the instrument and start the scheduler
    playInstrument(){
        this.filters = {
            lowpassFilter: this.configs.filter.cutoff,
            oscillatorADetune: this.configs.oscillatorA.detune,
            oscillatorBDetune: this.configs.oscillatorB.detune,
            oscillatorAVoices: this.configs.oscillatorA.voices,
            oscillatorBVoices: this.configs.oscillatorB.voices,
            filterQ: this.configs.filterQ,
            volume: this.configs.volume,
            decay: this.configs.ampEnv.decay,
            empty: 0
        };
            
        this.nextNotetime = this.audioContext.currentTime;
        this.startTime = this.audioContext.currentTime;
        this.currentSongTime = this.audioContext.currentTime;
        this.currentNote = 0;
        
        this.gainNodeA = this.audioContext.createGain();
        
        this.filter1 = this.audioContext.createBiquadFilter();
        this.filter2 = this.audioContext.createBiquadFilter();

        
        this.gainNodeA.connect(this.filter1);
        
        this.filter1.connect(this.filter2);
        this.filter2.connect(this.audioContext.destination);

        this.scheduler();
    }
    
    // schedules the notes a short time before they will be played
    scheduler() {
        var secondsPerBeat = 60.0 / this.bpm;

        while((this.startTime + this.notes[this.currentNote].time) < this.audioContext.currentTime + 1) {
            this.nextNotetime += 0.24 * secondsPerBeat;
            this.playSound(this.startTime + this.notes[this.currentNote].time);
        }
        this.timerID = window.setTimeout(() => this.scheduler(), 25.0);
    }
    
    // initialize oscialltors and define filters and gainNode
    playSound(time){
        this.filter1.type = this.configs.filter.type;
        this.filter1.Q.value = (20 / 127) * this.filters.filterQ;
        this.filter1.frequency.value = (24000 / 127) * this.filters.lowpassFilter;
        
        this.filter2.type = this.configs.filter.type;
        this.filter2.Q.value = (20 / 127) * this.filters.filterQ;
        this.filter2.frequency.value = (24000 / 127) * this.filters.lowpassFilter;
        
        
        this.gainNodeA.gain.setValueAtTime(0.0, time);
        this.gainNodeA.gain.linearRampToValueAtTime(((1 / 127) * this.filters.volume), time + this.configs.ampEnv.attack); 

        for(let i = 0; i < this.filters.oscillatorAVoices; i++){
            this.oscillatorsA[i] = this.audioContext.createOscillator();

            if(this.configs.oscillatorA.octave == '-1'){
                this.oscillatorsA[i].frequency.value = (this.midiNoteToFrequency(this.notes[this.currentNote].midi) / 2);
            } else if(this.configs.oscillatorA.octave == '+1'){
                this.oscillatorsA[i].frequency.value = this.midiNoteToFrequency(this.notes[this.currentNote].midi) * 2;
            } else if(this.configs.oscillatorA.octave == '-2'){
                this.oscillatorsA[i].frequency.value = this.midiNoteToFrequency(this.notes[this.currentNote].midi) / 4;
            } else {
                this.oscillatorsA[i].frequency.value = this.midiNoteToFrequency(this.notes[this.currentNote].midi);
            }

            this.oscillatorsA[i].type = this.configs.oscillatorA.waveform;

            this.oscillatorsA[i].detune.value = (this.filters.oscillatorADetune * 100) + (i * 2 * (this.filters.oscillatorADetune * 100)) / (this.filters.oscillatorAVoices);

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

            this.oscillatorsB[i].connect(this.gainNodeA);
            this.oscillatorsB[i].start(time);
            this.oscillatorsB[i].stop(time + this.notes[this.currentNote].duration);
        }

        this.currentNote++;
        if(this.currentNote === this.notes.length){
            this.currentNote = 0;
            this.startTime = this.startTime + this.songDuration;
        }
    }
    
    changeAxis(x, y, z){
        this.filters[this.configs['X-Axis']] = x;
        this.filters[this.configs['Y-Axis']] = y;
        this.filters[this.configs['Z-Axis']] = z;
    }
    
    stopInstrument(){
        clearTimeout(this.timerID);
    }
}