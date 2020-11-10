package mmorpg;

public abstract class Hero extends Entity
{

	public Hero(int hp, int dmgMin, int dmgMax, int waitMin, int waitMax) 
	{
		super(hp, dmgMin, dmgMax, waitMin, waitMax);
	}
	
}
