/*
Magyar Tamás
RNYR2F 
Webprogramozás - számonkérés
Ezt a megoldást a fent írt hallgató küldte be és készítette a Webprogramozás kurzus számonkéréséhez.
Kijelentem, hogy ez a megoldás a saját munkám. Nem másoltam vagy használtam harmadik féltől 
származó megoldásokat. Nem továbbítottam megoldást hallgatótársaimnak, és nem is tettem közzé. 
Az Eötvös Loránd Tudományegyetem Hallgatói Követelményrendszere 
(ELTE szervezeti és működési szabályzata, II. Kötet, 74/C. §) kimondja, hogy mindaddig, 
amíg egy hallgató egy másik hallgató munkáját - vagy legalábbis annak jelentős részét - 
saját munkájaként mutatja be, az fegyelmi vétségnek számít. 
A fegyelmi vétség legsúlyosabb következménye a hallgató elbocsátása az egyetemről.
*/

const inputField = document.querySelector("#input");
const inputNumber = document.querySelector("#inputnumber");
const inputStart = document.querySelector("#inputstart");
const wrongField = document.querySelector("#wrong");
const table = document.querySelector("#table")
const winField = document.querySelector("#win")


let matrix = []
let found = []
let start;

let selected = null;

inputStart.addEventListener("click", (e) =>
{
    let i = inputNumber.value;
    wrongField.classList.toggle("hidden", i >= 2 && i <= 10);

    if(i >= 2 && i <= 10)
        startGame(i);

    inputNumber.value = 0;
})

function startGame(i)
{
    inputField.classList.toggle("hidden");
    winField.classList.toggle("hidden", false);
    found = [];
    generateMatrix(i);
    createTable();
    start = (new Date()).getTime;
}

function generateMatrix(n)
{
    let d = 0;
    let c = 0;
    matrix = new Array(n);

    for (let x = 0; x < n; x++) 
        matrix[x] = new Array(n);

    for (let x = 0; x < n; x++) 
        for (let y = 0; y < n; y++)
        {
            matrix[x][y] = c;
            d++;
            if(d % 2 == 0)
            {
                d = 0;
                c++;
            }
        }

    matrix.forEach(arr => shuffle(arr));
    shuffle(matrix);
}

function createTable() 
{

    let body = document.createElement('tbody');
  
    matrix.forEach(data =>
    {
      let row = document.createElement('tr');
  
      data.forEach(d => 
      {
        let cell = document.createElement('td');
        
        let textnode =  document.createElement('p')
        textnode.innerText = d;
        cell.appendChild(textnode);
        textnode.classList.toggle("hidden", found.find(e => e == d) == null);
        textnode.classList.toggle("color", found.find(e => e == d) != null);
        row.appendChild(cell);
      });
  
      body.appendChild(row);
    });
  
    table.innerHTML = '';
    table.appendChild(body);
  }

function shuffle(arr) {
    for (var i = arr.length - 1; i > 0; i--) 
    {
        var j = Math.floor(Math.random() * (i + 1));
        var t = arr[i];
        arr[i] = arr[j];
        arr[j] = t;
    }
}

document.addEventListener("click", (e) =>
{
    let t = e.target;   
    if(t.nodeName == "TD" && selected != t)
    {
        console.log("sad")
        if(selected == null)
        {
            selected = t;
            t.childNodes[0].classList.toggle("hidden", false);
        }
        else        
        {
            if(t.childNodes[0].innerText == selected.childNodes[0].innerText)
            {
                let n = t.childNodes[0].innerText;
                if(found.find(e => e ==  n) == null)
                    found.push(n);
            }
                

            selected = null;
            createTable();
            checkWin();
        }
    }
})

function checkWin()
{
    let n = matrix.length;

    if(found.length == (n*n)/2)
    {
        inputField.classList.toggle("hidden");
        winField.classList.toggle("hidden", true);
        alert((new Date()).getTime() - start + "Allat nyertél");
    }
}

function delegate(parent, type, selector, fn) 
{
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