const menu = document.querySelector('#menupanel')
const gamep = document.querySelector('#gamepanel')
const game = document.querySelector('#game')
const custompanel = document.querySelector('#custompanel')

const playercount = document.querySelector('#playercount')
const playernamelist = document.querySelector('#playernames')
const ranked = document.querySelector('#ranked')
const practice = document.querySelector('#practice')
const tipbuttonS = document.querySelector('#check')
const showbuttonS = document.querySelector('#show')
const plusS = document.querySelector('#plus')
const start = document.querySelector('#start')

//Globals for menu
const nameList = new Array()
//


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
    for(let i = 0; i<10; i++)
        nameList[i].classList.toggle('hidden', !(i < n))  
}


//Game logic

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

init()