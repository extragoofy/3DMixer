class Song {
    constructor(midiFilePath){
        this.midiFilePath = midiFilePath;
        
        this.instruments = [];
        
        this.instrumentList = [];
        
        this.bpm;
        this.songDuration;
        
        this.context = new AudioContext();
    }
    
    loadSong(){
        return new Promise((resolve, reject) => {
            
            let instrumentConfigs;
            var xobj = new XMLHttpRequest();
            xobj.overrideMimeType("application/json");
            xobj.open('GET', './song1/song1.json', true);
            xobj.onreadystatechange = () => {
                if (xobj.readyState == 4 && xobj.status == "200") {
                    instrumentConfigs = JSON.parse(xobj.responseText);
                }
            };
            xobj.send(null); 
            
            MidiConvert.load(this.midiFilePath).then((midi) => {
                midi.tracks.filter((track) => track.name !== undefined).forEach((instrument) => {
                    this.bpm = midi.header.bpm;
                    this.songDuration = midi.duration;
                    this.initializeInstruments(instrument.notes, instrumentConfigs[instrument.name], instrument.name);
                    this.instrumentList.push(
                        instrument.name
                    );
                });
                console.log(midi);
                resolve();
            });
        });
    }
    
    initializeInstruments(notes, configs, name){
        this.instruments.push(
            new Instrument(notes, configs, this.context, this.bpm, this.songDuration, name)
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