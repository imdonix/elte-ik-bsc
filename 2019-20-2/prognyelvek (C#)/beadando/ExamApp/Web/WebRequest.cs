using ExamApp.Models;
using Newtonsoft.Json;
using System;
using System.Collections.Specialized;
using System.Net;
using System.Runtime.Remoting.Metadata.W3cXsd2001;
using System.Text;

namespace ExamApp.Web
{
    public static class WebRequest
    {
        private const string DOMAIN = "csharp-exam-app.herokuapp.com";
        private const string HOST = "http://" + DOMAIN;
        private static WebClient client;

        static WebRequest()
        {
            client = new WebClient();
            client.Encoding = Encoding.UTF8;
            client.DownloadStringCompleted += Client_DownloadStringCompleted;
            client.UploadStringCompleted += Client_UploadStringCompleted;
        }

        #region CLIENT_EVENTS 

        private static void Client_UploadStringCompleted(object sender, UploadStringCompletedEventArgs e)
        {
            Action<WebResponse> callback = (Action<WebResponse>)e.UserState;
            try
            { callback(new WebResponse(e.Result)); }
            catch (Exception ex)
            { callback(new WebResponse(ex)); }
        }

        private static void Client_DownloadStringCompleted(object sender, DownloadStringCompletedEventArgs e)
        {
            Action<WebResponse> callback = (Action<WebResponse>)e.UserState;
            try
            { callback(new WebResponse(e.Result));}
            catch (Exception)
            { callback(new WebResponse(e.Error)); }
        }

        #endregion

        #region CRUD

        private static void Get(string url, Action<WebResponse> callback)
        {
            client.Headers[HttpRequestHeader.ContentType] = "";
            client.DownloadStringAsync(new Uri(url), callback);
        }

        private static void LPost(string url, string data, Action<WebResponse> callback)
        {
            client.Headers[HttpRequestHeader.ContentType] = "application/x-www-form-urlencoded";
            client.UploadStringAsync(new Uri(url), "POST", data, callback);
        }

        private static void JPost(string url, string data, Action<WebResponse> callback)
        {
            client.Headers[HttpRequestHeader.ContentType] = "application/json";
            client.UploadStringAsync(new Uri(url), "POST", data, callback);
        }

        #endregion

        #region PUBLIC_METHODS 

        public static string GetDomain()
        {
            return DOMAIN;
        }

        public static string GetDownloadString()
        {
            return HOST + "/new";
        }

        public static bool IsClientBussy()
        {
            return client.IsBusy;
        }

        public static void SetAuthToken(string token)
        {
            client.Headers[HttpRequestHeader.Authorization] = $"Bearer {token}";
        }

        public static void Login(string neptun, string password, Action<WebResponse> callback)
        {
            string data = $"neptun={neptun}&password={password}";
            LPost(HOST + "/auth", data, callback);
        }

        public static void Check(Action<WebResponse> callback)
        {
            Get(HOST, callback);
        }

        public static void GetCollection(string collection, Action<WebResponse> callback)
        {
            Get(HOST + "/" + collection, callback);
        }

        public static void UploadNewUsers(User[] users, Action<WebResponse> callback)
        {
            JPost(HOST + "/users", JsonConvert.SerializeObject(users), callback);
        }

        public static void UploadResoult(Resoult resoult, Action<WebResponse> callback)
        {
            JPost(HOST + "/resoults", JsonConvert.SerializeObject(resoult), callback);
        }

        public static void DeleteExam(string id, Action<WebResponse> callback)
        {
            Get(HOST + "/delete/" + id, callback);
        }

        public static void UploadExam(UploadExam exam, Action<WebResponse> callback)
        {
            JPost(HOST + "/exams", JsonConvert.SerializeObject(exam), callback);
        }

        #endregion
    }
}
