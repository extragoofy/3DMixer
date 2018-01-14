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
                        new Drum(this.configs.tracks.find((track) => track.name === drum).notes, buffer, this.context, this.bpm, this.songDuration, drum)
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
    
    stopInstrument(){
        this.drums.forEach((drum) => {
            drum.stopInstrument(); 
        });
    }
    
    changeAxis(x, y, z){
        console.log(this.drums);
        if(x > 63){
            this.drums.forEach((drum) =>{
                if(drum.getName === 'kick'){
                    drum.changeGain(1);
                }
            })
        } else {
            this.drums.forEach((drum) =>{
                if(drum.getName === 'kick'){
                    drum.changeGain(0);
                }
            })
        }
        
        if(y > 63){
            this.drums.forEach((drum) =>{
                if(drum.getName === 'clap'){
                    drum.changeGain(1);
                }
            })
        } else {
            this.drums.forEach((drum) =>{
                if(drum.getName === 'clap'){
                    drum.changeGain(0);
                }
            })
        }
        
        if(z > 40){
            this.drums.forEach((drum) =>{
                if(drum.getName === 'hihat'){
                    drum.changeGain(1);
                }
            })
        } else {
            this.drums.forEach((drum) =>{
                if(drum.getName === 'hihat'){
                    drum.changeGain(0);
                }
            })
        }      
    }
    
}