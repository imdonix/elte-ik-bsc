

abstract class Book
{
    private String author, title;
    protected int pages;

    public Book()
    {
        this.author = "John Steinbeck";
        this.title = "Of Mice and Men";
        this.pages = 107;
    }

    public Book(String author, String title, int pages)
    {
        if (author.length() < 2 || title.length() < 4)
        {
            throw new IllegalArgumentException();
        }

        this.author = author;
        this.title = title;
        this.pages = pages;
    }

    public String getShortName()
    {
        return author.substring(0, 1) + ": " + title.substring(0, 3) + "; " + pages;
    }

    public String toString()
    {
        return author + ": " + title + ", pages: " + pages;
    }

    abstract public int getPrice();
    abstract public String createReference(String article, int from, int to);
}

enum CoverType
{
    Softcover,
    Hardcover;
}

class PrintedBook extends Book
{
    protected CoverType cover;

    public PrintedBook()
    {
        this.pages += 6;
        this.cover = CoverType.Hardcover;
    }

    public PrintedBook(String author, String title, int pages, CoverType cover)
    {
        super(author, title, pages + 6);
        this.cover = cover;
    }

    @Override
    public int getPrice()
    {
        if (cover == CoverType.Softcover)
        {
            return pages * 2;
        }
        else
        {
            return pages * 3;
        }
    }

    @Override
    public String toString()
    {
        if (cover == CoverType.Softcover)
        {
            return super.toString() + " (softcover)";
        }
        else
        {
            return super.toString() + " (hardcover)";
        }
    }

    @Override
    public String createReference(String article, int from, int to)
    {
        return super.toString() + " [" + from + "-" + to + "] referenced in article: " + article;
    }
}

class EBook extends Book
{
    protected int PDFSize;

    public EBook(String author, String title, int pages, int PDFSize)
    {
        super(author, title, pages);
        this.PDFSize = PDFSize;
    }

    @Override
    public int getPrice()
    {
        return pages + PDFSize;
    }

    @Override
    public String createReference(String article, int from, int to)
    {
        return super.toString() + " (PDF size: " + PDFSize + ") [" + from + "-" + to + "] referenced in article: " + article;
    }

    public String createReference(String article, String date)
    {
        return super.toString() + " (PDF size: " + PDFSize + ") referenced in article: " + article + ", accessing PDF date: " + date;
    }
}


class Main
{
    public static void main(String[] args)
    {
		//Book book00 = new Book();
        Book pbook = new PrintedBook("author", "Printed: Title", 100, CoverType.Softcover);
        System.out.println(pbook);
        System.out.println(" price = " + pbook.getPrice());
        EBook ebook = new EBook("author2", "Digitalised: Title", 100, 12);
        System.out.println(ebook);
        System.out.println(" price = " + ebook.getPrice());

        System.out.println();

        System.out.println(pbook.createReference("articlename", 10, 20));
        System.out.println(ebook.createReference("articlename", "2020/04/11"));
        System.out.println(ebook.createReference("articlename", 10, 20));
    }
}

