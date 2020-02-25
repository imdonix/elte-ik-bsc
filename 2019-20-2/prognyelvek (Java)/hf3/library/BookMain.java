package library;

class BookMain
{
	public static void main(String[] args)
	{
		Book b1 = new Book("A", "C", 1912, 50, true);
		Book b2 = new Book("B", "C", 1912, 10, true);
		Book b3 = new Book(b2);
		b3.aviable = false;
		
		System.out.println(b1.toString());
		System.out.println(b1.equals(b2));
		System.out.println(b2.equals(b3));
	}
}