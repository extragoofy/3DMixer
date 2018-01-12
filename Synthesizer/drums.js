class Drums{
    constructor(configs, drumList, audioContext, bpm, songDuration){
        this.configs = configs;
        this.drumList = drumList;
        this.context = audioContext;
        this.bpm = bpm;
        this.songDuration = songDuration;
        
        this.name = 'drums';
        this.drums = [];
    }
    
    initializeDrums(){
        this.drumList.forEach((drum) => {
            let request = new XMLHttpRequest();
            request.open('GET', `./song1/${drum}.wav`, true); 
            request.responseType = 'arraybuffer';
            request.onload = () => {
                let undecodedAudio = request.response; this.context.decodeAudioData(undecodedAudio, (buffer) => {
                    this.drums.push(
                        new Drum(this.configs.tracks.find((track) => track.name === drum).notes, buffer, this.context, this.bpm, this.songDuration)
                    );
                }); 
            };
            request.send();
        });
        console.log(this.drums);
    }
    
    playInstrument(){
        this.drums.forEach((drum) => {
            drum.playInstrument(); 
        });
    }
    
    changeAxis(x, y, z){
        console.log(x);   
    }
    
}