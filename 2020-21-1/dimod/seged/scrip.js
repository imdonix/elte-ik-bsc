const input = document.querySelector('#input')
const divider = document.querySelector('#divider')
const inputHelp = document.querySelector('#inputHelp')
const dividerHelp = document.querySelector('#dividerHelp')
const output = document.querySelector('#output')

const horner = document.querySelector('#horner')
const hornerHelp = document.querySelector('#hornerHelp')
const values = document.querySelector('#values')
const table = document.querySelector('table')

document.querySelector('#go').addEventListener('click', visualize);
document.querySelector('#do').addEventListener('click', dohorner);

function visualize()
{
    output.innerHTML = '';
    let inp = readPoly(input, inputHelp)
    let div = readPoly(divider, dividerHelp)
    
    let res = [];
    let c = 0
    let t = multiply(inp, [1,0])
    while(largest(div)[1] <= largest(t)[1] && c < 50)
    {
        c++
        let p = largest(t);
        let d = largest(div)
        let mem = [p[0] / d[0], p[1] - d[1]];
        let mul = multiply(div, mem);
        niceWrite(c,t,mul,mem, div)
        t = sub(t, mul)
        res.push(mem)
    }
    
    output.innerHTML += `(${polynomToString(inp)}) ÷ (${polynomToString(div)}) = <b>${polynomToString(res)}</b>`
}

function dohorner()
{
    let poly = readPoly(horner, inputHelp)
    let v = values.value.split(' ')
    table.innerHTML = ''
    let head = ['-']
    for(let p of poly)
        head.push(p[0])


    addrow(head, true);
    v.forEach(e => 
    {
        let larg = largest(poly)
        let tmp = [e, larg[0]];
        for (let i = larg[1]; i >= 0; i--)
            tmp.push(tmp[tmp.length-1] * parseFloat(e) + parseInt(find(poly, i-1)[0]));
        tmp.splice(-1,1)
        addrow(tmp, false);
    });
}

function addrow(arr, head)
{
    let row = document.createElement('tr')
    for(let n of arr)
    {
        let col = document.createElement(head ? 'th' : 'td')
        col.innerHTML = n;
        row.appendChild(col);
    }
    table.appendChild(row)
}

function niceWrite(c, t, mul, mem, div)
{
    output.innerHTML += `<h4>${c} kör</h4>`
    output.innerHTML += `(<b>${memToString(mem)}</b>) * (${polynomToString(div)}) = ${polynomToString(mul)} <br>`
    output.innerHTML += `(${polynomToString(t)}) - (${polynomToString(mul)}) = T`
    output.innerHTML += '<hr>'
}

function readPoly(input, helper)
{
    let inp = buildPolynom(input.value)
    helper.innerHTML = polynomToString(inp)
    return inp
}

function buildPolynom(input)
{
    let res = new Array()
    let arr = input.split(' ')
    let l = arr.length - 1
    for(let c of arr)
        res.push([c, l--]);
    return res
}

function memToString(e)
{
    return `${e[0] > 0 ? '+' : '-'} ${Math.abs(e[0])}${e[1] > 0 ? 'x<sup>' + e[1] + '</sup>' : ''}`
}

function polynomToString(poly)
{
    let tmp = ''
    if(poly.length == 0) return tmp
    for(let e of poly)
        if(e[0] != 0)
            tmp += `${e[0] > 0 ? '+' : '-'} ${Math.abs(e[0])}${e[1] > 0 ? 'x<sup>' + e[1] + '</sup>' : ''} `
    return tmp;
}

function largest(poly)
{
    if(poly.length == 0) return null
    let max = [0,0];
    for(let e of poly)
        if(e[1] > max[1] && e[0] != 0)
            max = e;
    return max;
}

function find(poly, n)
{
    for(let e of poly)
        if(e[1] == n)
            return [e[0], e[1]];
    return [0,n];
}

function multiply(poly, mul)
{
    let res = new Array()
    for(let e of poly)
        res.push([e[0] * mul[0], e[1] + mul[1]])
    return res
}

function sub(poly, div)
{
    let res = new Array()
    let n = largest(poly)[1]
    for (let i = n; i >= 0; i--)
    {
        let a = find(poly, i);
        let b = find(div, i);
        res.push([a[0] - b[0], i]);
    }
        
    return res;
}