let song;
let knobs = [null, null, null, null];

// initalize a song based on the song selection
if(localStorage.getItem('song') === '1'){
    song = new Song('./songs/song1.mid');
} else if(localStorage.getItem('song') === '2'){
    song = new Song('./songs/song2.mid');
} else if(localStorage.getItem('song') === '3'){
    song = new Song('./songs/song3.mid');
} else{
    console.log('Song not found!')
}

let selectBoxes = document.getElementsByClassName('instruments');
let glowKnobs = document.getElementsByClassName('knob'); 
let startButton = document.getElementById('start');
let stopButton = document.getElementById('stop');
let headline = document.getElementById('headline');
let backLink = document.getElementById('back');

// fill the select boxes with the selection of instruments in the song
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
stopButton.addEventListener('click', function(){
    knobs.forEach((knob, i) => {
        knobs[i] = null;
    });
    
    console.log(knobs);
     Array.prototype.forEach.call(selectBoxes, (selectBox) => {
        selectBox.style.display = 'block';
    });
    
    Array.prototype.forEach.call(glowKnobs, (glowKnob) => {
        glowKnob.style.position = 'relative'; 
        glowKnob.style.display = 'block';
        glowKnob.style.top = '0px'; 
        glowKnob.style.right = '0px'; 
    });
   
    headline.style.display = 'block';
    stopButton.style.display = 'none';
    startButton.style.display = 'block';
    backLink.style.visibility = 'visible';
    song.stopSong(); 
});

// initalize a knob with the selected instrument when clicking start and play the song
startButton.addEventListener('click', function(){
    knobs.forEach((knob, i) => {
        if(selectBoxes[i].options[selectBoxes[i].selectedIndex].text != 'Select an instrument'){
            console.log( selectBoxes[i].selectedIndex);
            let choosenInstrument = selectBoxes[i].selectedIndex - 1;
            knobs[i] = new Knob(i, song.getInstruments[choosenInstrument]);
        }
    });
    
    Array.prototype.forEach.call(selectBoxes, (selectBox) => {
        selectBox.style.display = 'none';
    });
    
    knobs.forEach((knob, i) => {
        if(knob == null){
            glowKnobs[i].style.display = 'none';
        } else {
            glowKnobs[i].style.position = 'absolute';
        }
    });
    
    headline.style.display = 'none';
    stopButton.style.display = 'block';
    startButton.style.display = 'none';
    
    backLink.style.visibility = 'hidden';
    
    console.log(knobs);
    song.playSong();
});

// to change the knob position based on the values from midi 
function changeKnobPosition(knob, x, y){
    if(x == 0 && y == 0){
        glowKnobs[knob].style.display = 'none';
    } else {
        x = (window.innerWidth / 127) * x;
        y = (window.innerHeight / 127) * y;
        
        glowKnobs[knob].style.display = 'block';
        glowKnobs[knob].style.top = y + 'px';
        glowKnobs[knob].style.right = x + 'px'; 
    }
}

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
                changeKnobPosition(knob, x, event.data[1]);
            }
            break;
    }
}
