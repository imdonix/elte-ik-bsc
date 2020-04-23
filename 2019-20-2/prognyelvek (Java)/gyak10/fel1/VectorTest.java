import static org.junit.Assert.assertTrue;
import static org.junit.Assert.assertFalse;
import org.junit.Test;

public class VectorTest
{
    @Test
    public void equalsIsReflexiv()
    {
        Vector v1 = new Vector(1, 3);
        assertTrue(v1.equals(v1));
    }

    @Test
    public void equalsIsSymmetric1()
    {
        Vector v1 = new Vector(1, 3);
        Vector v2 = new Vector(1, 3);
        if (v1.equals(v2))
        {
            assertTrue(v2.equals(v1));
        }
        if (v2.equals(v1))
        {
            assertTrue(v1.equals(v2));
        }
    }

    @Test
    public void equalsIsSymmetric2()
    {
        Vector v1 = new Vector(1, 3);
        Vector v2 = new Vector(1, 5);
        if (v1.equals(v2))
        {
            assertTrue(v2.equals(v1));
        }
        if (v2.equals(v1))
        {
            assertTrue(v1.equals(v2));
        }
    }

    @Test
    public void equalsIsTransitive1()
    {
        Vector v1 = new Vector(1, 3);
        Vector v2 = new Vector(1, 3);
        Vector v3 = new Vector(1, 3);
        if (v1.equals(v2) && v2.equals(v3))
        {
            assertTrue(v1.equals(v3));
        }
    }

    @Test
    public void equalsIsTransitive2()
    {
        Vector v1 = new Vector(1, 3);
        Vector v2 = new Vector(1, 5);
        Vector v3 = new Vector(1, 3);
        if (v1.equals(v2) && v2.equals(v3))
        {
            assertTrue(v1.equals(v3));
        }
    }

    @Test
    public void equalsWithNullParam()
    {
        Vector v = new Vector(10, 20);
        assertFalse(v.equals(null));
    }

    @Test(expected = NullPointerException.class)
    public void equalsOnNullref()
    {
        Vector v1 = new Vector(10, 20);
        Vector v2 = null;
        v2.equals(v1);
    }

    @Test
    public void equalObjHashCodeIsSame()
    {
        Vector v1 = new Vector(1, 3);
        Vector v2 = new Vector(1, 3);
        assertTrue(v1.equals(v2));
        assertTrue(v1.hashCode() == v2.hashCode());
    }
}
