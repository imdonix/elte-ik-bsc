class Main
{
	public static void main(String[] args)
	{
		Bartender pultos = new Bartender();
		
		Beverage pia  = new Beverage("Nem szabad",18);
		
		Adult jo = new Adult("Tamás",20);
		
		Minor nemjo = new Minor("MEsi",23);
		
		System.out.println(pultos.order(pia,felnott));
		
		System.out.println(pultos.order(pia,nemjo));
		
		try { Adult notadult = new Adult("Jani",17); }
		catch(IllegalArgumentException e){ System.out.println("Jani nem mult el 18."); }
	}
}