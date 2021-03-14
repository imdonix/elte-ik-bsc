package hu.elte.madtycoon.utils;

public class Random
{
    public static int getRandomInt(int min, int max)
    {
        return min + ((int)(Math.random() * (max-min)));
    }
}
