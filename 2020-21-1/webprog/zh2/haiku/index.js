const editor = document.querySelector('#haiku-editor')
const numofchar = document.querySelector('#number-of-characters')
const numofrows = document.querySelector('#number-of-rows')
const numofvovels = document.querySelector('#vowels-per-row')
const haikus = document.querySelector('#haikus')
const button = document.querySelector('#btn-copy-haiku');

const mh = "aáeéiíoóöőuúüű".split('');


function countVowels(str)
{
    return str.split('').filter(c => mh.includes(c)).length;
}

function createList(arr)
{
    let vow = new Array();
    numofvovels.innerHTML = "";   
    arr.forEach(str =>
        {
            let li = document.createElement('li');
            let count = countVowels(str);
            vow.push(count);
            li.innerHTML = count;
            numofvovels.appendChild(li);
        })
    return vow;
}

editor.addEventListener('input', e => 
{
    let data = e.target.value;
    let lines = data.split('\n');
    
    //b
    console.log(data);

    //c
    numofchar.innerHTML = data.split('').filter(c => c != ' ' && c != '\n').length

    //d
    numofrows.innerHTML = lines.length - 1

    //e
    console.log(countVowels(lines[0]))

    //f
    let vows = createList(lines);

    //g
    console.log(vows);
    let need = vows.length == 3;
    if(need) need = vows[0] == 5 && vows[1] == 7 && vows[2] == 5;
    editor.parentElement.classList.toggle('haiku', need)



})

button.addEventListener('click', e =>
{
    //h
    let pre = document.createElement('pre');
    pre.innerHTML = editor.value
    haikus.appendChild(pre)
})