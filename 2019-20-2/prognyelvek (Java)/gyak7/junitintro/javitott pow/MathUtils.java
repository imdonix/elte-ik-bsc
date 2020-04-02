

class MathUtils
{
    public static double power(int base, int exp)
    {
        double result = 1;
        for (int i = 1; i <= Math.abs(exp); ++i)
        {
            result *= base;
        }

        if (exp <= 0) // ez itt hibás -> mostmár fail-el az eddig megírt unit test
        {
            if (base == 0)
            {
                throw new IllegalArgumentException();
            }
            result = 1.0 / result;
        }

        return result;
    }
}
