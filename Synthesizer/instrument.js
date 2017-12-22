class Instrument {
    constructor(midiFilePath, jsonFilePath){
        this.midiFilePath = midiFilePath;
        this.jsonFilePath = jsonFilePath;
        
        this.bpm;
        this.notes;
        
        this.instrumentConfigs;
    }
    
    midiNoteToFrequency (note) {
        return Math.pow(2, ((note - 69) / 12)) * 440;
    }
    
    loadMidi(){
        MidiConvert.load(this.midiFilePath).then((midi) => {
            this.notes = midi.tracks.find((track) => track.name !== undefined).notes;
            this.bpm = midi.header.bpm;
        });
    }
    
    loadJSON(){
        var xobj = new XMLHttpRequest();
        xobj.overrideMimeType("application/json");
        xobj.open('GET', this.jsonFilePath, true);
        xobj.onreadystatechange = function () {
            if (xobj.readyState == 4 && xobj.status == "200") {
                this.instrumentConfigs = JSON.parse(xobj.responseText);
            }
        }.bind(this);
        xobj.send(null);  
    }
    
    get midiFilePathValue(){
        return this.midiFilePath;
    }
}