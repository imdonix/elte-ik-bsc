// TŰRI ERIK - Webprogramozás
// 7. gyakorló feladatsor megoldásai
// 1. FELADAT

const canvas = document.querySelector("canvas");
const ctx = canvas.getContext("2d");

let flappy = {
    x: 50,
    y: canvas.height / 2,
    width: 30,
    height: 20,
    vy: 0,
    ay: 200
};

let pipes = [];
const PIPE_GAP   = 150;
const PIPE_DIST  = 300;
const PIPE_SPEED = -200;

let lastFrame = performance.now();
let dead = false;
let passed = 0;

function gameLoop(){
    let now = performance.now();
    let dt = (now - lastFrame) / 1000;
    lastFrame = now;
    update(dt);
    render();
    if (!dead) requestAnimationFrame(gameLoop);
}

function update(dt){
    flappy.vy += flappy.ay * dt;
    flappy.y  += flappy.vy * dt;
    if (flappy.y < 0) flappy.y = 0;
    if (flappy.y > canvas.height) dead = true;
    if (pipes[pipes.length - 1].x < canvas.width - PIPE_DIST) newPipe();
    pipes.forEach(function(pipe){
        let before = pipe.x;
        pipe.x += PIPE_SPEED * dt;
        if (before > 50 && pipe.x < 50) passed += 0.5; 
        if (collision(pipe, flappy)) dead = true;
    });
    pipes = pipes.filter(pipe => pipe.x + pipe.width > 0);
}

function collision(a, b) {
    return !(b.y + b.height  < a.y || a.x + a.width < b.x || a.y + a.height  < b.y || b.x + b.width < a.x);
}

function random(a, b) {
    return Math.floor(Math.random() * (b - a + 1)) + a;
}

function newPipe(){
    let h = random(10, canvas.height / 2);
    pipes.push(
        {
            x: canvas.width,
            y: 0,
            width: 30,
            height: h
        },
        {
            x: canvas.width,
            y: h + PIPE_GAP,
            width: 30,
            height: canvas.height - (PIPE_GAP + h)
        }
    );
}

function render(){
    ctx.fillStyle = "lightblue";
    ctx.fillRect(0, 0, canvas.width, canvas.height);
    ctx.fillStyle = "brown";
    ctx.fillRect(flappy.x, flappy.y, flappy.width, flappy.height);
    ctx.fillStyle = "white";
    pipes.forEach(function(pipe){
        ctx.fillRect(pipe.x, pipe.y, pipe.width, pipe.height);
    })
    ctx.fillStyle = "black";
    ctx.fillText(passed, 0, 20);
}

function handleDocumentKeyDown(e){
    if (e.code == "Space") flappy.vy = -200;
}

document.addEventListener("keydown", handleDocumentKeyDown);
ctx.font = "20px sans-serif";
newPipe();
gameLoop();
