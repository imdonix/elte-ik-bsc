import hu.elte.madtycoon.utils.Vector2F;
import hu.elte.madtycoon.utils.Vector2I;
import org.junit.Test;

import static org.junit.Assert.assertEquals;

public class Vector2ITest
{

    @Test
    public void create()
    {
        Vector2I v = new Vector2I(1,2);
        assertEquals(v.x,1);
        assertEquals(v.y, 2);
    }

    @Test
    public void createParameterless()
    {
        Vector2I v = new Vector2I();
        assertEquals(v.x,0);
        assertEquals(v.y, 0);
    }

    @Test
    public void equals()
    {
        Vector2I v = new Vector2I(2,2);
        Vector2I m = new Vector2I(2,2);
        assertEquals(m, v);
    }

    @Test
    public void add()
    {
        Vector2I v = new Vector2I(1,1);
        assertEquals(v.add(v), new Vector2I(2,2));
    }

    @Test
    public void mul()
    {
        Vector2I v = new Vector2I(2,4);
        Vector2I m = v.mul(5);
        assertEquals(m, new Vector2I(10, 20));
    }

    @Test
    public void div()
    {
        Vector2I v = new Vector2I(2,4);
        Vector2I m = v.div(2);
        assertEquals(m, new Vector2I(1, 2));
    }

}
