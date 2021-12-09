
const letters = "A,B,C,D".split(',')
const raw = "r1(A);r2(A);r4(A);r2(C);r3(A);r4(B);w1(A);w2(B);w3(c)"

let edges = raw.split(';')
.map(s => [s.charAt(3).toUpperCase(), letters[s.charAt(1) - 1]])
.filter(a => a[0] != a[1])

for (const x of edges)
    console.log(`${x[0]} -> ${x[1]}`)

for (const x of edges)
    for (const y of edges)
        if(x[0] == y[1] && x[1] == y[0])
        {
            console.log("Trivial Loop found")
            return;
        }


function removeItemOnce(arr, value) 
{
    var index = arr.indexOf(value);
    if (index > -1) 
    {
        arr.splice(index, 1);
    }
    return arr;
}

function dep(path , acc, eds)
{
    let tmp = acc.filter(l => !eds.find(e => e[0] == l))
    if(tmp.length > 0)
    {
        for (const letter of tmp) 
        {
            let p = [...path]
            let a = [...acc]
            let e = eds.filter(e => e[1] != letter)
            p.push(letter)
            removeItemOnce(a, letter)

            dep(p, a, e)   
        }
    }
    else
        console.log(`Egy megoldás: ${path.join(' -> ', path)}`)
}

dep([] ,letters, edges)



