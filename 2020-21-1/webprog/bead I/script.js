const menu = document.querySelector('#menupanel')
const gamep = document.querySelector('#gamepanel')
const game = document.querySelector('#game')
const custompanel = document.querySelector('#custompanel')
const rules = document.querySelector('#rules')

const playercount = document.querySelector('#playercount')
const playercountLabel = document.querySelector('#playercountLabel')
const playernamelist = document.querySelector('#playernames')
const ranked = document.querySelector('#ranked')
const practice = document.querySelector('#practice')
const tipbuttonS = document.querySelector('#check')
const showbuttonS = document.querySelector('#show')
const plusS = document.querySelector('#plus')
const rulesLink = document.querySelector('#rulesLink')
const back = document.querySelector('#back')

const start = document.querySelector('#start')

const gameTable = document.querySelector('#gameTable')
const gamePlayerList = document.querySelector('#gamePlayerList')
const gameStatus = document.querySelector('#gameStatus')
const gameIsSet = document.querySelector('#gameIsSet')
const gameShowSet = document.querySelector('#gameShowSet')
const gameplusthree = document.querySelector('#gameplusthree')
const gameRestart = document.querySelector('#gameRestart')

let nameList = new Array()
let players
let deck
let table
let selected
let aiTip
let gameover
let round
let autoDraw


//Menu logic

function init()
{
    practice.checked = true;    
    ranked.addEventListener('change', (s) => custompanel.classList.toggle("hidden", true))
    practice.addEventListener('change', (s) => custompanel.classList.toggle("hidden", false))
    gameIsSet.addEventListener('click', tip)
    gameShowSet.addEventListener('click', show)
    gameplusthree.addEventListener('click', plusThree)
    rulesLink.addEventListener('click', e => {rules.classList.toggle('hidden', false), menu.classList.toggle('hidden', true)})
    back.addEventListener('click', e => {rules.classList.toggle('hidden', true), menu.classList.toggle('hidden', false)})

    
    generatePlayerList()
    playercount.addEventListener('change', (s) => showPlayerNames(playercount.value))
    showPlayerNames(1);

    start.addEventListener('click', (s) => startGame(createSettings()));
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
        nameList.push(input);
        let listelem = document.createElement('li');
        listelem.appendChild(input)
        return listelem;
    }

    for(let i = 0; i<10; i++)
    {
        let elem = createInputField(i);
        playernamelist.appendChild(elem);
    }  
}

function showPlayerNames(n)
{
    playercountLabel.innerHTML = n.toString()
    for(let i = 0; i<10; i++)
        nameList[i].parentElement.classList.toggle('hidden', !(i < n))  
}

function createSettings()
{
    return {
        count : playercount.value,
        tip: ranked.checked ? false : tipbuttonS.checked,
        show: ranked.checked ? false : showbuttonS.checked,
        plus: ranked.checked ? false : plusS.checked,
    }
}

//Game logic

function startGame(settings)
{
    gamep.classList.toggle('hidden', false);
    menu.classList.toggle('hidden', true);
    gameIsSet.classList.toggle('hidden', !settings.tip);
    gameShowSet.classList.toggle('hidden', !settings.show);
    gameplusthree.classList.toggle('hidden', !settings.plus);

    generatePlayers(settings.count);
    createGame(!settings.plus);
    draw(12);
}

function onTableCardClick(tableIndex)
{
    if(!isAnyPlayerSeleced())
    {
        render("Player needed to select set.")
        return;
    }

    const i = selected.indexOf(tableIndex)
    if (i >= 0) 
        selected.splice(i, 1)
    else
        selected.push(tableIndex)
    
    if(selected.length == 3)
        selectSet();
    else
        render(`Selected at ${Math.floor(tableIndex/4)+1}:${tableIndex%4+1}`)
}

function selectSet()
{
    const resoult = checkSet(selected)
    if(resoult)
        replace(selected);
    selected = new Array()
    addPoint(resoult)
    render(resoult ? "This was a set!" : "This was not a set!")
}

function addPoint(success)
{
    for(const player of players)
    {
        if(player.selected) player.point += success ? 1 : -1
        if(player.selected) player.ban = success ? false : true
        if(isMultiplayer()) player.selected = false
    }

    for(const player of players)
        if(AllBanned() || success) player.ban = false

    round++
    selected = new Array()
}

function AllBanned()
{
    for(const player of players)
        if(!player.ban)
            return false;
    return true;
}

function isAnyPlayerSeleced()
{    
    for(const p of players)
        if(p.selected)
            return true
    return false
}

function selectPlayer(player)
{
    if(isAnyPlayerSeleced())
        return;
    
    if(player.ban)
        return;

    player.selected = true;

    const r = round;
    render()

    setTimeout(() =>
    {
        if(r!=round) return
        addPoint(false)
        render("Out of time")
    },  10000)
}

function checkSet(setIndexes)
{
    for(let i=0;i<3;i++)
        if(!((table[setIndexes[0]][i]+1)*(table[setIndexes[1]][i]+1)*(table[setIndexes[2]][i]+1) == 1*2*3
        || (table[setIndexes[0]][i] == table[setIndexes[1]][i] && table[setIndexes[1]][i] == table[setIndexes[2]][i])))
            return false;
    return true;
}

function replace(tableIndexes)
{
    let vals = tableIndexes.map(i => table[i])
    table = table.filter(c => !vals.includes(c))
    draw(3)
}

function draw(n)
{
    while(n-- > 0 && deck.length > 0)
        table.push(deck.pop());

    if(deck.length == 0 && !search()) gameover = true
    if(deck.length > 0 && !search() && autoDraw) draw(3)
    aiTip = new Array()

    render();
}

function search()
{
    let l = table.length;
    for(let i=0;i<l;i++)
        for(let j=0;j<l;j++)
            for(let k=0;k<l;k++)
                if(i!=j && i!=k && j!=k)
                    if(checkSet([i,j,k]))
                        return [i,j,k];
    return false;
}

function tip()
{
    render(search() ? "There is a set on the table!" : "There is no set on the table!");
}

function show()
{
    const resoult = search();
    if(resoult) aiTip = resoult;
    render(search() ? "Set is highlighted" : "There is no set on the table!");
}

function plusThree()
{
    draw(3)
}

function generatePlayers(c)
{
    players = new Array()
    for(let i=0;i<c;i++)
        players.push({name: nameList[i].value, point: 0, selected: c == 1, ban: false})
}

function isMultiplayer()
{
    return players.length > 1
}

function createGame(auto)
{
    gameover = false
    autoDraw = auto
    round = 0
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

function render(msg)
{
    let rows = table.length / 4
    gameTable.innerHTML = ''
    gamePlayerList.innerHTML = ''

    for(const player of players)
    {
        let li = document.createElement('li')
        let badge = document.createElement('span')

        li.classList.add('list-group-item')
        if(player.selected) li.classList.add('active')
        if(player.ban) li.classList.add('disabled')
        badge.classList.add('badge')
        badge.classList.add('badge-success')
        li.innerHTML = `${player.name} `
        badge.innerHTML = player.point
        li.addEventListener('click', e => selectPlayer(player))

        li.appendChild(badge)
        gamePlayerList.appendChild(li)
    }

    for(let i = 0; i < rows; i++)
    {
        let row = document.createElement('div')
        row.classList.add('row')
        for(let j = 0; j < 4 && (4*i)+j < table.length; j++)
        {
            const tableIndex = (4*i)+j
            let col = document.createElement('div')
            let img = document.createElement('img')

            col.classList.add('col-sm')

            img.src = `./img/${cardToSrc(table[tableIndex])}`
            img.width = 117
            img.height = 180           
            img.classList.toggle('selected', selected.includes(tableIndex))
            img.classList.toggle('tip', aiTip.includes(tableIndex))
            img.addEventListener('click', e => onTableCardClick(tableIndex))

            col.appendChild(img)
            row.appendChild(col)
        }
        gameTable.appendChild(row)
    }

    if(gameover)
    {
        gameStatus.innerHTML = "Gameover!"  
        gameRestart.classList.toggle('hidden', false);
        gameIsSet.classList.toggle('hidden', true);
        gameShowSet.classList.toggle('hidden', true);
        gameplusthree.classList.toggle('hidden', true);
        gameTable.parentElement.remove();
    }
    else
        if(msg)
            gameStatus.innerHTML = msg.toString()
}

init()

function proof()
{
    for(let i = 0;i<3;i++)
        for(let j = 0;j<3;j++)
            for(let k = 0;k<3;k++)
                if((i+1)*(j+1)*(k+1) == 1*2*3)
                    if(i == j || j == k || i == k)
                        return false
    return true
}
