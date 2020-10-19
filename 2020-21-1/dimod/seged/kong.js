let x = parseInt(process.argv[2]);
let y = parseInt(process.argv[3]);
let z = parseInt(process.argv[4]);
let c = 0;

while((y + (z*c)) % x != 0)
    c++;

console.log(`${x}x = ${y} (${z}) | + (${z}*${c}) `)
console.log(`${x}x = ${y + (z*c)} (${z})`)
console.log(`x = ${(y + (z*c)) / x} (${z}) | / ${x}`)