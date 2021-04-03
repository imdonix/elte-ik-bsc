import hu.elte.madtycoon.utils.MinHeap;
import org.junit.Test;

import static org.junit.Assert.assertEquals;
import static org.junit.Assert.assertTrue;

public class MinHeapTest
{
    @Test
    public void create()
    {
        MinHeap<Integer> h = new MinHeap<>(5);
        assertTrue(h.isEmpty());
    }

    @Test
    public void add()
    {
        MinHeap<Integer> h = new MinHeap<>(5);
        h.add(5);
        assertTrue(!h.isEmpty());
    }

    @Test
    public void rem()
    {
        MinHeap<Integer> h = new MinHeap<>(5);
        h.add(5);
        h.add(2);
        h.add(3);
        h.add(7);
        assertEquals(h.rem(), new Integer(2));
    }
}
