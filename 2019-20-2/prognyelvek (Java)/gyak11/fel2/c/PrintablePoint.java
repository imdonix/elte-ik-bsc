public class PrintablePoint extends Point implements Printable
{
    public PrintablePoint(int x, int y)
    {
        super(x, y);
    }

    public void print()
    {
        System.out.println("(" + x + "," + y + ")");
    }
}