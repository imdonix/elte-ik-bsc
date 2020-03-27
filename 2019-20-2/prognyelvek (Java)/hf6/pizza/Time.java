package pizza;

public class Time
{
	int sec;

	public Time(int sec)
	{
		this.sec = sec;
	}
	
	public void add(Time left)
	{
		sec+=left.sec;
	}
	
	public String toString()
	{
		return (sec/60) + ":" + (sec%60);
	}
}