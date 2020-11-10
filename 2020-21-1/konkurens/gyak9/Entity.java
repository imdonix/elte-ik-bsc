package mmorpg;

import java.util.concurrent.CopyOnWriteArrayList;
import java.util.concurrent.atomic.AtomicInteger;

public abstract class Entity implements Runnable
{
	private final int  maxhp, dmgMin, dmgMax, waitMin, waitMax;
	private String name;
	private AtomicInteger hp;
	private Fight fight;
	
	public Entity(int hp, int dmgMin, int dmgMax, int waitMin, int waitMax)
	{
		this.name = getType() + " " +  ConcurrentRandom.nextInt(0, 10);
		this.maxhp = hp;
		this.dmgMin = dmgMin;
		this.dmgMax = dmgMax;
		this.waitMin = waitMin;
		this.waitMax = waitMax;
		this.hp = new AtomicInteger(hp);
		
	}
	
	public Entity AttachFight(Fight fight){ this.fight = fight; return this; }
	
	public int getHP() { return hp.get(); }
	
	public abstract int getDmgMultiplier();
	
	public abstract Entity getTarget();
	
	public abstract String getType();
	
	protected Entity getAlly()
	{
		CopyOnWriteArrayList<Hero> list = fight.getAllies();
		return list.get(ConcurrentRandom.nextInt(0, list.size()));
	}
	
	protected Entity getBoss()
	{
		return fight.getBoss();
	}
	
	
	@Override
	public void run() 
	{
		cooldown();
		while(!fight.isOver() && hp.get() > 0)
		{
			Entity target = getTarget();
			int dmg = ConcurrentRandom.nextInt(dmgMin, dmgMax) * getDmgMultiplier();
			
			int now = target.hp.addAndGet(dmg);
			if(now > maxhp)
				target.hp.set(maxhp);
			else if(now <= 0)
				if(target instanceof Hero)
					fight.getAllies().remove(target);
			
			System.out.println( target.name +  " | taken " + dmg + " | now: " + now + " hp");
			
			cooldown();
		}
		
	}
	
	private void cooldown() 
	{
		try { Thread.sleep(ConcurrentRandom.nextInt(waitMin, waitMax)); }
		catch(InterruptedException e) {}
	}
	
	
}
