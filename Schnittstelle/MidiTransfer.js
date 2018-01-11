window.onload = function(){
    var text = document.getElementById("midiText");
    text.innerHTML = "Hallo, Ladetest";

    // ask if MIDI is available in browser
    if (navigator.requestMIDIAccess) {
        text.innerHTML = "Test Midi-Support: CHECK";
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
        text.innerHTML = "Test: Midi no support";
    }

    //wird aufgerufen wenn über Inputs (MidiQuelle) midi daten geschickt werden
    function onMIDIMessage(event) {
        // event.data is an array
        // event.data[0] = on (144) / off (128) / controlChange (176)  / pitchBend (224) / ...
        // event.data[1] = midi note
        // event.data[2] = velocity

        switch(event.data[0]) {
            case 144:
                // your function startNote(note, velocity)...
                text.innerHTML = "144";
                startNote(event.data[1], event.data[2]);
                break;
            case 128:
                // your function stopNote(note, velocity)...
                text.innerHTML = "128";
                stopNote(event.data[1], event.data[2]);
                break;
            case 176:
                // your function controlChange(controllerNr, value)...
                text.innerHTML = "176";
                controlChange(event.data[1], event.data[2]);
                break;
            case 224:
                // your function pitchBend(LSB, HSB)...
                text.innerHTML = "224";
                pitchBend(event.data[1], event.data[2]);
                break;
        }
    }
    
    
}