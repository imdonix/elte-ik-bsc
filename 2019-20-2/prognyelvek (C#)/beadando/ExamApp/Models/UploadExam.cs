using Newtonsoft.Json;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ExamApp.Models
{
    public class UploadExam
    {
        [JsonProperty("_id")] public string Id { get; private set; }
        [JsonProperty("title")] public string Title { get; private set; }
        [JsonProperty("description")] public string Description { get; private set; }
        [JsonProperty("time")] public int Time { get; private set; }
        [JsonProperty("isRandomized")] public bool IsRandomized { get; private set; }
        [JsonProperty("questions")] public Question[] Questions { get; set; }

        public UploadExam() {}

        public UploadExam(string line)
        {
            string[] splitted = line.Split(';');
            int i = 0;
            Title = splitted[i++];
            Description = splitted[i++];
            IsRandomized = splitted[i++] == "true";
            Time = int.Parse(splitted[i++]);
        }
    }
}
