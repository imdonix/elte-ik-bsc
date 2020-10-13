const sizeInput = document.querySelector("input");
const startButton = document.querySelector("button");
const controlDiv = document.querySelector("div");
const statusSpan = document.querySelector("span");
const table = document.querySelector("table");

let matrix;
let unguessed;
let startTime;

function handleStartButtonClick(){
    let size = parseInt(sizeInput.value);
    if (size % 2 === 0 && size <= 10 && size >= 2){
        matrix = Array.from(Array(size), () => new Array(size))
        document.querySelectorAll("tr").forEach(tr => table.removeChild(tr));
        for (let i = 0; i < size; i++){
            let tr = document.createElement("tr");
            for (let j = 0; j < size; j++){
                let td = document.createElement("td");
                tr.appendChild(td);
            }
            table.appendChild(tr);
        }
        for (let i = 0; i < size**2; i++){
            let x, y;
            do {
                x = Math.floor(Math.random() * size);
                y = Math.floor(Math.random() * size);
            } while (matrix[x][y] != undefined)
            matrix[x][y] = Math.floor(i / 2) + 1;
        }
        unguessed = size**2 / 2;
        startTime = Date.now();
        console.log(matrix);
        controlDiv.style.display = "none";
    } else {
        sizeInput.value = "";
        statusSpan.innerText = "A tábla mérete 2 és 10 közötti páros szám legyen!";
        statusSpan.style.color = "red";
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
    } else if (secondTd === null) {
        td.innerText = matrix[td.parentElement.rowIndex][td.cellIndex];
        if (td.innerText === firstTd.innerText){
            let seconds = Math.floor((Date.now() - startTime) / 1000);
            td.style.color = "orange";
            firstTd.style.color = "orange";
            firstTd = null;
            unguessed--;
            if (unguessed === 0){
                controlDiv.style.display = "block";
                statusSpan.innerText = "Nyertél! Eltelt idő: " + seconds + " másodperc.";
                statusSpan.style.color = "green";
            }
        } else secondTd = td;
    } else {
        firstTd.innerText = "";
        secondTd.innerText = "";
        firstTd = null;
        secondTd = null;
    }
}

startButton.addEventListener("click", handleStartButtonClick);
delegate(table, "click", "td", handleTdClick);

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
