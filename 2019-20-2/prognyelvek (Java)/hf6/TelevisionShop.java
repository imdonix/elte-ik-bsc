import java.lang.*;
public enum TelevisionShop
{
	SAMSUNG(5, 15, 20),
	LG(50, 18, 20),
	SKYWORTH(80, 10, 24),
	SONY(75, 15, 20),
	SHARP(2, 15, 17);
	
	
	private final int db,minDiameter,maxDiameter;
	TelevisionShop(int db, int minDiameter, int maxDiameter)
	{
		this.db = db;
		this.minDiameter = minDiameter;
		this.maxDiameter = maxDiameter;
	}	
	
	public static void WriteMinMaxDiameter()
	{	
		int min = SAMSUNG.minDiameter;
		int max = SAMSUNG.maxDiameter;
		for(TelevisionShop ts : values())
		{min = Math.min(min, ts.minDiameter); max = Math.max(max, ts.maxDiameter);}
		System.out.println("A legkisebb meret: " + min + ", a legnagyobb: " + max);
	}
	
	public static void WriteMinMaxDiameter(TelevisionShop ts)
	{	
		System.out.println("A " + ts.name() + " markabol legkisebb meret: " + ts.minDiameter + ", a legnagyobb: " + ts.maxDiameter);
	}
	
	public static void WriteAll()
	{
		for(TelevisionShop ts : values())
			System.out.println( ts.name() + "|" + ts.db + "db|" + ts.minDiameter + "|" + ts.maxDiameter);
	}
}