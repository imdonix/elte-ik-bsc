// TŰRI ERIK - Webprogramozás
// 7. gyakorló feladatsor megoldásai
// 2. feladat

const inputPlace = document.querySelector("#place");
const findButton = document.querySelector("#find");
const inputLat = document.querySelector("#lat");
const inputLon = document.querySelector("#lon");
const weatherButton = document.querySelector("#weather");
const outputSpan = document.querySelector("span");
const table = document.querySelector("table");

function handleFindButtonClick(){
    let xhr = new XMLHttpRequest();
    xhr.addEventListener("load", onLoad);
    xhr.open("GET", "https://nominatim.openstreetmap.org/search?city=" + inputPlace.value + "&format=json");
    xhr.responseType = "json";
    xhr.send(null);
}

function onLoad(){
    if (this.response.length > 0){
        inputLat.value = this.response[0].lat;
        inputLon.value = this.response[0].lon;
    } else {
        inputLat.value = "";
        inputLon.value = "";
    }
}

const apiKey = ""; // !!!!! HIÁNYZIK !!!!!

async function handleWeatherButtonClick(){
    let response = await fetch("https://api.openweathermap.org/data/2.5/onecall?lat="+ inputLat.value + "&lon="+ inputLon.value +"&appid=" + apiKey);
    let data = await response.json();
    outputSpan.innerHTML = "Hőmérséklet: " + Math.round((data.current.temp - 273.15) * 100) / 100 + " °C <br>Nyomás: "+ data.current.pressure + " mbar";
    document.querySelectorAll("tr").forEach(tr => table.removeChild(tr));
    data.hourly.slice(0, 10).forEach(function(hour){
        let tr = document.createElement("tr");
        let td1 = document.createElement("td");
        let date = new Date(hour.dt * 1000);
        td1.innerText = date.getHours() + "h";
        tr.appendChild(td1);
        let td2 = document.createElement("td");
        td2.innerHTML = Math.round((hour.temp - 273.15) * 100) / 100 + " °C";
        tr.appendChild(td2);
        table.appendChild(tr);
    })
}

findButton.addEventListener("click", handleFindButtonClick);
weatherButton.addEventListener("click", handleWeatherButtonClick);
