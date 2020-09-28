// TŰRI ERIK - Webprogramozás
// 3. gyakorló feladatsor megoldásai
// 5. FELADAT

const button = document.querySelector("button");
const body = document.querySelector("body");
let draggedDiv = null;

function randomBetween(a, b) {
    return Math.floor(Math.random() * (b - a + 1)) + a;
}

function handleButtonClick() {
    const div = document.createElement("div");
    body.appendChild(div);
    div.style.position = "absolute";
    div.style.left = randomBetween(0, window.innerWidth - 300) + "px";
    div.style.top = randomBetween(0, window.innerHeight - 200) + "px";
}
button.addEventListener("click", handleButtonClick);

function handleDivMouseDown(e) {
    draggedDiv = e.delegatedTarget;
    draggedDiv.style.borderColor = "yellow";
}
delegate(body, "mousedown", "div", handleDivMouseDown);

function handleDivMouseUp() {
    draggedDiv.style.borderColor = "black";
    draggedDiv = null;
}
delegate(body, "mouseup", "div", handleDivMouseUp);

function handleDivMouseMove(e) {
    if (draggedDiv !== null) {
        const top = parseInt(draggedDiv.style.top.slice(0, -2));
        const left = parseInt(draggedDiv.style.left.slice(0, -2));
        draggedDiv.style.top = top + e.movementY + "px";
        draggedDiv.style.left = left + e.movementX + "px";
    }
}
delegate(body, "mousemove", "div", handleDivMouseMove);

function delegate(parent, type, selector, fn) {
    function delegatedFunction(e) {
        if (e.target.matches(`${selector},${selector} *`)) {
            let target = e.target;
            while (!target.matches(selector)) target = target.parentNode;
            e.delegatedTarget = target;
            return fn(e);
        }
    }
    parent.addEventListener(type, delegatedFunction, false);
}