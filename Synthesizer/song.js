class Song {
    constructor(midiFilePath){
        this.midiFilePath = midiFilePath;
        
        this.drums = [];
        
        this.instruments = [];
        
        this.instrumentList = [];
        
        this.bpm;
        this.songDuration;
        
        this.context = new AudioContext();
    }
    
    // loads the selected song midi file and the json file with all the instrument effect informations
    loadSong(){
        return new Promise((resolve, reject) => {
            
            let instrumentConfigs;
            var xobj = new XMLHttpRequest();
            xobj.overrideMimeType("application/json");
            xobj.open('GET', './songs/song.json', true);
            xobj.onreadystatechange = () => {
                if (xobj.readyState == 4 && xobj.status == "200") {
                    this.drums = JSON.parse(xobj.responseText).drums;
                    instrumentConfigs = JSON.parse(xobj.responseText);
                }
            };
            xobj.send(null); 
            
            MidiConvert.load(this.midiFilePath).then((midi) => {
                midi.tracks.filter((track) => track.name !== undefined).forEach((instrument) => {
                    this.bpm = midi.header.bpm;
                    this.songDuration = midi.duration;
                    this.initializeInstruments(instrument.notes, instrumentConfigs[instrument.name], instrument.name);
                    if(!this.drums.includes(instrument.name)){
                        this.instrumentList.push(
                            instrument.name
                        );
                    }
                });
                
                this.instrumentList.push(
                    'drums'
                );
                this.instruments.push(
                    new Drums(midi, this.drums, this.context, this.bpm, this.songDuration)
                );
                this.instruments[this.instruments.length - 1].initializeDrums();
                
                console.log(midi);
                resolve();
            });
        });
    }
    
    // initialize an instrument for each instrument in the midi file
    initializeInstruments(notes, configs, name){
        if(!this.drums.includes(name)){
            this.instruments.push(
                new Instrument(notes, configs, this.context, this.bpm, this.songDuration, name)
            );
        }
        console.log(this.instruments);
    }
    
    playSong(){
        this.instruments.forEach((instrument) => {
            console.log(instrument);
            instrument.playInstrument();
        });
    }
    
    stopSong(){
        this.instruments.forEach((instrument) => {
            console.log(instrument);
            instrument.stopInstrument();
        });
    }
    
    get getInstruments(){
        return this.instruments;
    }
    
    get getInstrumentList(){
        return this.instrumentList;
    }
    
    get getDrumList(){
        return this.drums;
    }
}