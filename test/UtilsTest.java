import hu.elte.madtycoon.utils.Utils;
import org.junit.Test;

import static org.junit.Assert.assertEquals;

public class UtilsTest
{
    public static float E = 0.005F;

    @Test
    public void clamMin()
    {
        assertEquals( Utils.clamp(1,5,0), 1, E);
    }

    @Test
    public void clamMax()
    {
        assertEquals( Utils.clamp(1,5,6), 5, E);
    }

    @Test
    public void clamInside()
    {
        assertEquals( Utils.clamp(1,5,2), 2, E);
    }
}
