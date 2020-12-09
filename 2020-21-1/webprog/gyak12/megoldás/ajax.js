const table = document.querySelector("table");
const refresh = document.querySelector("#refresh");

async function refreshTable(){
    let resp = await fetch("table.php");
    let data = await resp.json();
    console.log(data);
    table.innerHTML = "<tr><th>Tárgykód</th><th>Tárgynév</th><th>Oktató</th><th>Kredit</th><th>Érdemjegy</th></tr>";
    Object.keys(data).forEach(function(key){
        let row = data[key];
        let tr = document.createElement("tr");
        table.appendChild(tr);
        Object.keys(row).forEach(function(field){
            if (field != "id"){
                let td = document.createElement("td");
                td.innerText = row[field];
                tr.appendChild(td);
            }
        });
    });
}

refresh.addEventListener("click", refreshTable);