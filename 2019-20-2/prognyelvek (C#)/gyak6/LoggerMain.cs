using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Logger
{
    class Program
    {
        static void Main(string[] args)
        {
            Logger logger = new Logger();

            logger.AddLogMethod(ConsoleLog);
            logger.AddLogMethod(delegate (string msg) { Console.WriteLine(msg); });
            logger.AddLogMethod(x => Console.WriteLine(x));
            logger.AddLogMethod(x => 
            {
                using (StreamWriter sw = new StreamWriter("file.txt", true))
                {
                    sw.WriteLine(x);
                }
            });

            logger.Log("Log üzenet");
            logger.Log("Log üzenet2");
            Console.ReadLine();
        }

        static void ConsoleLog(string msg)
        {
            Console.WriteLine(msg);
        }
    }
}
