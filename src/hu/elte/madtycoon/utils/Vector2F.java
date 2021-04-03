package hu.elte.madtycoon.utils;

public class Vector2F
{

    public static float E = 0.0025F;

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

    public Vector2F min(Vector2F right)
    {
        return new Vector2F(x - right.x, y - right.y);
    }

    public Vector2F mul(float s)
    {
        return new Vector2F(x*s,y*s);
    }

    public float length()
    {
        return (float) Math.sqrt(x*x + y*y);
    }

    public Vector2F normalized()
    {
        float l = length();
        return new Vector2F(x/l,y/l);
    }

    public float distance(Vector2F target)
    {
        return (float) Math.sqrt(Math.pow(x - target.x,2)+Math.pow(y - target.y,2));
    }

    public boolean getAnimDirection()
    {
        if(x > 0)
            return true;
        else
            return false;
    }

    @Override
    public boolean equals(Object obj) {
        if(obj instanceof Vector2F)
            return distance((Vector2F) obj) < E;
        else
            return false;
    }

    @Override
    public String toString()
    {
        return String.format("(%f, %f)", x,y);
    }

    public static Vector2F UP = new Vector2F(0,-1);

    public static Vector2F DOWN = new Vector2F(0,1);

    public static Vector2F LEFT = new Vector2F(1,0);

    public static Vector2F RIGHT = new Vector2F(-1,0);

    public static Vector2F ZERO = new Vector2F(0,0);

    public static Vector2F ONE = new Vector2F(1,1);

}
