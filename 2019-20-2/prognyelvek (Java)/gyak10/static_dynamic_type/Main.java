

class Book
{
    private String author, title;
    protected int pages;

    public String getAuthor() { return author; }

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
        return "Book: " + author + ": " + title + ", pages: " + pages;
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

    @Override
    public String toString()
    {
        if (cover == CoverType.Softcover)
        {
            return "PrintedBook: " + super.toString() + " (softcover)";
        }
        else
        {
            return "PrintedBook: " + super.toString() + " (hardcover)";
        }
    }

    @Override
    public String createReference(String article, int from, int to)
    {
        return super.toString() + " [" + from + "-" + to + "] referenced in article: " + article;
    }
}


class Main
{
    public static void main(String[] args)
    {
        Book book;

        book = new Book();
        // book statikus típusa Book, dinamikus típusa Book
        System.out.println(book.toString()); // Book toString()-je

        book = new PrintedBook("author", "Printed: Title", 100, CoverType.Softcover);
        // book statikus típusa Book, dinamikus típusa PrintedBook
        System.out.println(book.toString()); // PrintedBook toString()-je

        //PrintedBook pbook3 = (PrintedBook)book1;
        //System.out.println(pbook3.toString());
    }
}

