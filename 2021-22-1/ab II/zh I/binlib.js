function binary(number)
{
    tmp = Array()
    while(number > 0 || tmp.length == 0)
    {
        tmp.push(number % 2)
        number = Math.floor(number / 2)
    }
    return tmp.reverse()
}

function lbinary(number, l)
{
    let r = binary(number)
    while(r.length < l)
        r.unshift(0)
    return r
}

function decimal(binary)
{
    binary = binary.reverse()
    let c = 0
    for (const i in binary) 
        if(binary[i] == 1)
            c += Math.pow(2, i)
    return c
}

function str2binary(input)
{
    tmp = Array()
    for (let i = 0; i < input.length; i++)
        tmp.push(input.charAt(i))
    return tmp
}

function binary2str(input)
{
    str = ''
    for (const bit of input)
        str += bit
    return str
}