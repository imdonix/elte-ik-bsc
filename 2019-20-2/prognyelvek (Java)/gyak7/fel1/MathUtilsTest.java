
import static org.junit.Assert.*;
import org.junit.Test;

public class MathUtilsTest
{
    @Test
    public void testPositive()
    {
        int res = MathUtils.Increment(4);
        assertEquals(5, res);
    }

    @Test
    public void testNegative()
    {
        int res = MathUtils.Increment(-3);
        assertEquals(-2, res);
    }

    @Test
    public void testZero()
    {
        int res = MathUtils.Increment(0);
        assertEquals(1, res);
    }

    @Test
    public void testMaxValue1()
    {
        int res = MathUtils.Increment(Integer.MAX_VALUE);
        assertEquals(Integer.MAX_VALUE, res);
    }

    @Test
    public void testMaxValue2()
    {
        int res = MathUtils.Increment(Integer.MAX_VALUE - 1);
        assertEquals(Integer.MAX_VALUE, res);
    }
}