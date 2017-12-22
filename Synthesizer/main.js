let song1 = ['flute', 'bass', 'synth'];
let song2 = ['flute', 'bass', 'drums'];

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
    opt.innerHTML = choosenSong[i];
    opt.value = choosenSong[i];
    sel.appendChild(opt);
}