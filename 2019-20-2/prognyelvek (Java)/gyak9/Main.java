

import java.util.LinkedList;


class Main
{
    public static LinkedList<Integer> divisors(int num)
    {
        LinkedList<Integer> result = new LinkedList<Integer>();

        for (int i = 1; i <= Math.sqrt(num); ++i)
        {
            if (num % i == 0)
            {
                result.add(i);
                if (num / i != i)
                {
                    result.add(num/i);
                }
            }
        }
        return result;
    }

    public static void main(String[] args)
    {
        System.out.println(divisors(10));
        System.out.println(divisors(1));
        System.out.println(divisors(2));
        System.out.println(divisors(7));
        System.out.println(divisors(124));
    }
}