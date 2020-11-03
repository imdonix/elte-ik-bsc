public class Bug {

	private int x, y;
	private Direction direction;

	public Bug( int x, int y, Direction direction )
	{
		this.x = x;
		this.y = y;
		this.direction = direction;
	}

	public void move()
	{
		switch( direction )
		{
			case NORTH -> --y;
			case EAST  -> ++x;
			case SOUTH -> ++y;
			case WEST  -> --x;
		}
	}

	public void turnTo( Direction direction )
	{
		this.direction = direction;
	}

	public boolean isDead()
	{
		if(x > 11 || x < 0)
			return true;
		if(y > 11 || y < 0)
			return true;
		return false;
	}
	
	@Override public String toString()
	{
		return "("+x+","+y+")";
	}
}
