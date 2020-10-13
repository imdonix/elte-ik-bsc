// TŰRI ERIK - Webprogramozás
// 6. gyakorló feladatsor megoldásai
// 2. FELADAT

const canvas = document.querySelector("canvas");
const ctx = canvas.getContext("2d");

let turtle = {
    x: canvas.width / 2,
    y: canvas.height / 2,
    phi: 0
};

function forward(ds){
    ctx.beginPath();
    ctx.moveTo(turtle.x, turtle.y);
    turtle.x += Math.sin(turtle.phi * Math.PI / 180) * ds;
    turtle.y -= Math.cos(turtle.phi * Math.PI / 180) * ds;
    ctx.lineTo(turtle.x, turtle.y);
    ctx.stroke();
}

function right(dphi){
    turtle.phi += dphi;
}

function polygon(n, a){
    for (let i = 0; i < n; i++){
        forward(a);
        right(360/n);
    }
}

ctx.lineWidth = 2;
polygon(8, 70);
