using System;
using System.IO;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace fourth
{
    class exceptions
    {
        public void readFromStream()
        {
            StreamReader sr = null;
            try
            {
                new StreamReader(@"C:\Users\cdac\Desktop\exception1.txt");
                Console.WriteLine(sr.ReadToEnd());
            }catch(Exception ex)
            {
                Console.WriteLine("please try again!!");
            }
        
        }
    }
}
