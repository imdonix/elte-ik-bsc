package mmorpg;

public class Boss extends Entity
{

	public Boss() { super(300, 30, 45, 600, 1200); }

	
	@Override
	public int getDmgMultiplier() { return -1;}


	@Override
	public Entity getTarget() { return getAlly(); }
	
	@Override
	public String getType() { return "Boss"; }

}
