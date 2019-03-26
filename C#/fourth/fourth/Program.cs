using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace fourth
{
    public delegate void DelegateHelper(string s);
    class Program
    {
        static void Main(string[] args)
        {
            exceptions obj1 = new exceptions();
            obj1.readFromStream();
            try
            {
                try
                {
                    Console.WriteLine("Enter fiorst number:");
                    string a = Console.ReadLine();
                    Console.WriteLine("Enter Second Number:");
                    string b = Console.ReadLine();
                    int c = Convert.ToInt32(a) / Convert.ToInt32(b); // converting into int
                    int num;
                    if (int.TryParse("2", out num))
                    {
                        // we can use this instead of convert to avoid exceptions
                    }
                    Console.WriteLine(c.ToString());
                }
                catch (FormatException ex)
                {
                    Console.WriteLine("fe" + ex.Message);
                    throw new Exception("Inner Exception", ex);
                }
                catch (DivideByZeroException ex)
                {
                    Console.WriteLine(ex.Message);
                    throw new Exception("Inner Exception", ex);
                }
                catch (OverflowException ex)
                {
                    Console.WriteLine(ex.Message);
                    throw new Exception("Inner Exception", ex);
                }
            }
            catch (Exception ex)
            {
                Console.WriteLine("exception re thrown:" + ex.Message);
            }
         
        DelegateHelper DH = new DelegateHelper(printHello);
            DH();
        
        Console.Read();
        }
        public static void printHello()
        {
            Console.WriteLine("in delegate");
        }

    }
        
    }
       
    

