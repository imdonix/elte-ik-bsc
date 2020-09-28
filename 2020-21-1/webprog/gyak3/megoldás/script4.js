// TŰRI ERIK - Webprogramozás
// 3. gyakorló feladatsor megoldásai
// 4. FELADAT

const table = document.querySelector("table");
const winnerSpan = document.querySelector("span");
let next = "X";
let board = [[], [], []];
let won = false;

function handleTdClick(e){
    const td = e.delegatedTarget;
    if (td.innerText === "" && !won){
        td.innerText = next;
        let row = td.parentElement.rowIndex;
        let col = td.cellIndex;
        board[row][col] = next;
        won = decideWinner(next, row, col);
        if (won) winnerSpan.innerText = next + " nyert!";
        next = next === "X" ? "O" : "X";
    }
}

function decideWinner(player, row, col){
    // nyert az adott sorban
    if (board[row].filter(cell => cell === player).length === 3) return true;

    // nyert az adott oszlopban
    let i = 0;
    while (i < 3 && board[i][col] === player) i++;
    if (i == 3) return true;
    
    // nyert az egyik átlón
    i = 0;
    while (i < 3 && board[i][i] === player) i++;
    if (i == 3) return true;

    // nyert a másik átlón
    i = 0;
    while (i < 3 && board[i][2-i] === player) i++;
    if (i == 3) return true;

    // különben nem nyert
    return false;
}

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