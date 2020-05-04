using System;
using System.Collections.Generic;
using System.Globalization;
using System.IO;
using System.Linq;
using System.Runtime.Remoting.Activation;
using System.Runtime.Remoting.Metadata.W3cXsd2001;
using System.Text;
using System.Threading.Tasks;

namespace LOIMExamGenerator
{

    class Question
    {
        public int level;
        public string question;
        public string[] answers;
        public string right;
        public string category;
        public bool isBad;

        public Question(string line)
        {
            string[] splitted = line.Split(';');
            int i = 0;
            level = int.Parse(splitted[i++]);
            question = splitted[i++];
            answers = new string[4];
            answers[0] = splitted[i++];
            answers[1] = splitted[i++];
            answers[2] = splitted[i++];
            answers[3] = splitted[i++];
            right = splitted[i++];
            category = splitted[i++];

            SortAnswer();
        }

        public void SortAnswer()
        {
            int i = 0;
            string[] ans = new string[] { "A", "B", "C", "D" };
            while (i < ans.Length && !ans[i].Equals(right))
                i++;

            if (i >= ans.Length) 
            {
                isBad = true;
                return;
            }

            string tmp = answers[0];
            answers[0] = answers[i];
            answers[i] = tmp;
        }

        public override string ToString()
        {
            return $"select;{question};{level};{answers[0]};{answers[1]};{answers[2]};{answers[3]}";
        }
    }

    class Program
    {
        const int LEVEL = 1;
        const int NUM = 10;

        static void Main(string[] args)
        {

            string[] categories = new string[] { "FÖLDRAJZ", "ÁLTALÁNOS", "SPORT", "TECHNIKA", "TÖRTÉNELEM" };
            List<Question>[] allQuestion = new List<Question>[categories.Length];
            List<Question> questions = File.ReadAllLines("loim.csv", Encoding.UTF7).Select(u => new Question(u)).ToList();


            allQuestion = allQuestion.Select(u => new List<Question>()).ToArray();

            foreach (Question item in questions)
                if (item.level <= LEVEL && !item.isBad)
                {
                    int i = -1;
                    for (int j = 0; j < categories.Length; j++)
                        if (categories[j].Equals(item.category))
                            i = j;

                    if (i >= 0) 
                        if (allQuestion[i].Count < NUM)
                            allQuestion[i].Add(item);

                }

            for (int i = 0; i < categories.Length; i++)
                File.WriteAllLines("generated/" + categories[i].ToLower() + ".csv", GenerateData(allQuestion[i], categories[i]), Encoding.UTF8);
        }

        static string[] GenerateData(List<Question> q, string cat)
        {
            List<string> s = q.Select(u => u.ToString()).ToList();
            s.Insert(0, $"LÖIM {cat.ToLower()};Automatikusan generált teszt egy legyen ön is miliomos kérdésekből!;true;{q.Count}");
            return s.ToArray();
        }

    }
}
