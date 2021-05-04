let n = Number(process.argv[2])

const x = [-2, -1, 0, 1]
const y = [0, -2, 2, 2]


console.log(`Sum(1) = ${sum(x, (x) => 1)}`)

for (let i = 1; i <= n; i++)
{
    console.log(`Sum(x^${i}) = ${sum(x, (a) => Math.pow(a,i))}`)
    console.log(`Sum(x^${i-1} * y^${i}) = ${sum2(x, y, (a, b) => Math.pow(a,i - 1) * b)}`)
}

console.log("-".repeat(10))

for (let i = 0; i < n; i++)
{
    let tmp = []
    for (let j = 0; j < n; j++) tmp.push(sum(x, (a) => Math.pow(a,i+j)))
    console.log(`[${tmp.join(', ')}] [a${i}] [${sum2(x, y, (a, b) => Math.pow(a,i) * b)}}]` )
}

console.log("-".repeat(10))


function sum(arr, fun)
{
    let s = 0;
    for(let a of arr) s += fun(a);
    return s;
}

function sum2(arr1, arr2, fun)
{
    let s = 0;
    for (let i = 0; i < arr1.length; i++)
        s += fun(arr1[i], arr2[i])  
    return s;
}