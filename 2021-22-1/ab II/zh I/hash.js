function hash(inputs, threshold)
{  
    threshold = parseFloat(threshold)
    const res = []
    const bins = inputs.split(',')
    .map(s => s.trim())
    .map(str2binary)
    .reverse();

    let c = 1
    let k = 0

    let buckets = [[],[]]
    
    while(bins.length > 0)
    {
        let added = false
        const next = bins.pop()

        insert(buckets, c, next)
        k++

        let fullness = k / buckets.length;
        if(fullness >= threshold)
        {
            old = buckets.flat(1)
            buckets = Array(buckets.length + 1).fill(0).map(_ => [])       
            c = binary(buckets.length-1).length
            added = true

            while(old.length > 0)
            {
                const reset = old.pop()
                insert(buckets, c, reset)
            }
        }

        let readable = buckets.map((bucket, i) => [binary2str(lbinary(i,c)), bucket.map(binary2str)])
        res.push([binary2str(next), readable, c, added])
    }

    return res
}

function insert(buckets, c, next)
{
    for (let j = 0; j < c; j++)
        for (let i = 0; i < buckets.length; i++)
            if(equals(next, lbinary(i,c), c-j))
            {
                buckets[i].push(next)
                return
            }
    throw `A number cant be inserted ${next}`
}

function equals(left, right, i)
{
    for (let j = 0; j < i; j++) 
        if(left[left.length-j-1] != right[right.length-j-1])
            return false
    return true
}   