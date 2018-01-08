//let song1 = [ 
//    {
//        instrument: 'flute',
//        midi: './song1/song1_flute.mid',
//        json: './song1/song1_flute.json',
//    },
//    {
//        instrument: 'bass',
//        midi: './song1/song1_bass.mid',
//        json: './song1/song1_bass.json',
//    },
//    {
//        instrument: 'synth',
//        midi: './song1/song1_synth.mid',
//        json: './song1/song1_synth.json',
//    }
//]

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

//let instruments = song.getInstrumentList;
//console.log(instruments);
//instruments.forEach((instrument) => {
//    var opt = document.createElement('option');
//    opt.innerHTML = instrument;
//    opt.value = i;
//    sel.appendChild(opt);
//});

let song;
let knobs = [null, null, null, null];

// initalize a song based on the song selection
if(localStorage.getItem('song') === '1'){
    song = new Song('./song1/song1.mid');
} else{
    console.log('Song not found!')
}

// fill the select boxes with the selection of instruments in the song
let selectBoxes = document.getElementsByClassName('instruments');

song.loadSong().then(() => {
    song.getInstrumentList.forEach((instrument, i) => {
        Array.prototype.forEach.call(selectBoxes, (selectBox) =>{
            var opt = document.createElement('option');
            opt.innerHTML = instrument;
            opt.value = i;
            selectBox.appendChild(opt); 
        });
    });
});


// stop the song
document.getElementById('stop').addEventListener('click', function(){
   song.stopSong(); 
});

// initalize a knob with the selected instrument when clicking start and play the song
document.getElementById('start').addEventListener('click', function(){
    knobs.forEach((knob, i) => {
        let choosenInstrument = selectBoxes[i].selectedIndex;
        knobs[i] = new Knob(i, song.getInstruments[choosenInstrument]);
    });
    song.playSong();
});

// MIDIListener
if (navigator.requestMIDIAccess) {
    navigator.requestMIDIAccess({sysex: false}).then(function(midiAccess) {
        midi = midiAccess;
        var inputs = midi.inputs.values();
        // loop through all inputs
        for (var input = inputs.next(); input && !input.done; input = inputs.next()) {
            // listen for midi messages
            input.value.onmidimessage = onMIDIMessage;
        }
    });
} else {
    alert("No MIDI support in your browser.");
}

let knob;
let x;
let y;
let z;

//wird aufgerufen wenn über Inputs (MidiQuelle) midi daten geschickt werden
function onMIDIMessage(event) {
    
    console.log(event);
    switch(event.data[0]) {
        case 144:
            knob = event.data[1];
            x = event.data[2];
            break;
        case 128:
            if(knobs[knob] !== null){
                knobs[knob].instrumentValue.changeAxis(x, event.data[1], event.data[2]);   
            }
            break;
    }
}