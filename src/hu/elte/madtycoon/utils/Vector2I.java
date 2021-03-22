package hu.elte.madtycoon.utils;

public final class Vector2I
{
    public final int x;
    public final int y;

    public Vector2I(int x, int y)
    {
        this.x = x;
        this.y = y;
    }

    public Vector2I(Vector2F v)
    {
        this((int) v.x,(int) v.y);
    }

    public Vector2I()
    {
        this(0,0);
    }

    public Vector2I add(Vector2I right)
    {
        return new Vector2I(x + right.x, y + right.y);
    }

    public Vector2I mul(int s)
    {
        return new Vector2I(x*s,y*s);
    }

    public Vector2I div(int s)
    {
        return new Vector2I(x/s,y/s);
    }

    @Override
    public String toString()
    {
        return String.format("(%o, %o)", x,y);
    }

    public static Vector2I UP = new Vector2I(0,-1);

    public static Vector2I DOWN = new Vector2I(0,1);

    public static Vector2I LEFT = new Vector2I(1,0);

    public static Vector2I RIGHT = new Vector2I(-1,0);

    public static Vector2I ZERO = new Vector2I(0,0);

    public static Vector2I ONE = new Vector2I(1,1);

}
