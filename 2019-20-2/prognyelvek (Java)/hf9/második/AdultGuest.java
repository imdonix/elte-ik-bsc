class AdultGuest extends Guest
{
	public AdultGuest(String name,int age)
	{
		super(name,age);
		if(age < 18)
			throw new IllegalArgumentException();
	}
}