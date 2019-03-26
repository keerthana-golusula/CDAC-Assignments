using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Collections
{
    class customer:IComparable<customer>
    {
        public int Id { get; set; }
        public string Name { get; set; }
        int IComparable<customer>.CompareTo(customer other)
        {
            return this.Id.CompareTo(other.Id);
        }
    }
    class Program
    {
        public static void dictionary()
        {
            customer cust1 = new Collections.customer { Id = 1, Name = "Keerthana1" };
            customer cust2 = new Collections.customer { Id = 2, Name = "Keerthana2" };
            customer cust3 = new Collections.customer { Id = 3, Name = "Keerthana3" };

            Dictionary<int, customer> values = new Dictionary<int, customer>();
            values.Add(cust1.Id, cust1);
            values.Add(cust2.Id, cust2);
            values.Add(cust3.Id, cust3);
            foreach (KeyValuePair<int, customer> value in values)
            {
                Console.WriteLine(value.Key + " " + value.Value.Name);
            }
            if (values.ContainsKey(1))
            {
                Console.WriteLine("True");
            }
           
        }
        public static void LoadList()
        {
            List<customer> list = new List<customer>()
            {
                new customer { Id=2,Name="keerthana"},
                new customer {Id=1,Name="sravani" }
            };
            foreach (customer cust in list)
            {
                Console.WriteLine(cust.Id + " " + cust.Name);
            }
            list.Sort();
            foreach(customer cust in list)
            {
                Console.WriteLine(cust.Id + " " + cust.Name);
            }
        }
        static void Main(string[] args)
        {


            dictionary();
            LoadList();

            Console.ReadLine();
        }
    }
}
