//let song1 = ['flute', 'bass', 'synth'];
let song2 = ['flute', 'bass', 'drums'];

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

let instruments = [];

let choosenSong = localStorage.getItem('song');
if(choosenSong === '1'){
    choosenSong = song1;
} else if(choosenSong === '2'){
    choosenSong = song2;
}

let sel = document.getElementById('instruments');

for(var i = 0; i < choosenSong.length; i++) {
    
    var opt = document.createElement('option');
    opt.innerHTML = choosenSong[i].instrument;
    opt.value = i;
    sel.appendChild(opt);
    
    instruments.push(
        new Instrument(choosenSong[i].midi, choosenSong[i].json)
    );
    
    instruments[i].loadMidi();
    instruments[i].loadJSON();
}

document.getElementById('start').addEventListener('click', function(){
    let instrument = sel.options[sel.selectedIndex].value;
    knob = new Knob(0, instruments[instrument]);
//    knobs.push(
//        new Knob(0, instrument)
//    );
    console.log(knob.instrumentValue);
});