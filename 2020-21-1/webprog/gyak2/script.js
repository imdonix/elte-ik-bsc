const greetButton = document.querySelector("#greet");
const greetOutput = document.querySelector("#output");

greetButton.addEventListener("click", () =>
{
    greetButton.style.display = "none";
    greetOutput.innerHTML = "Hello!";
})

const url = document.querySelector("#url");
const submit = document.querySelector("#submit");
const dest = document.querySelector("#dest");

submit.addEventListener("click", () =>
{
    dest.src = url.value;
})

const links = document.querySelector("#links");

window.addEventListener("load", () =>
{
    console.log("sad")
    document.querySelectorAll("a").forEach(x => 
        {
            let elem = document.createElement("LI");
            elem.innerText = x.href;
            links.appendChild(elem);
        })

})

const female = document.querySelector("#female");
const male = document.querySelector("#male");
const nameinput = document.querySelector("#nameinput");

female.addEventListener("click", handleChange)
male.addEventListener("click", handleChange)
window.addEventListener("load", handleChange)

function handleChange()
{
    nameinput.style.display = female.checked ? "block" : "none";
}

const bar = document.querySelector("#bar");
const disp = document.querySelector("#disp");

bar.addEventListener("change", () =>
{
    console.log(bar.value);
    disp.style.left = bar.value + "%";
    disp.innerText = bar.value + "%";
})

bar.value = 0;