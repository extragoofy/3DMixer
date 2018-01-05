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

if(localStorage.getItem('song') === '1'){
    song = new Song('./song1/song1.mid');
} else{
    console.log('Song not found!')
}

let selectBoxes = document.getElementsByClassName('instruments');

console.log(selectBoxes);

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

//document.getElementById('knob1X').addEventListener('change', () => {
//    knobs[0].instrumentValue.changeXAxis(3);
//})

// initalize a knob with the selected instrument when clicking start
document.getElementById('start').addEventListener('click', function(){
    knobs.forEach((knob, i) => {
        let choosenInstrument = selectBoxes[i].selectedIndex;
        knobs[i] = new Knob(i, song.getInstruments[choosenInstrument]);
    });
    
//    document.getElementById('labelKnob1X').innerHTML = ;
    
    console.log(knobs);
    
    
    song.playSong();
});