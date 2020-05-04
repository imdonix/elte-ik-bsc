using Newtonsoft.Json;
using System;
using System.Collections.Generic;
using System.DirectoryServices;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ExamApp.Models
{
    public class Exam
    {
        [JsonProperty("_id")] public string Id { get; private set; }
        [JsonProperty("title")] public string Title { get; private set; }
        [JsonProperty("description")] public string Description { get; private  set; }
        [JsonProperty("isRandomized")] public bool IsRandomized { get; private set; }
        [JsonProperty("time")] public int Time { get; private set; }
        [JsonProperty("questions")] public string[] QuestionsIDs { get; private set; }
        private Question[] questions;

        public void FillQuestions(Question[] quests)
        {
            questions = quests.ToList().FindAll(u => QuestionsIDs.Contains(u.Id)).ToArray();
        }

        public Question[] GetQuestions()
        {
            return questions;
        }

        public string[] ToArray()
        {
            string[] tmp = new string[5];
            int i = 0;
            tmp[i++] = Title;
            tmp[i++] = Description;
            tmp[i++] = IsRandomized.ToString();
            tmp[i++] = Time.ToString();
            return tmp;
        }

        public string[] GetData()
        {
            List<string> tmp = new List<string>();
            tmp.Add(concat(ToArray()));
            foreach (Question quest in GetQuestions())
                tmp.Add(concat(quest.ToArray()));
            return tmp.ToArray();
        }

        public string concat(string[] strs)
        {
            StringBuilder stringBuilder = new StringBuilder();
            for (int i = 0; i < strs.Length; i++)
            {
                stringBuilder.Append(strs[i]);
                if(i != strs.Length-1)
                    stringBuilder.Append(';');
            }
            return stringBuilder.ToString();
        }
    }
}
