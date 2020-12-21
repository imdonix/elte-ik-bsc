const output = document.querySelector('#res')

const gold = document.querySelector('#gold')
const silver = document.querySelector('#silver')
const income = document.querySelector('#income')
const spend = document.querySelector('#spend')

const mybal = document.querySelector('#bal')

const trans = []

income.addEventListener('click', () => send(formGold()))
spend.addEventListener('click', () => send(-formGold()))

send(0)

function send(num)
{
    fetch(`index.php?add=${num}`, 
    {
        method: 'POST'
    }) 
    .then(response => response.json())
    .then(data => 
        {
            console.log(data.balance)
            trans.push([new Date(), data.balance])
            render()
        })
}

function formGold()
{
    return (gold.value * 12) + (silver.value * 1);
}

function render()
{
    output.innerHTML = '<tr><th>Időpont</th><th>Egyenleg</th></tr>'
    mybal.innerText = numToGold(trans[trans.length-1][1])
    trans.forEach(elem => 
    {
        const tr = document.createElement('tr')
        const date = document.createElement('td')
        const bal = document.createElement('td')
        date.innerText = elem[0].toUTCString()
        bal.innerText = numToGold(elem[1])
        tr.appendChild(date)
        tr.appendChild(bal)
        output.appendChild(tr)
    });

}

function numToGold(num)
{
    return `${Math.floor(num/12)}G ${num%12}S`
}