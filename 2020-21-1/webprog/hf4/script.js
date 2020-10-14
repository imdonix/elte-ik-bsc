const canvas = document.querySelector("canvas");
const ctx = canvas.getContext("2d");

let snails = [
    { x: 0, v: 10, a: 0, finish: null},
    { x: 0, v: 0 , a: 1, finish: null} 
];

let snailImage = new Image();
snailImage.src = "ship.png";

let lastFrame = performance.now();

function gameLoop(){
    let now = performance.now();
    let dt = (now - lastFrame) / 1000;
    lastFrame = now;
    update(dt);
    render();
    requestAnimationFrame(gameLoop);
}

let fps;
function update(dt){
    
    snails.forEach(function(snail){
        snail.v += snail.a * dt;
        snail.x += snail.v * dt;
        if (snail.x >= 500 && snail.finish == null)
            snail.finish = (performance.now() - startTime) / 1000;  
    });



    fps = Math.floor(1 / dt);
}

function render(){
    ctx.clearRect(0, 0, canvas.width, canvas.height);
    ctx.fillStyle = "lime";
    ctx.fillRect(500, 0, 50, canvas.height);
    ctx.fillStyle = "brown";

    snails.forEach(function(snail, i){
        // ctx.fillRect(snail.x, 50 * i, 20, 20);
        ctx.drawImage(snailImage, snail.x, 70 * i);
        if (snail.finish != null){
            ctx.fillText(snail.finish + " sec", 0, 20 + 70 * i);
        }
        i++;
    })

    ctx.fillText("FPS: " + fps, 0, canvas.height - 20);
}

let startTime = performance.now();
ctx.font = "20px sans-serif";
gameLoop();