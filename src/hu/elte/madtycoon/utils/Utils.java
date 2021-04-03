package hu.elte.madtycoon.utils;

public class Utils
{
    public static float clamp(float min, float max, float val)
    {
        if(val > max)
            return max;
        else if(val < min)
            return min;
        else
            return val;
    }

    public static int clamp(int min, int max, int val)
    {
        if(val > max)
            return max;
        else if(val < min)
            return min;
        else
            return val;
    }
}
