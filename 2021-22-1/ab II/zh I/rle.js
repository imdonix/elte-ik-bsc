function encode(input)
{
    input = str2binary(input)

    let ls = new Array()
    let c = 0
    for (const bit of input)
    {
        if(bit == 1)
        {
            ls.push(c)
            c = 0
        }
        else
            c++
    }

    let res = Array()
    rn = ls.map(binary)
    for (const r of rn) 
    {

        let l = r.length - 1
        let sub = Array(l).fill(1)
        sub.push(0)
        sub.push(...r)
        res.push(...sub)
    }

    return [res, ls, rn]
}

function decode(input)
{
    input = str2binary(input)

    let ls = new Array()
    let c = 0
    for (let i = 0; i < input.length; i++) 
    {
        if(input[i] == 0)
        {
            let sub = Array()
            for (let j = 0; j < c + 1; j++, i++) 
                sub.push(input[i+1])
            ls.push(sub)
            c = 0
        }
        else
            c++
    }

    let res = Array()
    let rn = ls.map(decimal)
    for (const n of rn)
    {
        res.push(...Array(n).fill(0))
        res.push(1)
    }

    return [res, ls, rn]
}