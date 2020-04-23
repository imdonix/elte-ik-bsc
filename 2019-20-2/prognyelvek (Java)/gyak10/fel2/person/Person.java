package person;

import java.util.Objects;

public class Person
{
    private String firstname, lastname;
    private String occup;
    private Gender gen;
    private int birthYear;

    public Person(String firstname, String lastname, String occup, Gender gen, int birthYear)
    {
        this.firstname = firstname;
        this.lastname = lastname;
        this.occup = occup;
        this.gen = gen;
        this.birthYear = birthYear;
    }

    public String toString()
    {
        return "(" + firstname + "," + lastname + "," + occup + "," + gen + "," + birthYear + ")";
    }

    // overload
    // dont do this
    /*
    public boolean equals(Person that)
    {
        return this.firstname.equals(that.firstname) && this.lastname.equals(that.lastname) && this.occup.equals(that.occup) && this.gen == that.gen && this.birthYear == that.birthYear;
    }*/

    @Override
    public boolean equals(Object that)
    {
        if (that == this) return true;
        if (that == null) return false;

        if (that instanceof Person)
        {
            Person thatPerson = (Person)that;
            return firstname.equals(thatPerson.firstname) && lastname.equals(thatPerson.lastname) && occup.equals(thatPerson.occup) && gen == thatPerson.gen && birthYear == thatPerson.birthYear;
        }
        else return false;
    }

    @Override
    public int hashCode()
    {
        return Objects.hash(firstname, lastname, occup, gen, birthYear);
    }
}

