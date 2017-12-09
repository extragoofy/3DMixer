let context = new AudioContext();

let flute = new Instrument('song1_flute.mid');
flute.loadMidi();

let synth = new Instrument('song1_synth.mid');
synth.loadMidi();

let bass = new Instrument('song1_bass.mid');
bass.loadMidi();

document.getElementById("playClass").addEventListener('click', function(){
    let start = context.currentTime;
    flute.playInstrument(start, context);
    synth.playInstrument(start, context);
    bass.playInstrument(start, context);
});