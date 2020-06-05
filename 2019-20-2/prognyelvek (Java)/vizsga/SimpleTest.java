import static org.junit.Assert.*;
import org.junit.Test;

import game.utils.*;
import game.vehicles.*;
import game.Player;

public class SimpleTest
{
    @Test(expected = IllegalArgumentException.class)
    public void nameNull()
    {
        new Player(null, "192.168.0.0", 0);
    }
    
    @Test(expected = IllegalArgumentException.class)
    public void negativeMOney()
    {
        new Player("Sándor", "192.168.0.0", -1);
    }

    @Test(expected = IllegalArgumentException.class)
    public void whiteSpace()
    {
        new Player("Sándor", "192.168. 0.0", 0);
    }

    @Test
    public void money()
    {
        Player p = new Player("Sándor", "192.168.0.0", 100);
        assertEquals(p.money, 100);
    }

    @Test
    public void accelerateCar()
    {
        Car c = new Car(10, 5);
        try 
        {
            c.accelerate(10);
            c.accelerate(10);
        } catch (Exception e) {}

        assertEquals(c.getCurrentSpeed(), 10, 0.0);
    }

    @Test
    public void check()
    {
        Car c = new Car(10, 5);
        try 
        {
            c.accelerate(10);
            c.accelerate(-10);
            c.accelerate(10);
        } catch (Exception e) {}
        assertEquals(c.getCurrentSpeed(), 10, 0.0);
    }

    @Test
    public void minus()
    {
        Car c = new Car(10, 5);
        try 
        {c.accelerate(-10); assertTrue(true);
        } catch (Exception e) {assertTrue(false);}
    }

    @Test
    public void equal()
    {
        Player p1 =  new Player("Sándor", "192.168.0.0", 0);
        Player p2 = new Player("Sándor", "192.168.0.0", 0);
        assertTrue(p1.equals(p2));
    }

    @Test
    public void hash()
    {
        Player p1 =  new Player("Sándor", "192.168.0.0", 0);
        Player p2 = new Player("Sándor", "192.168.0.0", 0);
        assertEquals(p1.hashCode(), p2.hashCode());
    }
}