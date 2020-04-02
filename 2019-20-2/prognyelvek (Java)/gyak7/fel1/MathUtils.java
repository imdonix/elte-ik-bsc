

class MathUtils
{
    public static int Increment(int x)
    {
        if (x == Integer.MAX_VALUE)
        {
            return x;
        }
        else
        {
            return x + 1;
        }
    }
}