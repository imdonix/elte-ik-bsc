import org.junit.Test;
import org.junit.Before;
import org.junit.After;

import static org.junit.Assert.assertEquals;
import static org.junit.Assert.assertNotEquals;
import static org.junit.Assert.assertTrue;
import static org.junit.Assert.assertFalse;
import static org.junit.Assert.fail;


public class AdderTest
{
    public static final double EPSILON = 0.01;

    @Test
    public void test_Add()
    {
        int result = Integer.parseInt(Adder.add("1", "2"));
        assertEquals(3, result);
    }

    @Test
    public void test_Add_Comm()
    {
        int result1 = Integer.parseInt(Adder.add("1", "2"));
        assertEquals(3, result1);

        int result2 = Integer.parseInt(Adder.add("2", "1"));
        assertEquals(3, result2);

        result1 = Integer.parseInt(Adder.add("11", "2214125"));
        result2 = Integer.parseInt(Adder.add("2214125", "11"));
        assertTrue(result1 == result2);
    }

    @Test
    public void test_Add_Epsilon()
    {
        double result = Double.parseDouble(Adder.add("1.1", "5.7"));
        assertEquals(6.8, result, EPSILON);
        assertEquals(6.81, result, EPSILON);
    }

    @Test // ez a TC fail-el
    public void test_Add_Binary()
    {
        int result = Integer.parseInt(Adder.add("0b1100", "0b10111"));
        assertEquals(35, result);
    }
}