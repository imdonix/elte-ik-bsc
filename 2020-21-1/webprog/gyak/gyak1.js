console.log("Loaded")

function lnko(a,b)
{
    if(a<b) 
        [a,b] = [b,a];

    let maradek = a % b;
    while (maradek > 0)
    {
        a = b;
        b = maradek;
        maradek = a % b;
    }
    return b;
}


function sec()
{
    let arr = [1,2,3,4,5]
    console.log(arr.map(x => x*x*x));    
}

function third()
{
    let arr = [1,2,3,4,5]
    console.log(arr.map(x => x + arr.length));  
}

function fourth()
{
    let arr = [1,2,3,4,5,2,2]
    console.log(arr.reduce((acc, x) => acc += x % 2 === 0 ? 1 : 0, 0));  
}

function fifth()
{
    let arr = [1,2,3,4,5,2,2]
    console.log(arr.reduce((acc, x) => acc += x, 0));  
}

function sixth()
{
    let arr = [1,2,3,4,5,2,2,85]
    console.log(arr.reduce((acc, x) => acc = x > acc ? x : acc, arr[0]));
}

function seventh()
{
    let arr = [1,2,3,4,5,2,2,85,4]
    console.log(arr.filter(x => x < 0).length > 0);
    console.log(arr.reduce((acc, x) => acc = x < 0 || acc, false));
    console.log(arr.map(x => x < 0).reduce((acc,x) => acc = acc || x, false));
}

function eighth()
{
    let matrix = [[2,2,2],[2,2,2],[2,2,1]]
    console.log(matrix.reduce((acc, x) => acc.concat(x),[]).reduce((acc, x) => acc = acc && (x % 2 == 0), true))
}

//nine
students = 
[
    {name : "Elte Mető", neptun : "F3S5K2", grade : 2.04},
    {name : "Hát Izsák", neptun : "K91FFG", grade : 4.37},
    {name : "Pál Inka ", neptun : "UWU431", grade : 5.00}
]

function myfindworst()
{
    return students.reduce((acc, x) => acc = acc.grade > x.grade ? x : acc, students[0]);
}

function tenth()
{
    console.log(myfindworst().grade)
}

function eleven()
{
    console.log(myfindworst())
}

function twelve()
{
    console.log(students.reduce((acc, x) => acc += (x.grade / students.length), 0));
}