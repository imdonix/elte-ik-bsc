const list = document.querySelector('#todos')


delegate(list ,'click', 'li', e =>
{
    if(e.target.parentNode.tagName == 'UL')
    {
        let el = e.target;

        if(el.classList.contains('done'))
            while (el) 
            {
                el.classList.toggle('done', false)
                el = el.nextElementSibling;
                e.target.parentNode.parentNode.classList.toggle('done', false);
            }
        else
            while (el) 
            {
                el.classList.toggle('done', true)
                el = el.previousElementSibling;
            }
        
        if(e.target.nextElementSibling == null)
            e.target.parentNode.parentNode.classList.toggle('done', e.target.classList.contains('done'));  
                     
    }
})


function delegate(parent, type, selector, fn) 
{
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