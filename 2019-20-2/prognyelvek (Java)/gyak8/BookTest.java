import org.junit.Test;
import org.junit.Before;
import org.junit.After;

import static org.junit.Assert.assertEquals;
import static org.junit.Assert.assertNotEquals;
import static org.junit.Assert.assertTrue;
import static org.junit.Assert.assertFalse;
import static org.junit.Assert.fail;


public class BookTest
{

    @Before
    public void setUp()
    {
        Book.resetId();
    }
    @After
    public void tearDown()
    {
        Book.resetId();
    }

    @Test
    public void Book_setsParameters()
    {
        Book b1 = Book.make("abc", "def","SCIFI","10000");
        Book b2 = Book.make("abc", "def","SCIFI","10000");

        assertEquals(10000, b1.getReservePrice());
        assertEquals(10000, b2.getReservePrice());

        assertEquals(0, b1.getId());
        assertEquals(1, b2.getId());
    }

    @Test
    public void make_parsesTypes()
    {
        assertEquals(null, Book.make("abc", "def", "SCIFI","tenthousand"));
        assertEquals(null, Book.make("abc", "def","AVANTGARDE","10000"));
    }

    @Test
    public void make_checksValues()
    {
        assertEquals(null, Book.make("abc", null,"SCIFI","10000"));
        assertEquals(null, Book.make("abc", "d","SCIFI","10000"));

        assertEquals(null, Book.make("abc", "def","SCIFI","0"));
        assertEquals(null, Book.make("abc", "def","SCIFI","-1"));

        assertNotEquals(null, Book.make("abc", "def","SCIFI","10000"));
    }

    @Test
    public void compare_LessOrGreater()
    {
        Book b1 = Book.make("abc", "def","SCIFI","8000");
        Book b2 = Book.make("abc", "def","SCIFI","10000");

        assertEquals(-1, b1.compare(b2));
        assertEquals(1, b2.compare(b1));
    }

    @Test
    public void compare_Equality()
    {
        Book b1 = Book.make("abcccc", "def","SCIFI","10000");
        Book b2 = Book.make("abc", "def","SCIFI","10000");

        assertEquals(0, b1.compare(b2));
    }
}


/*
make("...", "Of mice and man###", ...) -> null
*/
