class Bartender
{
	public boolean order(Beverage ital,Guest vendeg)
	{
		return (ital.getLegalAge() == 18 && !(vendeg instanceof Adult))
	}
}