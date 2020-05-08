import java.util.Iterator;
import java.util.ArrayList;
import java.util.Collections;

class ExtendedString implements Comparable<ExtendedString>, Iterable<Character>
{
    private String data;

    public ExtendedString(String data)
    {
        this.data = data;
    }

    @Override
    public String toString()
    {
        return this.data;
    }

    @Override
    public int compareTo(ExtendedString other)
    {
        return this.data.length() - other.data.length();
    }

    @Override
    public Iterator<Character> iterator()
    {
        return new ExtendedStringIterator(this.data);
    }
}

class ExtendedStringIterator implements Iterator<Character>
{
    private String stringToIterate;
    private int counter;

    public ExtendedStringIterator(String stringToIterate)
    {
        this.stringToIterate = stringToIterate;
        this.counter = 0;
    }

    @Override
    public boolean hasNext()
    {
        return this.counter < this.stringToIterate.length();
    }

    @Override
    public Character next()
    {
        return this.stringToIterate.charAt(this.counter++);
    }

    @Override
    public void remove()
    {
        this.counter++;
    }
}

class Main
{
    public static void main(String[] args)
    {
        ExtendedString temp1 = new ExtendedString("Java programming");
        ExtendedString temp2 = new ExtendedString("C++ programming");

        System.out.println("temp1.compareTo(temp2): " + temp1.compareTo(temp2));
        System.out.println("temp2.compareTo(temp1): " + temp2.compareTo(temp1));

        Iterator<Character> it = temp1.iterator();

        while (it.hasNext())
        {
            char ch = it.next();
            System.out.println("ch: " + ch);
        }

        System.out.println("-------------------------------------------------------");

        it = temp1.iterator();
        if (it.hasNext())
        {
            it.remove();
        }

        while (it.hasNext())
        {
            char ch = it.next();
            System.out.println("ch: " + ch);
        }

        ArrayList<ExtendedString> list = new ArrayList<ExtendedString>();
        list.add(new ExtendedString("This is a full sentence."));
        list.add(temp1);
        list.add(temp2);
        list.add(new ExtendedString("world"));
        list.add(new ExtendedString("hello"));
        list.add(new ExtendedString("java"));
        System.out.println(list);
        System.out.println();
        Collections.sort(list);
        System.out.println(list);
		
		
		
        System.out.println("______________________");
		for (char ch:temp1){
			System.out.print(ch+"|");
		}
		System.out.println();
		
    }
}

