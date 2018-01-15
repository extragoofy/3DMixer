let context = new AudioContext();
let request = new XMLHttpRequest();
let sourceBuffer;

function handleMouseOver(song){
    sourceBuffer = context.createBufferSource();
    request.open('GET', `./songs/${song}.wav`, true);
    request.responseType = 'arraybuffer';
    request.onload = function () {
        var undecodedAudio = request.response;
        context.decodeAudioData(undecodedAudio, function (buffer) {
            sourceBuffer.buffer = buffer;
            sourceBuffer.loop = true;
            sourceBuffer.connect(context.destination);
            sourceBuffer.start(context.currentTime);
        }); 
    };
    request.send();
    document.getElementById(song).animate([
    // keyframes
        { width: '300px', height: '300px' }, 
        { width: '350px', height: '350px' }
    ], { 
    // timing options
        duration: 300,
    });
    document.getElementById(song).style.width = '350px';
    document.getElementById(song).style.height = '350px';
}

function handleMouseOut(song){
    sourceBuffer.stop(context.currentTime);
    document.getElementById(song).animate([
    // keyframes
        { width: '350px', height: '350px' }, 
        { width: '300px', height: '300px' }
    ], { 
    // timing options
        duration: 300,
    });
    document.getElementById(song).style.width = '300px';
    document.getElementById(song).style.height = '300px';
}

document.getElementById('song1').addEventListener('click', function(){
    localStorage.setItem('song', 1);
    location.href = "knobs.html";
});

document.getElementById('song1').addEventListener('mouseover', () => {
    handleMouseOver('song1');
});

document.getElementById('song1').addEventListener('mouseout', () => {
    handleMouseOut('song1');
});

document.getElementById("song2").addEventListener('click', function(){
    localStorage.setItem('song', 2);
    location.href = "knobs.html";
});

document.getElementById("song2").addEventListener('mouseover', () => {
    handleMouseOver('song2');
});

document.getElementById("song2").addEventListener('mouseout', () => {
    handleMouseOut('song2');
});

document.getElementById("song3").addEventListener('click', function(){
    localStorage.setItem('song', 3);
    location.href = "knobs.html";
});

document.getElementById("song3").addEventListener('mouseover', () => {
    handleMouseOver('song3');
});

document.getElementById("song3").addEventListener('mouseout', () => {
    handleMouseOut('song3');
});