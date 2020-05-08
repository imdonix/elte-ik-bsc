import java.util.HashSet;
import java.util.Iterator;

class Example
{
    public static void main(String[] args)
    {
        HashSet<Integer> set = new HashSet<Integer>();

        set.add(4);
        set.add(6);
        set.add(7);
        set.add(10);

        System.out.println(set);

        /*
        for (Integer i : set)
        {
            if (i % 2 == 1)
            {
                System.out.println(i);
                set.remove(i); // ConcurrentModificationException
            }
        }
        */

        Iterator<Integer> it = set.iterator();
        while (it.hasNext())
        {
            int i = it.next();
            if (i % 2 == 1)
            {
                System.out.println(i);
                it.remove();
            }
        }

        System.out.println(set);
    }
}

