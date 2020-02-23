using System;


namespace Boxing
{
    class Program
    {
        static void Main(string[] args)
        {

            // boxing - unboxing
            int i = 11;
            object o = i;
            i = (int)o;
            Console.WriteLine(i);
            Console.WriteLine(o);

            // https://www.tutorialsteacher.com/articles/boxing-unboxing-in-cshar

            Console.ReadLine();
           
        }
    }
}
