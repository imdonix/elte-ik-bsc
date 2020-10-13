// TŰRI ERIK - Webprogramozás
// 5. gyakorló feladatsor megoldásai

const controlsDiv = document.querySelector("div");
const inputSize = document.querySelector("input");
const startButton = document.querySelector("button");
const outputSpan = document.querySelector("span#status");
const timeSpan = document.querySelector("span#time");
const table = document.querySelector("table");

let matrix;
let unguessed;
let startTime;

function handleStartButtonClick(){
    let size = parseInt(inputSize.value);
    if (size >= 2 && size <= 10 && size % 2 === 0){
        matrix = [];
        for (let i = 0; i < size; i++) matrix[i] = [];
        for (let i = 0; i < size*size; i++){
            let x, y;
            do {
                x = Math.floor(Math.random() * size);
                y = Math.floor(Math.random() * size);
            } while (matrix[x][y] != undefined)
            matrix[x][y] = Math.floor(i / 2) + 1;
        }

        document.querySelectorAll("tr").forEach(tr => table.removeChild(tr));

        for (let i = 0; i < size; i++){
            let tr = document.createElement("tr");
            for (let j = 0; j < size; j++){
                let td = document.createElement("td");
                tr.appendChild(td);
            }
            table.appendChild(tr);
        }

        console.log(matrix);
        unguessed = size**2 / 2;
        startTime = Date.now();
        controlsDiv.style.display = "none";
    } else {
        outputSpan.innerText = "A tábla mérete 2 és 10 közötti páros szám legyen!";
        outputSpan.style.color = "red";
        inputSize.value = "";
    }
}

let firstTd = null;
let secondTd = null;

function handleTdClick(e){
    let td = e.delegatedTarget;
    if (td.innerText !== "") return;
    if (firstTd === null){
        td.innerText = matrix[td.parentElement.rowIndex][td.cellIndex];
        firstTd = td;
    } else if (secondTd === null){
        td.innerText = matrix[td.parentElement.rowIndex][td.cellIndex];
        if (td.innerText === firstTd.innerText){
            td.style.color = "orange";
            firstTd.style.color = "orange";
            firstTd = null;
            unguessed--;
            if (unguessed === 0){
                controlsDiv.style.display = "block";
                let time = Math.floor((Date.now() - startTime) / 1000);
                outputSpan.innerText = "Nyertél! Eltelt idő: " + time + " másodperc.";
                outputSpan.style.color = "green";
            }
        } else secondTd = td;
    } else {
        firstTd.innerText = "";
        secondTd.innerText = "";
        firstTd = null;
        secondTd = null;
    }
}

function updateTime(){
    if (unguessed > 0){
        let time = Math.floor((Date.now() - startTime) / 1000);
        let sec = ("0" + (time % 60)).slice(-2);
        let min = String(Math.floor(time / 60)).padStart(2, "0");
        timeSpan.innerText = `Eltelt idő = ${min}:${sec}`;
    }
}

let name = null;
function handleDocumentLoaded(){
    name = localStorage.getItem("name");
    while (name === null || name === ""){
        name = prompt("Játékos neve:");
        localStorage.setItem("name", name);
    }
    timeSpan.innerText = "Üdvözöllek, " + name + "!";
}

startButton.addEventListener("click", handleStartButtonClick);
delegate(table, "click", "td", handleTdClick);
window.addEventListener("DOMContentLoaded", handleDocumentLoaded);
setInterval(updateTime, 1000);

function delegate(parent, type, selector, fn) {
    function delegatedFunction(e) {
        if (e.target.matches(`${selector},${selector} *`)) {
            let target = e.target;
            while (!target.matches(selector)) target = target.parentNode;
            e.delegatedTarget = target;
            return fn(e);
        }
    }
    parent.addEventListener(type, delegatedFunction, false);
}