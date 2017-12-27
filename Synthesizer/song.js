class Song {
    constructor(midiFilePath){
        this.midiFilePath = midiFilePath;
        this.instrumentsNotes = {};
        
        this.intstruments = [];
        
        this.bpm;
        this.songDuration;
        
        this.context = new AudioContext();
    }
    
    loadMidi(){
        MidiConvert.load(this.midiFilePath).then((midi) => {
            midi.tracks.filter((track) => track.name !== undefined).forEach((instrument) => {
                this.initializeInstruments(instrument.notes, midi.header.bpm, midi.duration);
//                this.instrumentsNotes = Object.assign({}, {[instrument.name]: {notes: instrument.notes}}, this.instrumentsNotes);
            });
            this.bpm = midi.header.bpm;
            this.songDuration = midi.duration;
            console.log(midi);
        });
    }
    
    initializeInstruments(notes, bpm, songDuration){
        this.intstruments.push(
            new Instrument(notes, this.context, bpm, songDuration)
        );
        console.log(this.intstruments);
    }
    
    playSong(){
        this.intstruments.forEach((instrument) => {
            instrument.playInstrument();
        })
    }
}