using Newtonsoft.Json;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ExamApp.Models
{
    public class LoginResponse
    {
        [JsonProperty("key")] public string Key { get; set; }
        [JsonProperty("user")] public User User { get; set; }
    }
}
