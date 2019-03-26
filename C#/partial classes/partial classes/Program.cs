using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using nm1=namespace1; // alias name allocation to a namepsace.
using namespace2;

namespace partial_classes
{
    partial class Class1
    {
        partial void method()
        {
            Console.WriteLine(id.ToString());
        }
    }
    class Program
    {
 
        static void Main(string[] args)
        {
            Class1 obj = new Class1();
            obj.print();
          
            Class2 obj2 = new partial_classes.Class2();
            ((partial_classes.interface1)(obj2)).print();// typecasting the class object to interface to avoid ambiguity

            nm1.ClassA obj3 = new nm1.ClassA();  //intead of writing namespace name every time we can use alias name.
            namespace2.ClassA obj4 = new namespace2.ClassA();// use namespacename.Classname to avoid ambiguity.

            indexersample obj5 = new indexersample();
            Console.WriteLine(obj5[2]);

            Console.Read();
        }
    }
}
