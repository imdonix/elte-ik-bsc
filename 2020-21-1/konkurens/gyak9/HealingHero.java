package mmorpg;

public class HealingHero extends Hero
{

	public HealingHero() { super(100, 25, 35, 1500, 2000);}

	@Override
	public int getDmgMultiplier() { return -1; }

	@Override
	public Entity getTarget() { return getAlly(); }

	@Override
	public String getType() { return "Healer"; }
}
