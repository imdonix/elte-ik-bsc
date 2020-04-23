import java.util.Scanner;
import java.io.File;
import java.io.FileNotFoundException;

class Main
{
    public static void main(String[] args)
    {
/*
        Bag<String> bag = new Bag<>();
        bag.add("foo");
        bag.add("foo");
        bag.add("foo");
        bag.add("foo2");
        bag.add("foo3");
        bag.add("idk");
        bag.add("idk");
        System.out.println(bag);
*/

        File input = new File(args[0]);
        Bag<String> statistics = new Bag<>();

        try (Scanner sc = new Scanner(input))
        {
            while (sc.hasNextLine())
            {
                statistics.add(sc.nextLine());
            }
        }
        catch (FileNotFoundException e)
        {
            System.out.println("Unable to access file: " + args[0]);
        }

        System.out.println("Word statistics: " + statistics);
    }
}

