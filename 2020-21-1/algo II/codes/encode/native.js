let code = process.argv[2];
let set = new Set(code);

let bit = 1;

while(powerOfTwo(bit) < set.size) bit++;

console.log(`Evry letter takes: ${bit} bit | the word takes: ${bit*code.length}`);

function powerOfTwo(n)
{
    let c = 1;
    while(n-- > 0)
        c *=2;
    return c;
}