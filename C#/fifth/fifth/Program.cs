using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace fifth
{
   // public delegate void DelegateHelper();
   
   
    class employee
    {
        public delegate bool promoteDelegate(employee emp);
        public int Id { get; set; }
        public string Name { get; set; }
        public int years { get; set; }
        public int salary { get; set; }
        public static void promotion (List<employee>emps,promoteDelegate promote)
        {
            foreach(employee emp in emps)
            {
                if (promote(emp))
                {
                    Console.WriteLine(emp.Name + " promoted");
                }
            }
        }
       public static bool ispromotable(employee emp)
        {
            if (emp.years >= 5)
            {
                return true;
            }
            return false;
        }
        public static bool ispromotableBysal(employee emp)
        {
            if (emp.salary > 20000)
                return true;
            return false;
        }
        static void Main(string[] args)
        {
            //DelegateHelper DH = new DelegateHelper(printHello);
            //DH();
            List<employee> emps = new List<employee>()
            {
                new fifth.employee { Id=1,Name="keerthana",years=3,salary=30000},
                new employee {Id=2,Name="Raj",years=5,salary=20000},
                new employee {Id=3,Name="sravani",years=7 ,salary=10000 }
            };
            promoteDelegate promote = new promoteDelegate(ispromotable);
            promote += ispromotable;
            promotion(emps, promote);


            Console.Read();
        }
    }
}
