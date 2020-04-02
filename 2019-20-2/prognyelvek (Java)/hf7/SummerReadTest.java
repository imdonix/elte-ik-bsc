import static org.junit.Assert.assertEquals;
import static org.junit.Assert.assertTrue;
import static org.junit.Assert.fail;
import org.junit.Test;
import java.util.NoSuchElementException;

public class SummerReadTest
{
	@Test
	public void testOne()
	{
		assertEquals("4 5 9 5 2", Summer.readLines("be1.txt")[0]);
	}
	
	@Test
	public void testTow()
	{
		assertEquals("5 5 5 5 5 5", Summer.readLines("be2.txt")[0]);
	}
	
	@Test
	public void testThird()
	{
		assertEquals("3 8 4", Summer.readLines("be3.txt")[0]);
	}
}