import hu.elte.madtycoon.utils.Vector2I;
import org.junit.Test;

import static org.junit.Assert.assertEquals;

public class Vector2ITest
{

    @Test
    public void addTest()
    {
        Vector2I v = new Vector2I(1,1);
        assertEquals(v.add(v), new Vector2I(2,2));
    }

}
