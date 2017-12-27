class Song {
    constructor(midiFilePath){
        this.midiFilePath = midiFilePath;
        this.instruments = {};
        
        this.bpm;
        this.songDuration;
    }
    
    loadMidi(){
        MidiConvert.load(this.midiFilePath).then((midi) => {
            midi.tracks.filter((track) => track.name !== undefined).forEach((instrument) => {
                this.instruments = Object.assign({}, {[instrument.name]: {notes: instrument.notes}}, this.instruments);
            });
            console.log(this.instruments);
            this.bpm = midi.header.bpm;
            this.songDuration = midi.duration;
            console.log(midi);
        });
    }
}