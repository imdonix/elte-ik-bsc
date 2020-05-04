using Newtonsoft.Json;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ExamApp.Models
{
    public enum Role
    {
        Student,
        Teacher
    }

    public class User
    {
        [JsonProperty("_id")] public string Id { get; set; }
        [JsonProperty("neptun")] public string Neptun { get; set; }
        [JsonProperty("name")] public string Name { get; set; }
        [JsonProperty("password")] public string Password { get; set; }
        [JsonProperty("role")]public Role Role { get; set; }

        public bool isModerator()
        {
            return Role == Role.Teacher;
        }

        public User(){}

        public User(string line)
        {
            string[] splitted = line.Split(';');
            Neptun = splitted[0];
            Name = splitted[1];
            Password = splitted[2];
            Role = Role.Student;
        }
    }
}
