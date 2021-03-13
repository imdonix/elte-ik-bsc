package hu.elte.madtycoon.utils;

public class Vector2F
{
    public final float x;
    public final float y;

    public Vector2F(float x, float y)
    {
        this.x = x;
        this.y = y;
    }

    public Vector2F()
    {
        this(0,0);
    }

    public Vector2F(Vector2I v)
    {
        this((float) v.x, (float) v.y);
    }

    public Vector2F add(Vector2F right)
    {
        return new Vector2F(x + right.x, y + right.y);
    }

    public Vector2F mul(float s)
    {
        return new Vector2F(x*s,y*s);
    }

    public float distance(Vector2F target)
    {
        return (float) Math.sqrt(Math.pow(x - target.x,2)+Math.pow(y - target.y,2));
    }

}
