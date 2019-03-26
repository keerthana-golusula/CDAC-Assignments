using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace first
{
    //class class1
    //{
    //    public int p;
    //    public int q;
    //    public class1(int p,int q)
    //    {
    //        this.p = p;
    //        this.q = q;
    //    }
    //    public void point(int p,int q)
    //    {
    //        this.p = p;
    //        this.q = q;
    //    }
    //}
    class Base
    {
       public string fname="fname", lname="lname", email="email.com";
       virtual public void printdetails()
        {
            Console.WriteLine(fname + " " + lname + " " + email);
        }

    }
    class derived1 : Base
    {
        public int salary=1000;
        override public void printdetails()
        {
            Console.WriteLine(fname + " " + lname + " " + email+" derived1");
        }
        public void printsalary()
        {
            Console.WriteLine(salary);
        }
    }
    class derived2 :Base
    {
        public int yearlysalary=10000;
      new public void printdetails()
        {
            Console.WriteLine(fname + " " + lname + " " + email+" derived2");
        }
        public void printsalary()
        {
            Console.WriteLine(yearlysalary);
        }

    }
    class Program
    {
        static void Main(string[] args)
        {
            ClassLibrary1.Class1.func();
            int? x = null;
            Console.WriteLine("my first line");
            Console.WriteLine("x is :" + x);
            //Console.WriteLine("type of x is:" + x.GetType());
            int[] arrayname = { 1, 2, 3 };
            foreach (var x2 in arrayname)
                Console.WriteLine(x2);
            int x1 = 10;
            int y = 20;
            //int z = (x1 > y) ? x1 : y;
            //Console.WriteLine(z + "is greater");
            //float f= 12.5F;
            // x1=(int)f;
            //Console.WriteLine(x1);

            //class1 p1= new class1(10,20);
          
            //Console.WriteLine(p1.p + " " + p1.q);
            //p1.point(10, 10);
            //Console.WriteLine(p1.p + " " + p1.q);
            int sub;
            int add = addition(x1, y,3,4,5);
            sub = subtraction( y,num3:10);
            Console.WriteLine(add+" "+sub);
            Base Bobj = new Base();
            Base d1obj = new derived1();
            Base
                d2obj = new derived2();
            Console.WriteLine("base objeect");
            Bobj.printdetails();
            d1obj.fname = "sravani";
            d1obj.lname = "santhoshi";
            d1obj.email = "sravanisanthoshi@gmail.com";
            d1obj.printdetails();
            //d1obj.printsalary();
            d2obj.fname = "keerthana";
            d2obj.lname = "golusula";
            d2obj.email = "kerthanagolusula@gmail.com";
            d2obj.printdetails();
          //  d2obj.printsalary();

            Console.Read();
        }
        public static int addition(int num1,int num2, params int[] values)
        {
            int sum = num1 + num2;
            if (values != null)
            {
                Console.WriteLine("values passed");
                for (int index = 0; index < values.Length; index++)
                    sum = sum + values[index];
            }
           // sub = num1 - num2;
            return sum;
        }
        public static int subtraction(int num1,int num2 = 0,int num3=0)
        {
            return num1 - num3;
        }

    }
}
