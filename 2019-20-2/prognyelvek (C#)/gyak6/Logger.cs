using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Logger
{
    class Logger
    {
        private Action<string> logMethods;

        public void AddLogMethod(Action<string> logMethod)
        {
            logMethods += logMethod;
        }

        public void Log(string message)
        {
            logMethods?.Invoke(string.Format("[{0}]: {1}", DateTime.UtcNow.ToLocalTime(), message));
        }
    }
}
