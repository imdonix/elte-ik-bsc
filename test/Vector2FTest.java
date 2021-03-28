import hu.elte.madtycoon.utils.Vector2F;
import org.junit.Test;

import static org.junit.Assert.assertEquals;

public class Vector2FTest
{

    public static float E = 0.005F;

    @Test
    public void create()
    {
        Vector2F v = new Vector2F(1,2);
        assertEquals(v.x,1, E);
        assertEquals(v.y, 2, E);
    }

    @Test
    public void createParameterless()
    {
        Vector2F v = new Vector2F();
        assertEquals(v.x,0, E);
        assertEquals(v.y, 0, E);
    }

    @Test
    public void equals()
    {
        Vector2F v = new Vector2F(2,2);
        Vector2F m = new Vector2F(2,2);
        assertEquals(m, v);
    }

    @Test
    public void add()
    {
        Vector2F v = new Vector2F(1,1);
        assertEquals(v.add(v), new Vector2F(2,2));
    }

    @Test
    public void mul()
    {
        Vector2F v = new Vector2F(2,4);
        Vector2F m = v.mul(5);
        assertEquals(m, new Vector2F(10, 20));
    }

    @Test
    public void div()
    {
        Vector2F v = new Vector2F(2,4);
        Vector2F m = v.mul(1/2F);
        assertEquals(m, new Vector2F(1, 2));
    }

    @Test
    public void distance()
    {
        Vector2F v = new Vector2F(0,1);
        Vector2F u = new Vector2F(0,2);
        assertEquals(v.distance(u), 1, E);
    }

    @Test
    public void normalized()
    {
        Vector2F v = new Vector2F(0,5);
        assertEquals(v.normalized(), new Vector2F(0,1));
    }

    @Test
    public void min()
    {
        Vector2F v = new Vector2F(0,5);
        Vector2F u = new Vector2F(0,5);
        assertEquals(v.min(u), new Vector2F());
    }

}
