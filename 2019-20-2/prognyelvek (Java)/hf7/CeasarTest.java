import static org.junit.Assert.assertEquals;
import static org.junit.Assert.assertTrue;
import static org.junit.Assert.fail;
import org.junit.Test;
import java.util.NoSuchElementException;

public class CeasarTest
{
	@Test
    public void simplechip1()
    {
        Ceasar c = Ceasar.Create(2);
		assertTrue(c.decipher(c.chiper("abc")).equals("abc"));
    }
	
	@Test
    public void simplechip2()
    {
        Ceasar c = Ceasar.Create(2);
		assertTrue(c.decipher(c.chiper("fadsfas")).equals("fadsfas"));
    }
	
	@Test
    public void simplechip3()
    {
        Ceasar c = Ceasar.Create(2);
		assertTrue(c.decipher(c.chiper("asdfhskidoljkn")).equals("asdfhskidoljkn"));
    }
	
	@Test
    public void simplechip4()
    {
        Ceasar c = Ceasar.Create(1);
		assertTrue(c.decipher(c.chiper("fshjfdknx")).equals("fshjfdknx"));
    }
	
	@Test
    public void simplechip5()
    {
        Ceasar c = Ceasar.Create(4);
		assertTrue(c.decipher(c.chiper("hellovilag")).equals("hellovilag"));
    }
	
	
}