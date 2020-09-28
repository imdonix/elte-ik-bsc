const words = ["hedgehog", "lion", "cat", "mouse", "bird", "eagle", "giraffe", "porcupine"]

const newButton = document.querySelector("#new");
const table = document.querySelector("#guess");
const letters = document.querySelector("#letters");
const pointdisp = document.querySelector("#point");
const alldisp = document.querySelector("#all");

let state = 0; //0 - start |  1 - ingame | 2 - newword | 3 - game end
let point = 0;
let all = 0;
let currentWord;
let guesses;


function createNewGame()
{
    state = 1;
    point = 10;

    let word = words[Math.floor(Math.random() * words.length)];
    currentWord = word;
    guesses = new Array(currentWord.length);
    guesses.fill(false);

    submitPoint(0);
    renderTable();
} 

function guessLetter(letter)
{
    letters.innerText += (letter + "-"); 

    let c = 0;
    for (var i = 0; i < currentWord.length; i++) 
        if(currentWord.charAt(i) == letter)
        {
            c++;
            guesses[i] = true;
        }
    
    if(c == 0)
        submitPoint(-1);

    renderTable();
    checkWin();
}

function checkWin()
{
    let win = guesses.reduce((acc, val) => acc = acc && val, true);
    
    if(win)
    {
        state = 2;
        all += point;
        updateAll();
        alert("You guessed the word right.")
    }
}

function submitPoint(p)
{
    point+=p;
    pointdisp.innerText = point;

    if(point < 0)
        endGame();
}

function updateAll()
{
    alldisp.innerText = all;
}

function endGame()
{
    status = 3;
    alert("Game is over! you reach " + all + " points.");
}

function renderTable()
{
    table.innerHTML = '';

    for (var i = 0; i < currentWord.length; i++) 
    {
        let letter = document.createElement("th");
        letter.id = i;
        letter.innerText = (guesses[i]) ? currentWord.charAt(i) : "?";
        table.appendChild(letter);
    }
}

function restart()
{
    all = 0;
    updateAll();
    createNewGame();
}

document.addEventListener("keypress", (e) =>
{
    if(state == 1)
        guessLetter(e.key)
})

newButton.addEventListener("click", (e) =>
{
    if(state == 0 || state == 2)
        createNewGame();

    if(state == 3)
        restart();
})

document.addEventListener("click", (e) =>
{
    let t = e.target;
    if(e.shiftKey && t.nodeName == "TH")
        console.log('A mező helyére "' + currentWord[t.getAttribute('id')] + '"-t kell irni.' )
})