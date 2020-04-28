public class Book implements Printable
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