using Newtonsoft.Json;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ExamApp.Models
{
    public class Question
    {
        [JsonProperty("_id")] public string Id { get; set; }
        [JsonProperty("type")] public string Type { get; set; }
        [JsonProperty("description")] public string Description { get; set; }
        [JsonProperty("point")] public int Point { get; set; }
        [JsonProperty("answers")] public string[] Answers { get; set; }

        public Question() {}

        public Question(string line)
        {
            string[] splitted = line.Split(';');
            int i = 0;
            Type = splitted[i++];
            Description = splitted[i++];
            Point = int.Parse(splitted[i++]);
            Answers = new string[splitted.Length - i];
            for (int j = i; i < splitted.Length; i++)
                Answers[i - j] = splitted[i];
        }

        public string[] ToArray()
        {
            List<string> tmp = new List<string>();
            tmp.Add(Type);
            tmp.Add(Description);
            tmp.Add(Point.ToString());
            foreach (string ans in Answers)
                tmp.Add(ans);
            return tmp.ToArray();
        }
    }
}
