

import org.junit.Test;
import static org.junit.Assert.assertEquals;


public class MathUtilsTest
{
    public static final double EPSILON = 0.01;

    @Test
    public void testPosRaisedToPos()
    {
        assertEquals(8, MathUtils.power(2, 3), EPSILON);
    }

    @Test
    public void testPosRaisedToZero()
    {
        assertEquals(1, MathUtils.power(2, 0), EPSILON);
    }

    @Test
    public void testZeroRaisedToPos()
    {
        assertEquals(0, MathUtils.power(0, 3), EPSILON);
    }

    @Test
    public void testOneRaisedToPos()
    {
        assertEquals(1, MathUtils.power(1, 313212), EPSILON);
    }

    @Test
    public void testZeroRaisedToZero()
    {
        assertEquals(1, MathUtils.power(0, 0), EPSILON);
    }

    @Test
    public void testPosRaisedToNeg()
    {
        assertEquals(0.25, MathUtils.power(2, -2), EPSILON);
    }

    @Test(expected = IllegalArgumentException.class)
    public void testZeroRaisedToNeg()
    {
        MathUtils.power(0, -3);
    }
}


