// TŰRI ERIK - Webprogramozás
// 6. gyakorló feladatsor megoldásai
// 1. FELADAT

const canvas = document.querySelector("canvas");
const ctx = canvas.getContext("2d");

// háromszög
ctx.fillStyle = "yellow";
ctx.strokeStyle = "blue";
ctx.beginPath();
ctx.moveTo(20, 200);
ctx.lineTo(20, 20);
ctx.lineTo(200, 200);
ctx.closePath(); // = ctx.lineTo(20, 200);
ctx.stroke();
ctx.fill();

// narancs töltött téglalap
ctx.fillStyle = "orange";
ctx.fillRect(200, 150, 150, 150);

// lila üres téglalap
ctx.lineWidth = 4;
ctx.strokeStyle = "purple";
ctx.strokeRect(220, 50, 200, 200);

// zöld kör
ctx.beginPath();
ctx.fillStyle = "green";
ctx.strokeStyle = "red";
ctx.lineWidth = 2;
ctx.arc(200, 170, 100, 0, 2*Math.PI);
ctx.fill();
ctx.stroke();

// szöveg
ctx.fillStyle = "gray";
ctx.strokeStyle = "black";
ctx.font = "60px sans-serif"
ctx.fillText("Szia!", 130, 190);
ctx.strokeText("Szia!", 130, 190);
