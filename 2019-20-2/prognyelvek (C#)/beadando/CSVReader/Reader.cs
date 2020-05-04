using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace CSVReader
{
    public static class Reader
    {
        public static List<string> ReadFile(string src)
        {
            if (!File.Exists(src))
                throw new FileNotFoundException(src);

            return File.ReadAllLines(src, Encoding.UTF7).ToList();
        }
    }
}
