const placesInput = document.querySelector('#places')
const speciesInput = document.querySelector('#species')
const button = document.querySelector('#btn-generate')
const tableContainer = document.querySelector('#table-container')
const task1 = document.querySelector('#task-1')
const task2 = document.querySelector('#task-2')
const task3 = document.querySelector('#task-3')
const task4 = document.querySelector('#task-4')
const task5 = document.querySelector('#task-5')


let tab;
let matrix = []

button.addEventListener('click', onGenerate)
function onGenerate(e) {
  const n = placesInput.valueAsNumber
  const m = speciesInput.valueAsNumber

  matrix = generateMatrix(n, m)
  console.log(matrix);
  createTable(matrix);
}

function generateMatrix(n, m) {
  const matrix = []
  for(let i = 0; i<n; i++) {
    const row = []
    for(let j = 0; j<m; j++) {
      row.push(0)
    }
    matrix.push(row)
  }
  return matrix
}

function createTable(data) 
{
  let table = document.createElement('table');
  let tableBody = document.createElement('tbody');
  let x = 0;

  data.forEach(function(row) 
  {
    let rowe = document.createElement('tr');

    let y = 0;
    row.forEach(function(cellData) 
    {
      let cell = document.createElement('td');
      cell.appendChild(document.createTextNode(cellData));
      cell.addEventListener('click', onClick);    
      rowe.appendChild(cell);
      y++
    });

    tableBody.appendChild(rowe);
    x++;
  });

  table.appendChild(tableBody);
  tableContainer.appendChild(table);
  tab = table;
}

function onClick(e)
{
  let c = parseInt(e.target.innerHTML);
  c++;
  e.target.innerHTML = c;
  update();
}

function update()
{
  let first = false;
  let sec = 0;
  let thr = [];

  for(let x = 0, row; row = tab.rows[x]; x++ )
  {
    thr.push(true);

    for(let y = 0, col; col = row.cells[y]; y++ )
    {
      if(x == 0 && parseInt(col.innerHTML) != 0)
        first = true;

      if(parseInt(col.innerHTML) >= 10)
      {
        sec++;
        break;
      }

      if(parseInt(col.innerHTML) > 0)
        thr[x] = false;
    }
  }

  task1.innerHTML = first ? "Yes" : "No"
  task2.innerHTML = sec;

  let vl = false;

  for(let i = 0; i < thr.length && !vl ; i++ )
  {
    if(thr[i])
    {
      task3.innerHTML = i+1;
      vl = true;
    }
  }

  if(!vl)
    task3.innerHTML = "No";
  
}

