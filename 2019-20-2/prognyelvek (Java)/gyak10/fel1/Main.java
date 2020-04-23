import java.util.HashSet;

class Main
{
    public static void main(String[] args)
    {
        System.out.println(new Vector(2, 3).equals(new Vector(2, 3)));
        System.out.println(new Vector(2, 3).equals(new Vector(2, 2)));

        HashSet<Vector> exampleSet = new HashSet<Vector>();
        exampleSet.add(new Vector(0, 0));
        exampleSet.add(new Vector(3, -7));
        exampleSet.add(new Vector(3, -7));
        System.out.println( "size of HashSet: " + exampleSet.size());
        System.out.println( "items of HashSet: " + exampleSet);
    }
}
