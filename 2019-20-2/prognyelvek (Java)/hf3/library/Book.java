package library;

class Book
{
	String name, author;
	int age, pages;
	boolean aviable;
	
	Book(String name, String author, int age, int pages, boolean aviable)
	{
		this.name = name;
		this.author = author;
		this.age = age;
		this.pages = pages;
		this.aviable = aviable;
	}
	
	Book(Book b)
	{
		if(b == null)
			return;
		
		this.name = b.name;
		this.author = b.author;
		this.age = b.age;
		this.pages = b.pages;
		this.aviable = b.aviable;
	}
	
	public String toString()
	{
		return name + " | " + author + " | " + age
		+ " | " + pages + " | " + aviable;
	}
	
	boolean equals(Book b)
	{
		return 
		this.name == b.name &&
		this.author == b.author &&
		this.age == b.age &&
		this.pages == b.pages;
	}	
}