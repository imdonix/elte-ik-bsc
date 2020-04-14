

class Book
{
    private String author, title;
    protected int pages;

    public String getAuthor() { return author; }

	public static void main(String[] args)
    {
        Book book1 = new Book();
        System.out.println(book1.getShortName());
        Book book2 = new Book("author", "Title", 100);
        System.out.println(book2.getShortName());

        System.out.println();

        PrintedBook pbook1 = new PrintedBook();
        System.out.println(pbook1.getShortName());
        System.out.println(" price = " + pbook1.getPrice());
        PrintedBook pbook2 = new PrintedBook("author", "Printed: Title", 100, CoverType.Softcover);
        System.out.println(pbook2.getShortName());
        System.out.println(" price = " + pbook2.getPrice());

        System.out.println();

        EBook ebook1 = new EBook("author2", "Digitalised: Title", 100, 12);
        System.out.println(ebook1.getShortName());
        System.out.println(" price = " + ebook1.getPrice());

        System.out.println();

        System.out.println(book1);
        System.out.println(pbook1);
        System.out.println(pbook2);
        System.out.println(ebook1);

        System.out.println();

        //Book book3 = new PrintedBook();
        //System.out.println("book3 price: " + book3.getPrice()); // compile error

        System.out.println(book1.createReference("articlename", 10, 20));
        System.out.println(pbook1.createReference("articlename", 10, 20));
        System.out.println(ebook1.createReference("articlename", "2020/04/11"));
        System.out.println(ebook1.createReference("articlename", 10, 20));

        System.out.println();

        System.out.println(Book.isSameAuthor(book1, book2));
        System.out.println(Book.isSameAuthor(book2, pbook2)); // LSP
		
    }

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

	public static boolean isSameAuthor(Book book1, Book book2)
    {
        return book1.getAuthor().equals(book2.getAuthor());
    }

    public String getShortName()
    {
        return author.substring(0, 2) + ": " + title.substring(0, 4) + "; " + pages;
    }

    //@Override
    public String toString()
    {
        return author + ": " + title + ", pages: " + pages;
    }

    public String createReference(String article, int from, int to)
    {
        return getShortName() + " [" + from + "-" + to + "] referenced in article: " + article;
    }
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
		super();
        this.pages += 6;
        this.cover = CoverType.Hardcover;
    }

    public PrintedBook(String author, String title, int pages, CoverType cover)
    {
        super(author, title, pages + 6);
        this.cover = cover;
    }

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

    //@Override
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

    public int getPrice()
    {
        return pages + PDFSize;
    }

    @Override
    public String createReference(String article, int from, int to)
    {
        return super.toString() + " (PDF size: " + PDFSize + ") [" + from + "-" + to + "] referenced in article: " + article;
    }

    //@Override // compile error
    public String createReference(String article, String date)
    {
        return super.toString() + " (PDF size: " + PDFSize + ") referenced in article: " + article + ", accessing PDF date: " + date;
    }
}

