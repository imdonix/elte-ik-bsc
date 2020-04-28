class MinorGuest extends Guest
{
	public MinorGuest(String name,int age)
	{
		super(name,age);
		if(age >= 18)
			throw new IllegalArgumentException();
	}
}