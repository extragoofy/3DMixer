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
        if(selectBoxes[i].options[selectBoxes[i].selectedIndex].text != 'Select an instrument'){
            console.log( selectBoxes[i].selectedIndex);
            let choosenInstrument = selectBoxes[i].selectedIndex - 1;
            knobs[i] = new Knob(i, song.getInstruments[choosenInstrument]);
        }
    });
    
    console.log(knobs);
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


/*let knob1X = 0;
let knob1Y = 0;
let knob1Z = 0;

document.getElementById('knob1X').addEventListener('input', (e) => {
    knob1X = e.target.value;
    knobs[0].instrumentValue.changeAxis(knob1X, knob1Y, knob1Z);
});

document.getElementById('knob1Y').addEventListener('input', (e) => {
    knob1Y = e.target.value;
    knobs[0].instrumentValue.changeAxis(knob1X, knob1Y, knob1Z);
});

document.getElementById('knob1Z').addEventListener('input', (e) => {
    knob1Z = e.target.value;
    knobs[0].instrumentValue.changeAxis(knob1X, knob1Y, knob1Z);
});

let knob2X = 0;
let knob2Y = 0;
let knob2Z = 0;

document.getElementById('knob2X').addEventListener('input', (e) => {
    knob2X = e.target.value;
    knobs[1].instrumentValue.changeAxis(knob2X, knob2Y, knob2Z);
});

document.getElementById('knob2Y').addEventListener('input', (e) => {
    knob2Y = e.target.value;
    knobs[1].instrumentValue.changeAxis(knob2X, knob2Y, knob2Z);
});

document.getElementById('knob2Z').addEventListener('input', (e) => {
    knob2Z = e.target.value;
    knobs[1].instrumentValue.changeAxis(knob2X, knob2Y, knob2Z);
});

let knob3X = 0;
let knob3Y = 0;
let knob3Z = 0;

document.getElementById('knob3X').addEventListener('input', (e) => {
    knob3X = e.target.value;
    knobs[2].instrumentValue.changeAxis(knob3X, knob3Y, knob3Z);
});

document.getElementById('knob3Y').addEventListener('input', (e) => {
    knob3Y = e.target.value;
    knobs[2].instrumentValue.changeAxis(knob3X, knob3Y, knob3Z);
});

document.getElementById('knob3Z').addEventListener('input', (e) => {
    knob3Z = e.target.value;
    knobs[2].instrumentValue.changeAxis(knob3X, knob3Y, knob3Z);
});

let knob4X = 0;
let knob4Y = 0;
let knob4Z = 0;

document.getElementById('knob4X').addEventListener('input', (e) => {
    knob4X = e.target.value;
    knobs[3].instrumentValue.changeAxis(knob4X, knob4Y, knob4Z);
});

document.getElementById('knob4Y').addEventListener('input', (e) => {
    knob4Y = e.target.value;
    knobs[3].instrumentValue.changeAxis(knob4X, knob4Y, knob4Z);
});

document.getElementById('knob4Z').addEventListener('input', (e) => {
    knob4Z = e.target.value;
    knobs[3].instrumentValue.changeAxis(knob4X, knob4Y, knob4Z);
});*/