// TŰRI ERIK - Webprogramozás
// 3. gyakorló feladatsor megoldásai
// 2. FELADAT

const ul = document.querySelector("ul");
let firstLi = null;

function handleLiClick(e){
    if (firstLi !== null){
        let secondLi = e.delegatedTarget;
        [firstLi.innerText, secondLi.innerText] = [secondLi.innerText, firstLi.innerText];
        firstLi = null;
    } else firstLi = e.delegatedTarget;
}

delegate(ul, "click", "li", handleLiClick);

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