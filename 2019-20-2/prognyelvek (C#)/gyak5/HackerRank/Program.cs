using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace HackerRank
{
    class Program
    {

        static void Main(string[] args)
        {
            #region eddigiek
            solveMeFirst(2, 3);

            //            6
            //1 2 3 4 10 11
            int[] tomb = new int[6] { 1, 2, 3, 4, 10, 11 };
            simpleArraySum(tomb);

            // 10 14
            int[] tomb2 = new int[5] { 5, 2, 3, 1, 4 };
            miniMaxSum(tomb2);
            #endregion

            //            11 2 4
            //4 5 6
            //10 8 - 12

            List<List<int>> bemenet = new List<List<int>>();

            List<int> sor1 = new List<int>();
            sor1.Add(11);
            sor1.Add(2);
            sor1.Add(4);

            List<int> sor2 = new List<int>();
            sor2.Add(4);
            sor2.Add(5);
            sor2.Add(6);

            List<int> sor3 = new List<int>();
            sor3.Add(10);
            sor3.Add(8);
            sor3.Add(-12);

            bemenet.Add(sor1);
            bemenet.Add(sor2);
            bemenet.Add(sor3);
            diagonalDifference(bemenet);

        }

        #region korábbi megoldások

        static int solveMeFirst(int a, int b)
        {
            // Hint: Type return a+b; below  
            return a + b;
        }

        static int simpleArraySum(int[] ar)
        {
            int osszeg = 0;
            for (int i = 0; i < ar.Length; i++)
            {
                osszeg += ar[i];
            }
            return osszeg;
        }

        static void miniMaxSum(int[] arr)
        {
            long min, max;
            Array.Sort(arr);
            min = arr[0] + arr[1] + arr[2] + arr[3];
            max = arr[4] + arr[1] + arr[2] + arr[3];
            Console.WriteLine($"{min} {max}");
        }
        #endregion

        public static int diagonalDifference(List<List<int>> arr)
        {
            int fo = 0;
            int mel = 0;

            int n = arr.Count();
            int[,] tombom = new int[n, n];
            for (int i = 0; i < n; i++)
            {
                List<int> sor = arr[i];
                for (int j = 0; j < n; j++)
                {
                    tombom[i, j] = sor[j];
                    if (i == j)
                    {
                        fo += sor[j];
                    }

                    if (i + j == n - 1)
                    {
                        mel += sor[j];
                    }
                }
            }

            return Math.Abs(fo-mel);
        }

    }
}
