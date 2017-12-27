class Song {
    constructor(midiFilePath){
        this.midiFilePath = midiFilePath;
        
        this.instruments = [];
        
        this.instrumentList = [];
        
        this.bpm;
        this.songDuration;
        
        this.context = new AudioContext();
    }
    
    loadMidi(){
        return new Promise((resolve, reject) => {
            MidiConvert.load(this.midiFilePath).then((midi) => {
                midi.tracks.filter((track) => track.name !== undefined).forEach((instrument) => {
                    this.initializeInstruments(instrument.notes, midi.header.bpm, midi.duration);
                    this.instrumentList.push(
                        instrument.name
                    );
    //                this.instrumentsNotes = Object.assign({}, {[instrument.name]: {notes: instrument.notes}}, this.instrumentsNotes);
                });
                this.bpm = midi.header.bpm;
                this.songDuration = midi.duration;
                console.log(midi);
                resolve();
            });
        });
    }
    
    initializeInstruments(notes, bpm, songDuration){
        this.instruments.push(
            new Instrument(notes, this.context, bpm, songDuration)
        );
        console.log(this.instruments);
    }
    
    playSong(){
        this.instruments.forEach((instrument) => {
            instrument.playInstrument();
        })
    }
    
    get getInstruments(){
        return this.instruments;
    }
    
    get getInstrumentList(){
        return this.instrumentList;
    }
}