package main;

import java.util.HashSet;
import person.*;


public class Main
{
    public static void main(String[] args)
    {
        HashSet<Person> exampleSet = new HashSet<Person>();
        exampleSet.add(new Person("AAA", "BBB", "oc", Gender.MALE, 2000));
        exampleSet.add(new Person("AAA2", "BBB2", "oc2", Gender.FEMALE, 1999));
        exampleSet.add(new Person("AAA", "BBB", "oc", Gender.MALE, 2000));
        exampleSet.add(new Person("AAA", "BBB", "oc", Gender.MALE, 2000));
        exampleSet.add(new Person("AAA", "BBB", "oc", Gender.MALE, 2000));
        exampleSet.add(new Person("AAA", "BBB", "oc", Gender.MALE, 2000));

        System.out.println("size of HashSet: " + exampleSet.size());
        System.out.println("items of HashSet: " + exampleSet);

        Person tmp = new Person("AAA", "BBB", "oc", Gender.MALE, 2000);
        //System.out.println(tmp.equals(tmp)); // equals(Person)
        System.out.println(tmp.equals(new Object())); // equals(Object)
    }
}

