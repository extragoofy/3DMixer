class Drum {
    constructor(notes, buffer, audioContext, bpm, songDuration){
//        this.bufferSource = bufferSource;
        this.notes = notes;
        this.audioContext = audioContext;
        this.bpm = bpm;
        this.songDuration = songDuration;
        this.buffer = buffer;
        this.currentNote = 0;
    }
    
//    loadBuffer(){
//        let request = new XMLHttpRequest();
//        request.open('GET', this.bufferSource, true); 
//        request.responseType = 'arraybuffer';
//        request.onload = () => {
//            let undecodedAudio = request.response; this.audioContext.decodeAudioData(undecodedAudio, (buffer) => {
//                this.buffer = buffer;
//            }); 
//        };
//        request.send();
//    }
    
    playInstrument(){
        this.nextNotetime = this.audioContext.currentTime;
        this.startTime = this.audioContext.currentTime;
        this.currentSongTime = this.audioContext.currentTime;
        this.currentNote = 0;
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
        let sourceBuffer = this.audioContext.createBufferSource(); sourceBuffer.buffer = this.buffer; sourceBuffer.connect(this.audioContext.destination); sourceBuffer.start(time);
        this.currentNote++;
        if(this.currentNote === this.notes.length){
            this.currentNote = 0;
            this.startTime = this.startTime + this.songDuration;
        }
    }
}