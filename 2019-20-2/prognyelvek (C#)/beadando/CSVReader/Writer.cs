using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace CSVReader
{
    public static class Writer
    {
        public static void WriteFile(string src, string[] lines)
        {
            File.WriteAllLines(src, lines, Encoding.UTF8);
        }
    }
}
