import hu.elte.madtycoon.utils.Vector2F;
import org.junit.Test;

import static org.junit.Assert.assertEquals;

public class Vector2FTest
{

    public static float E = 0.005F;

    @Test
    public void addTest()
    {
        Vector2F v = new Vector2F(1,1);
        assertEquals(v.add(v).length(), new Vector2F(2,1).length(), E);
    }

}
