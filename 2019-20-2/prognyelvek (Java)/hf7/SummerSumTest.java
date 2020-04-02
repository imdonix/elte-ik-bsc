import static org.junit.Assert.assertEquals;
import static org.junit.Assert.assertTrue;
import static org.junit.Assert.fail;
import org.junit.Test;
import java.util.NoSuchElementException;

public class SummerSumTest
{
	String[] one,two,three;
	
	@Before
	public void read()
	{
		one = Summer.readLines("be1.txt");
		two = Summer.readLines("be1.txt");
		three = Summer.readLines("be1.txt");
	}
	
	@Test
	public void testOne()
	{
		assertEquals(25, Summer.sumLines(one)[0]);
	}
	
	@Test
	public void testTow()
	{
		assertEquals(30, Summer.sumLines(two)[0]);
	}
	
	@Test
	public void testThird()
	{
		assertEquals(15, Summer.sumLines(three)[0]);
	}
}