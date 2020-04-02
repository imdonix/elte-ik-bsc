import java.util.NoSuchElementException;

class IntStack
{
	int[] x;
	int i;	
	
	IntStack(int n)
	{
		x = new int[n];
		i = 0;
	}
	
	void push(int c)
	{
		x[i++] = c;
	}
	
	int pop()
	{
        if(isEmpty())
            throw new NoSuchElementException();
		return x[--i];
	}
	
	boolean isEmpty()
	{
		return i == 0;
	}

    int size()
    {
        return x.length;
    }
}