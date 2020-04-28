public class Main
{
    public static void foo(Printable obj)
    {
        // ...
        obj.print();
    }

    public static void main(String[] args)
    {
        ReversablePoint p1 = new ReversablePoint(2, 3);
        System.out.println("x = " + p1.getX());
        p1.setX(-1000);
        System.out.println("x = " + p1.getX());
        p1.reverse();
        System.out.println("x = " + p1.getX());

        System.out.println();

        PrintableAndReverseablePoint p2 = new PrintableAndReverseablePoint(10, 20);
        p2.print();
        p2.setX(3);
        p2.print();
        p2.setX(5);
        p2.setY(5);
        p2.print();
        p2.reverse();
        p2.print();

        System.out.println();

        foo(new Book("author", "title"));
        foo(new PrintablePoint(2, 2));
        foo(p2);
    }
}
