package person;

enum Gender {
	MALE,
	FEMALE
}

class Person
{
	String firstname, lastname;
	String job;
	Gender gender;
	int birth;
	
	public static void main(String[] args)
	{
		Person p1 = new Person("Wirth", "Istvan", "matematikus", Gender.MALE, 0);
		Person p2 = new Person("Wirth", "Istvan", "matematikus", Gender.MALE, 0);
		
		System.out.println(p1.toString());
		System.out.println(p2.toString());
		
		System.out.println(p1.equals(p2));
	}
	
	Person(String firstname, String lastname, String job, Gender gender, int birth)
	{
		this.firstname = firstname;
		this.lastname = lastname;
		this.job = job;
		this.gender = gender;
		this.birth = birth;
	}
	
	public String toString()
	{
		return firstname + " " + lastname + " " + job  + " " + gender.toString() + " " + "[" + birth + "]";
	}
	
	boolean equals(Person p)
	{
		if(p == null)
			return false;
		
		boolean b = true;
		b = b && p.firstname == firstname;
		b = b && p.lastname == lastname;
		b = b && p.job == job;
		b = b && p.gender == gender;
		b = b && p.birth == birth;
		return b;
	}
	
}