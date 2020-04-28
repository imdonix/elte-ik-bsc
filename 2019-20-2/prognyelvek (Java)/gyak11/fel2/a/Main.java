


interface Reversable
{
    void reverse();
}

class ReversablePoint implements Reversable
{
    private int x, y;
    private int prev_x, prev_y;

    public ReversablePoint(int x, int y)
    {
        prev_x = this.x = x;
        prev_y = this.y = y;
    }

    public void setX(int x)
    {
        prev_x = this.x;
        this.x = x;
    }

    public void setY(int y)
    {
        prev_y = this.y;
        this.y = y;
    }

    public int getX() { return x; }
    public int getY() { return y; }

    public void reverse()
    {
        x = prev_x;
        y = prev_y;
    }
}

interface Printable
{
    void print();
}

class PrintablePoint implements Printable
{
    private int x, y;

    public PrintablePoint(int x, int y)
    {
        this.x = x;
        this.y = y;
    }

    public void print()
    {
        System.out.println("(" + x + "," + y + ")");
    }
}

class Book implements Printable
{
    private String author, title;

    public Book(String author, String title)
    {
        this.author = author;
        this.title = title;
    }

    public void print()
    {
        System.out.println(author + ": " + title);
    }
}

class PrintableAndReverseablePoint implements Printable, Reversable
{
    private int x, y;
    private int prev_x, prev_y;

    public PrintableAndReverseablePoint(int x, int y)
    {
        prev_x = this.x = x;
        prev_y = this.y = y;
    }

    public void print()
    {
        System.out.println("(" + x + "," + y + ")");
    }

    public void setX(int x)
    {
        prev_x = this.x;
        this.x = x;
    }

    public void setY(int y)
    {
        prev_y = this.y;
        this.y = y;
    }

    public int getX() { return x; }
    public int getY() { return y; }

    public void reverse()
    {
        x = prev_x;
        y = prev_y;
    }
}


class Main
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

        foo(new Book("author", "title"));
        foo(new PrintablePoint(2, 2));
        foo(p2);
		
		
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
    }
}
