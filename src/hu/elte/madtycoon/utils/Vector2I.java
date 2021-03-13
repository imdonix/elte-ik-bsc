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

}
