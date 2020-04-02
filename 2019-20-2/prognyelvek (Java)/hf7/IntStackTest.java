import static org.junit.Assert.assertEquals;
import static org.junit.Assert.assertTrue;
import static org.junit.Assert.fail;
import org.junit.Test;
import java.util.NoSuchElementException;

public class IntStackTest
{
    @Test
    public void newStack()
    {
        try{IntStack is = new IntStack(1);}
        catch(Exception e){fail("nem sikerült letrehozni");}
    }

    @Test
    public void firstInLastOut()
    {
        IntStack is = new IntStack(1);
        is.push(2);
        assertTrue(2 == is.pop());
    }

    @Test
    public void notEmpty()
    {
        IntStack is = new IntStack(1);
        is.push(2);
        assertTrue(!is.isEmpty());
    }

    @Test(expected = NoSuchElementException.class)
    public void cantGetNull()
    {
        IntStack is = new IntStack(1);
        is.pop();
    }

    @Test
    public void testExtrimalNull()
    {
        IntStack is = new IntStack(0);
        assertTrue(is.size() == 0);
    }

    @Test
    public void testExtrimalOne()
    {
        IntStack is = new IntStack(1);
        assertTrue(is.size() == 1);
    }

    @Test
    public void lastOut()
    {
        IntStack is = new IntStack(1);
        is.push(2);
        is.pop();
        if(is.isEmpty());
    }

}