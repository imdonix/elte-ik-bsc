let num = process.argv[2]

if(!num) return 0;

let divider = Math.pow(10, (`${num}`.length ))
console.log(divider)
let flag = false;
for(let i = 0; i < 10;)
{
    num*=2;
    let rem = Math.floor(num / divider);
    num = num % divider;
    console.log(`${rem} | ${num}`);

    if(rem == 1) flag = true;
    if(flag) i++;
}

