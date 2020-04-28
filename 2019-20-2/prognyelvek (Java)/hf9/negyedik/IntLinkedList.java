import java.util.*;

class IntLinkedList
{
	public LinkedList<Integer> storage;
	
	public IntLinkedList()
	{
		storage=new LinkedList<Integer>();
	}
	
	public IntLinkedList(int[] storage)
	{
		this.storage=new LinkedList<Integer>();
		for(int i=0;i<storage.length;i++)
			this.storage.add(storage[i]);
	}
	
	public void concat(IntLinkedList other)
	{
		for(int num : other.storage)
			this.storage.add(num);
	}
	
	public void add(int number)
	{
		storage.add(number);
	}
	
		public void RemoveItemsGreaterThan(int limit)
	{
		for(int i=0;i<storage.size();i++)
			if(storage.get(i)>limit) storage.remove(i);
	}
	
	public String toString()
	{
		if(storage.isEmpty()) return "empty";
		StringBuilder builer=new StringBuilder();
		builer.append(storage.get(0));
		for(int i=1;i<storage.size();i++)
			builer.append(","+storage.get(i));
		return builer.toString();
		}
	}
	

}