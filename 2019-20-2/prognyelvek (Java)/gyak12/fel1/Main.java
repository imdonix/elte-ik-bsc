import java.util.ArrayList;
import java.util.Collections;

class Point implements Comparable<Point>
{
    private int x, y;

    public Point(int x, int y)
    {
        this.x = x;
        this.y = y;
    }

    @Override
    public String toString()
    {
        return "(" + x + "," + y + ")";
    }

    // ez teljes rendezés
    /*
    @Override
    public int compareTo(Point that)
    {
        if (this.x < that.x)
            return -1;
        else if (this.x == that.x)
        {
            if (this.y < that.y)
                return -1;
            else if (this.y == that.y)
                return 0;
            else
                return 1;
        }
        else
            return 1;
    }
    */

    @Override
    public int compareTo(Point that)
    {
        int xCompareResult = Integer.compare(this.x, that.x);

        if (xCompareResult == 0)
        {
            return Integer.compare(this.y, that.y);
        }
        else return xCompareResult;
    }

    // ez nem rendezés
    /*
    @Override
    public int compareTo(Point that)
    {
        if (this.x + that.x < this.y + that.y)
            return -1;
        else if (this.x + that.x == this.y + that.y)
            return 0;
        else return 1;
    }
    */
}

class Main
{
    public static void main(String[] args)
    {
        /*
        ArrayList<Integer> list = new ArrayList<Integer>();
        list.add(2);
        list.add(-2);
        list.add(10);
        */
		
        ArrayList<Point> list = new ArrayList<Point>();
        list.add(new Point(1, 2));
        list.add(new Point(4, 6));
        list.add(new Point(4, -3));
        list.add(new Point(4, 2));
        list.add(new Point(4, 5));
        list.add(new Point(2, 7));
        list.add(new Point(2, 6));
		
		
        System.out.println(list);
        Collections.sort(list);
        System.out.println(list);
    }
}
