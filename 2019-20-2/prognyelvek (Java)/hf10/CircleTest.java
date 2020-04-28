import static org.junit.Assert.assertEquals;
import static org.junit.Assert.assertTrue;
import static org.junit.Assert.fail;
import org.junit.Test;

class CircleTest
{
	@Test
    public void eqTestGood()
    {
        Circle c1 =  new Circle(1,1,3);
		Circle c2 =  new Circle(2,2,3);
		assertTrue(c1.equals(c2));
    }
	
	@Test
    public void eqTestBad()
    {
        Circle c1 =  new Circle(1,1,3);
		Circle c3 =  new Circle(3,3,4);
		assertTrue(!c1.equals(c3));
    }
	
	@Test
    public void hashTest()
    {
        Circle c1 =  new Circle(1,1,3);
		Circle c2 =  new Circle(2,2,3);
		assertTrue(c1.hashCode() == c2.hashCode());
    }
}