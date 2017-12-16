let context = new AudioContext();

let flute = new Instrument('song1_flute.mid');
flute.loadMidi();

let synth = new Instrument('song1_synth.mid');
synth.loadMidi();

let bass = new Instrument('song1_bass.mid');
bass.loadMidi();

  

var xobj = new XMLHttpRequest();
xobj.overrideMimeType("application/json");
xobj.open('GET', 'song1_flute.json', true); // Replace 'my_data' with the path to your file
xobj.onreadystatechange = function () {
  if (xobj.readyState == 4 && xobj.status == "200") {
    // Required use of an anonymous callback as .open will NOT return a value but simply returns undefined in asynchronous mode
//    callback(xobj.responseText);
      console.log(JSON.parse(xobj.responseText).oscillatorA);
  }
};
xobj.send(null);  


document.getElementById("playClass").addEventListener('click', function(){
    let start = context.currentTime;
    flute.playInstrument(start, context);
//    synth.playInstrument(start, context);
//    bass.playInstrument(start, context);
});