class Kangaroo
{
	String name;
	int age;
	
	public static void main(String[] args)
	{
		Kangaroo k = new Kangaroo("Aladar", 5);
		k.display("Magyarorszag");
	}
	
	Kangaroo(String name, int age)
	{
		this.name = name;
		this.age = age;
	}
	
	Kangaroo(int legs)
	{
		System.out.println("A kengurunak " + legs 
		+ " lába van");
	}
	
	void display(String country)
	{
		System.out.println(name + " kenguru " 
		+ age++ + " eves, " + country + " lakik");
		System.out.println("uj eletkora: " + age);
	}
}