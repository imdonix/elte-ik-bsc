using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Net;
using System.CodeDom;

namespace ExamApp.Web
{
    public class WebResponse
    {
        private string data;
        private Exception exeption;
        private bool isSucces;

        public WebResponse(string data)
        {
            this.data = data;
            this.isSucces = true;
        }

        public WebResponse(Exception exception)
        {
            this.exeption = exception;
            this.isSucces = false;
        }

        public bool IsSucces()
        {
            return isSucces;
        }

        public override string ToString()
        {
            if (isSucces)
                return data;
            else
                return exeption.Message;
        }
    }
}
