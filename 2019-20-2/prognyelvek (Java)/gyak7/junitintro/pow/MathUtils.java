class MathUtils
{
    public static double power(int base, int exp)
    {
        double result = 1;
        for (int i = 1; i <= Math.abs(exp); ++i)
        {
            result *= base;
        }
        return result;
    }
}
