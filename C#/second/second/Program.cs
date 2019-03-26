using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace second
{
    class parent {
        public parent()
        {
            Console.WriteLine("parent class default");
        }
         public parent(string str)
        {
            Console.WriteLine("parent class Parameterised" + str);
        }

    }
    class child:parent
    {
        public child():base("called from derived")
        {
            Console.WriteLine("child class default");
        }
    }
    class TimePeriod
    {
        private double seconds;
        private string automaticProp;
        private string testprop;

        public string AutomaticProp
        {
            get
            {
                return automaticProp;
            }

            set
            {

                try
                {
                    if (value[0] != '_')
                    {
                        automaticProp = value;
                    }
                    else
                    {
                        throw new InvalidProgramException("this is wrong input");
                    }
                }
                catch (Exception e)
                {
                    Console.WriteLine(e);
                }
            }
        }

        public string Testprop
        {
            get
            {
                return testprop;
            }

            set
            {
                testprop = value;
            }
        }
        public int MyProperty { get; set; } 

          
            //{
            //    return MyProperty;
            //}
            //set
            //{
            //    if (value <= 10)
            //        MyProperty = value;
            //}


                    //    }


                }

    class Program
    {
        static void Main(string[] args)
        {
            parent p = new parent();
            child c = new child();
            TimePeriod tp = new TimePeriod();
            tp.Testprop = "keerthana";
            tp.MyProperty = 10;
          
            Console.WriteLine(tp.MyProperty);
            Console.WriteLine(tp.Testprop);
            tp.AutomaticProp = "_keerthana";
            Console.WriteLine(tp.AutomaticProp);
            Console.Read();
        }
    }
}
