using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Reflection;

namespace reflection
{
    class Program
    {
        static void Main(string[] args)
        {
            print();
            Console.Read();
        }
        public static void print()
        {
            Type ty = Type.GetType("reflection.reflect");
            object instance = Activator.CreateInstance(ty);
            MethodInfo minfo = ty.GetMethod("GetFullName");
            //string[] str = new string[2];
            object[] str = new object[]
            {
                new string[2]
            };
            str[0] = "keerthana";
            str[1] = "golusula";
            minfo.Invoke(instance, str);
        }
        
        
    }
    class reflect
    {
        public void GetFullName(string[] str)
        {
            Console.WriteLine(str[0] + " " + str[1]);
        }
    }
}
