// TŰRI ERIK - Webprogramozás
// 3. gyakorló feladatsor megoldásai
// 3. FELADAT

const table = document.querySelector("table");

function handleMouseOver(e){
    e.delegatedTarget.style.backgroundColor = "yellow";
}

function handleMouseOut(e){
    e.delegatedTarget.style.backgroundColor = "";
}

delegate(table, "mouseover", "tr", handleMouseOver);
delegate(table, "mouseout", "tr", handleMouseOut);

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