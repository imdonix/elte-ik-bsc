const card = document.querySelector("#card");
const icon = document.querySelector("#logo");
const buy = document.querySelector("#buy");
const amountinp = document.querySelector("#amount");
const btn = document.querySelector("#btn");
const total = document.querySelector("#total");

const endpanel = document.querySelector("#end");

let cardnumber = "";
let amount = "";
let account = 420069;

card.addEventListener('input', (e) =>
{
    if(isNumber(e.data) && cardnumber.length < 16)
        cardnumber += e.data;

    if(e.inputType == "deleteContentBackward")
        if(cardnumber.length > 0)
            cardnumber = cardnumber.substring(0,cardnumber.length-1);

    card.value = render(cardnumber);
});

amountinp.addEventListener('input', (e) =>
{
    if(isNumber(e.data))
        amount += e.data;

    if(e.inputType == "deleteContentBackward")
        if(amount.length > 0)
            amount = amount.substring(0,amount.length-1);
        

    amountinp.value = amount;
});

document.addEventListener("DOMContentLoaded", (e) => total.innerText = account + " Ft");

btn.addEventListener('click', (e) =>
{
    if(isNumber(amount))
    {
        let tmp = parseInt(amount);
        
        if(account > amount)
            location.reload();
        else
        {
            document.querySelectorAll(".main").forEach(u => u.style.display = "none");
            endpanel.style.display = "block";
        }
    }
})


function isNumber(char)
{
    return Number.isInteger(parseInt(char));
}

function render(input)
{
    let isValidByStart = false;

    if(input.length > 0)
        isValidByStart = showIcon(input[0])
    else
        showIcon(" ");

    let tmp = "";
    let c = 0;
    for (const char of input) 
    {
        if(c % 4 == 0 && c != 0)
            tmp += " ";
        tmp += char;
        c++;
    }

    let isValid = isValidByStart && input.length == 16;
    showBuyPanel(isValid);

    return tmp;
}

function showIcon(char)
{
    let src;
    switch (char) 
    {
        case "4":
            src = "visa.png";
            break;
        case "5":
            src = "master.png";
            break;
        case "6":
            src = "maestro.png";
            break;
        default:
            src = "";
            break;
    }
    icon.src = src;
    return src.length > 0;
}

function showBuyPanel(show)
{
    buy.style.display = show ? "block" : "none";
}