package hu.elte.madtycoon.utils;

public class Random
{
    public static int getRandomInt(int min, int max)
    {
        return min + ((int)(Math.random() * (max-min)));
    }

    public static float getRandomFloat(float min, float max)
    {
        return min + ((float) Math.random() * (max-min));
    }
}
