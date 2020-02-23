using System;

namespace ConsoleApp26
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine("int--->");
            int i1 = 1;
            int i2 = i1;
            i1++;
            i2++;
            Console.WriteLine(i1);
            Console.WriteLine(i2);
            Console.WriteLine(i1 == i2);
            Console.WriteLine("--->int");

            Console.WriteLine("string--->");
            string s1 = "alma";
            string s2 = s1;
            string s3 = s1;
            s1 += "fa";
            s2 += "gyoker";
            s3 += "fa";
            Console.WriteLine(s1);
            Console.WriteLine(s2);
            Console.WriteLine(s3);
            Console.WriteLine(s1 == s2);
            Console.WriteLine(s1 == s3);
            Console.WriteLine("--->string");

            Console.WriteLine("class--->");
            JustSomeValues jsv1 = new JustSomeValues();
            jsv1.IntValue = 11;
            jsv1.StringValue = "barack";
            jsv1.IntArray = new int[3] { 1, 2, 3 };
            JustSomeValues jsv2 = new JustSomeValues();
            jsv2 = jsv1;
            JustSomeValues jsv3 = jsv1;
            jsv1.IntValue++;
            jsv2.IntValue++;
            jsv3.IntValue++;
            jsv1.StringValue += "ag";
            jsv2.StringValue += "fa";
            jsv3.StringValue += "gyoker";
            jsv1.IntArray[0]++;
            jsv2.IntArray[0]++;
            jsv3.IntArray[0]++;
            Console.WriteLine(jsv1.IntValue);
            Console.WriteLine(jsv2.IntValue);
            Console.WriteLine(jsv3.IntValue);
            Console.WriteLine(jsv1.StringValue);
            Console.WriteLine(jsv2.StringValue);
            Console.WriteLine(jsv3.StringValue);
            Console.WriteLine(jsv1.IntArray[0]);
            Console.WriteLine(jsv2.IntArray[0]);
            Console.WriteLine(jsv3.IntArray[0]);
            Console.WriteLine(jsv1 == jsv2);
            Console.WriteLine(jsv2 == jsv3);
            Console.WriteLine(jsv1.Equals(jsv2));
            Console.WriteLine(jsv2.Equals(jsv3));
            Console.WriteLine("--->class");

            Console.WriteLine("struct--->");
            SomeMoreValues smv1 = new SomeMoreValues();
            smv1.IntValue = 22;
            smv1.StringValue = "korte";
            smv1.IntArray = new int[3] { 1, 2, 3 };
            SomeMoreValues smv2 = new SomeMoreValues();
            smv2 = smv1;
            SomeMoreValues smv3 = smv1;
            smv1.IntValue++;
            smv2.IntValue++;
            smv3.IntValue++;
            smv1.StringValue += "ag";
            smv2.StringValue += "fa";
            smv3.StringValue += "gyoker";
            smv1.IntArray[0]++;
            smv2.IntArray[0]++;
            smv3.IntArray[0]++;
            Console.WriteLine(smv1.IntValue);
            Console.WriteLine(smv2.IntValue);
            Console.WriteLine(smv3.IntValue);
            Console.WriteLine(smv1.StringValue);
            Console.WriteLine(smv2.StringValue);
            Console.WriteLine(smv3.StringValue);
            Console.WriteLine(smv1.IntArray[0]);
            Console.WriteLine(smv2.IntArray[0]);
            Console.WriteLine(smv3.IntArray[0]);
            Console.WriteLine(smv1 == smv2);
            //Console.WriteLine(smv2 == smv3);
            Console.WriteLine(smv1.Equals(smv2));
            Console.WriteLine(smv2.Equals(smv3));
            Console.WriteLine("--->struct");

            Console.ReadLine();
        }
    }


    class JustSomeValues
    {
        public int IntValue { get; set; }

        public string StringValue { get; set; }

        public int[] IntArray { get; set; }
    }

    struct SomeMoreValues
    {
        public int IntValue { get; set; }

        public string StringValue { get; set; }

        public int[] IntArray { get; set; }
    }
}
