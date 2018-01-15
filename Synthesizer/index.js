document.getElementById("song1").addEventListener('click', function(){
    localStorage.setItem('song', 1);
    location.href = "knobs.html";
})

document.getElementById("song2").addEventListener('click', function(){
    localStorage.setItem('song', 2);
    location.href = "knobs.html";
})

document.getElementById("song3").addEventListener('click', function(){
    localStorage.setItem('song', 3);
    location.href = "knobs.html";
})