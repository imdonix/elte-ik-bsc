package mmorpg;

import java.util.concurrent.CopyOnWriteArrayList;

public class Fight 
{
	CopyOnWriteArrayList<Hero> allies;
	Boss boss; 
	 
	public Fight()
	{
		allies = new CopyOnWriteArrayList<Hero>();
		for(int i = 0; i < 4; i++ )
			allies.add((Hero) new AttackingHero().AttachFight(this));
		allies.add((Hero) new HealingHero().AttachFight(this));		
		boss = (Boss) new Boss().AttachFight(this);
		
		Start();		
	}

	public CopyOnWriteArrayList<Hero> getAllies() {  return allies; }
	
	public Entity getBoss() { return boss; }
	
	public boolean isOver() { return allies.size() == 0 || boss.getHP() <= 0;}
	
	public void Start()
	{
		new Thread(boss).start();
		for(Hero h : allies)
			new Thread(h).start();
	}
	
	
}
