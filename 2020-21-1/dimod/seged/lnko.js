const print = (x,y) => console.log(`${y} = ${Math.floor(y/x)} * ${x} + ${y%x}`);

let x = parseInt(process.argv[2]);
let y = parseInt(process.argv[3]);

if(x > y)
    [x,y] = [y,x]

while(y%x != 0)
{
    print(x,y);
    [x,y] = [y%x, x];
}

print(x,y)


