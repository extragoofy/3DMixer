let song1 = [ 
    {
        instrument: 'flute',
        midi: './song1/song1_flute.mid',
        json: './song1/song1_flute.json',
    },
    {
        instrument: 'bass',
        midi: './song1/song1_bass.mid',
        json: './song1/song1_bass.json',
    },
    {
        instrument: 'synth',
        midi: './song1/song1_synth.mid',
        json: './song1/song1_synth.json',
    }
]

// needed to save intialized instruments
//let instruments = [];
//
//let context = new AudioContext();
//
//
//// get the choosen song from local Storage
//let choosenSong = localStorage.getItem('song');
//if(choosenSong === '1'){
//    choosenSong = song1;
//} else if(choosenSong === '2'){
//    choosenSong = song2;
//}
//
//let sel = document.getElementById('instruments');
//
//// for each instrument create option in dropdown and initalize an instrument
//for(var i = 0; i < choosenSong.length; i++) {
//    
//    var opt = document.createElement('option');
//    opt.innerHTML = choosenSong[i].instrument;
//    opt.value = i;
//    sel.appendChild(opt);
//    
//    instruments.push(
//        new Instrument(choosenSong[i].midi, choosenSong[i].json, context)
//    );
//    
//    instruments[i].loadMidi();
//    instruments[i].loadJSON();
//}

let song = new Song('./song1/song1.mid');
    song.loadMidi();

// initalize a knob with the selected instrument when clicking start
document.getElementById('start').addEventListener('click', function(){
    song.playSong();
//    let instrument = sel.options[sel.selectedIndex].value;
//    knob = new Knob(0, instruments[instrument]);
//    knobs.push(
//        new Knob(0, instrument)
//    );
//    console.log(knob.instrumentValue);
//    for(var i = 0; i < choosenSong.length; i++) {
//        instruments[i].playInstrument();
//    }
});