const c = document.querySelector("canvas");
const button = document.querySelector('#btn-change');
const change = document.querySelector('#btn-animation');

let arr;

function random(a, b)
{
    return Math.floor(Math.random() * (b - a + 1) + a);
}

function createArr(min, max, n)
{
    let arr = new Array();
    for(let i = 0; i < n; i++)
        arr.push(random(min,max))
    return arr;
}

console.log(random(-10,10))

console.log(createArr(-5,5,20))

function draw(arr)
{
    var ctx = c.getContext("2d");
    ctx.clearRect(0, 0, c.width, c.height);
    ctx.beginPath();
    ctx.lineWidth = 3;
    
    ctx.moveTo(0, 105);

    let x = 1;
    arr.forEach(e => 
    {
        ctx.lineTo(x * 10, 105 + e);
        ctx.moveTo(x * 10, 105 + e);
        x++;
    });
    ctx.lineTo(x * 10, 105);
    ctx.strokeStyle = 'grey';
    ctx.stroke();
}

arr = createArr(-5,5,20);
draw(arr);

function mod()
{
    arr = arr.map(e => e + random(-1,1))
    draw(arr);
}

button.addEventListener('click', e =>
{
    mod();
})

change.addEventListener('click', e =>
{
    setInterval(mod, 50);
})