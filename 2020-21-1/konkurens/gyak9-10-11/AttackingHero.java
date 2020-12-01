package mmorpg;

public class AttackingHero extends Hero
{
	public AttackingHero() { super(120, 5, 20, 1300, 1500);}

	@Override
	public int getDmgMultiplier() { return -1; }

	@Override
	public Entity getTarget() { return getBoss(); }
	
	@Override
	public String getType() { return "Attacker"; }
}
