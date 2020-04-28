class Guest
{
	protected String name;
	protected int age;
	
	public Guest(String name,int age)
	{
		if(!name.equals("") && age>0)
		{
			this.name=name;
			this.age=age;
		}
		else throw new IllegalArgumentException();
	}
	
		
	public int getAge()
	{
		return age;
	}
	
	public String getName()
	{
		return name;
	}

}
