using Newtonsoft.Json;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ExamApp.Models
{
    public class Version
    {
        [JsonProperty("api")] public string Api { get; set; }
        [JsonProperty("client")] public string Client { get; set; }

        public Version(){}

        public Version(string api, string client)
        {
            Api = api;
            Client = client;
        }

        public bool Equals(Version obj)
        {
            return Client.Equals(obj.Client);
        }
    }

}
