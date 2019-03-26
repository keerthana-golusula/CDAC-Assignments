using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace partial_classes
{
   partial class Class1
    {
        private int id=10;
        partial void method();// partial methods are always private
        public void print()
        {
            Console.WriteLine("Helo");
            method();
        }
    }
    interface interface1
    {
        void print();
    }
    interface interface2
    {
        void print();
    }
    class Class2 : interface1, interface2 // multiple inheritance is possible.
    {
        void interface1.print() // avoid ambiguity by using its interface name.
        {
            Console.WriteLine("interface1");

        }
        void interface2.print()
        {
            Console.WriteLine("interface2");
        }
    }
   public class indexersample
    {
        List<int> list = new List<int>();
        public indexersample()
        {
            list.Add(10);
            list.Add(20);
            list.Add(30);

        }
       // public int MyProperty { get; set; }
        public int this [int id]
        {
            get
            {

                return list[id];
            }
            set
            {
                list[id] = value;
            }
        }
    }
}
// same class definition in different namespaces 

namespace namespace1
{
    public class ClassA
    {
      public ClassA()
        {
            Console.WriteLine("ClassA in namespace1 ");
        }
    }
}
namespace namespace2
{
    public class ClassA
    {
        public ClassA()
        {
            Console.WriteLine("ClassA in namespace2 ");
        }
    }
}
