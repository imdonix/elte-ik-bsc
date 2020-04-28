class ndIntList extends IntLinkedList
{
	public String n;
	
	public ndIntList(String n)
	{
		super();
		this.n=n;
	}
	
	public ndIntList(int[] numbers,String n)
	{
		super(numbers);
		this.n=n;
	}
	
	public String toString()
	{
		return n + ": " + super.toString();
	}
}