using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace threading
{
    class Program
    {
        static void Main(string[] args)
        {
            List<int> list = new List<int>
            {
                1,2,3,4,5
            };
           int k= list.Find(delegate (int i)
            {
                return i % 2 == 0;
            });
            Console.WriteLine(k.ToString());
            foreach(int l in list)
            {
                Console.WriteLine(l.ToString());
            }

           // Form1 obj = new Form1();
            Console.Read();
        }

    }
}
