import static org.junit.Assert.assertEquals;
import static org.junit.Assert.assertTrue;
import static org.junit.Assert.fail;
import org.junit.Test;
import java.util.NoSuchElementException;

public class SummerWriteTest
{
	@Test
	public void testOne()
	{
		try {Summer.writeOutLines(Summer.sumLines(Summer.readLines("be1.txt")));}
		catch(Exception e){fail();};
	}
	
	@Test
	public void testTow()
	{
		try {Summer.writeOutLines(Summer.sumLines(Summer.readLines("be2.txt")));}
		catch(Exception e){fail();};
	}
	
	@Test
	public void testThird()
	{
		try {Summer.writeOutLines(Summer.sumLines(Summer.readLines("be3.txt")));}
		catch(Exception e){fail();};
	}
}