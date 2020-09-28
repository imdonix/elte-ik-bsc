// TŰRI ERIK - Webprogramozás
// 3. gyakorló feladatsor megoldásai
// 1. FELADAT

let last = null;
let lastTime = null;
const outputSpan = document.querySelector("span");

function handleClick(e){
    if (last !== null){
        let dist  = ((e.screenX - last.screenX) ** 2 + (e.screenY - last.screenY) ** 2) ** 0.5;
        let time1 = e.timeStamp - last.timeStamp;
        let time2 = Date.now() - lastTime;
        outputSpan.innerText = "Elmozdulás: " + dist + " px\nEltelt idő (event): " + time1 + " ms\nEltelt idő (now): " + time2 + " ms";
    } else outputSpan.innerText = "Várom a második kattintást...";
    last = e;
    lastTime = Date.now();
}

document.addEventListener("click", handleClick);