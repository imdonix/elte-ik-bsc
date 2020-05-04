using Newtonsoft.Json;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ExamApp.Models
{
    public class Resoult
    {
        [JsonProperty("_id")] public string Id { get; set; }
        [JsonProperty("user")] public string User { get; set; }
        [JsonProperty("exam")] public string Exam { get; set; }
        [JsonProperty("answers")] public int[] Answers { get; set; }

        public Resoult(string exam, int[] answers)
        {
            Exam = exam;
            Answers = answers;
        }
    }
}
