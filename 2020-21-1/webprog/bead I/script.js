const menu = document.querySelector('#menupanel')
const gamep = document.querySelector('#gamepanel')
const game = document.querySelector('#game')
const custompanel = document.querySelector('#custompanel')

const playercount = document.querySelector('#playercount')
const playercountLabel = document.querySelector('#playercountLabel')
const playernamelist = document.querySelector('#playernames')
const ranked = document.querySelector('#ranked')
const practice = document.querySelector('#practice')
const tipbuttonS = document.querySelector('#check')
const showbuttonS = document.querySelector('#show')
const plusS = document.querySelector('#plus')
const start = document.querySelector('#start')

const gameTable = document.querySelector('#gameTable')
const gamePlayerList = document.querySelector('gamePlayerList')

//Menu
const nameList = new Array()

//Game
let deck;
let table;
let selected;
let aiTip;


//Menu logic

function init()
{
    practice.checked = true;    
    ranked.addEventListener('change', (s) => custompanel.classList.toggle("hidden", true))
    practice.addEventListener('change', (s) => custompanel.classList.toggle("hidden", false))
    
    generatePlayerList()
    playercount.addEventListener('change', (s) => showPlayerNames(playercount.value))
    showPlayerNames(1);

    start.addEventListener('click', (s) => startGame());
}

function generatePlayerList()
{
    function createInputField(i)
    {
        let input = document.createElement('input');
        input.type = "text"
        input.name =  "name";
        input.maxLength = 10;
        input.id = `name${i}`;
        input.value = `Player${i+1}`;
        let listelem = document.createElement('li');
        listelem.appendChild(input)
        return listelem;
    }

    for(let i = 0; i<10; i++)
    {
        let elem = createInputField(i);
        playernamelist.appendChild(elem);
        nameList.push(elem);
    }  
}

function showPlayerNames(n)
{
    playercountLabel.innerHTML = n.toString()
    for(let i = 0; i<10; i++)
        nameList[i].classList.toggle('hidden', !(i < n))  
}


//Game logic

function startGame()
{
    gamep.classList.toggle('hidden', false);
    menu.classList.toggle('hidden', true);

    createGame();
    draw(12);
}

function draw(n)
{
    while(n-- > 0)
        table.push(deck.pop());
    render();
}

function createGame()
{
    deck = generatePack()
    table = new Array()
    selected = new Array()
    aiTip = new Array()
    shuffleArray(deck)
    console.log(deck)
}

function generatePack()
{
    let res = new Array()
    for (let x = 0; x < 3; x++)
        for (let y = 0; y < 3; y++)
            for(let z = 0; z < 3; z++)
                res.push([x,y,z]);
    return res;
}

function shuffleArray(array) 
{
    for (let i = array.length - 1; i > 0; i--) 
    {
        const j = Math.floor(Math.random() * (i + 1));
        [array[i], array[j]] = [array[j], array[i]];
    }
}

function cardToSrc(card)
{
    const color = ['r', 'p', 'g']
    const type =  ['S', 'D', 'P']
    return `${card[0]+1}${color[card[1]]}${type[card[2]]}.svg`
}

function render()
{
    let rows = table.length / 4;
    gameTable.innerHTML = '';

    for(let i = 0; i < rows; i++)
    {
        let row = document.createElement('div')
        row.classList.add('row')
        for(let j = 0; j < 4 && (4*i)+j < table.length; j++)
        {
            let col = document.createElement('div')
            let img = document.createElement('img')

            col.classList.add('col-sm')

            img.src = `./img/${cardToSrc(table[(4*i)+j])}`
            img.width = 117
            img.height = 180           
            img.classList.toggle('selected', selected.includes((4*i)+j))
            img.classList.toggle('tip', aiTip.includes((4*i)+j))

            col.appendChild(img)
            row.appendChild(col)
        }
        gameTable.appendChild(row)
    }
}

init()