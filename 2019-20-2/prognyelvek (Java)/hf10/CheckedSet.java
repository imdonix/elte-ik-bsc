import java.util.*;

public class CheckedSet<T>
{
	
	private HashSet<T> set;
	
	public CheckedSet()
	{ set = new HashSet<T>(); }
	
	public int size()
	{  return set.size(); }
	
	public void add(T element) throws AlreadyContainedException 
	{
		if(contains(element)) 
			throw new AlreadyContainedException("Ez az elem mar metalalhato a set-ben");
		set.add(element); 
	}
	
	public boolean contains(T element)
	{ return set.contains(element); }
	
	
	public static void main(String[] args)
	{
		CheckedSet<Circle> t = new CheckedSet<Circle>();
		try
		{
			t.add(new Circle(1,1,3));
			t.add(new Circle(2,2,3));
		}
		catch(AlreadyContainedException e){System.out.println(e.getMessage());}

		System.out.println(t.size());
	}
	
}

class AlreadyContainedException extends Exception
{
	public AlreadyContainedException(String massage)
	{
		super(massage);
	}
}