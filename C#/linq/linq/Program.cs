using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.IO;
using System.Data;


namespace linq
{
    class Program
    {
        static void Main(string[] args)
        {
            //  Linqintro();
            // deffered();
            aggregate();
            grouping();
            elementmethod();
            quantifier();
            Console.Read();
        }
        private static void Linqintro()
        {
            string path=@"C:\Windows";
            DirectoryInfo info = new DirectoryInfo(path);
            FileInfo[] files = info.GetFiles();
            #region Non Linq

            #endregion Non Linq
            var result = (from file in files
                          orderby file.Length descending
                          select file).Take(5);
            // var result = files.orderByDescending(file => file.Length).Take(5);
            // Console.WriteLine(result);
            //linq.Form1.dataGridView1.DataSource = result;
            //linq.Form1.dataGridView1.DataBind();
            foreach (var file in result)
            {
                Console.WriteLine(file.ToString());
            }
         
           
        }
        public static void deffered()
        {
            List<int> numbers = new List<int> { 1, 2, 3, 4, 5, 6};
            var result = from num in numbers where num % 2 == 0 select num;
            numbers.Add(7);
            numbers.Add(8);
            foreach(var num in result)
            {
                Console.WriteLine(num.ToString());
            }
        }
        public static void aggregate()
        {
            List<int> numbers = new List<int> { 1, 2, 3, 4, 5, 6 };
            Console.WriteLine(numbers.Min());
            Console.WriteLine(numbers.Max());
            Console.WriteLine(numbers.Sum());
            Console.WriteLine(numbers.Count());
            Console.WriteLine(numbers.Average());
            Console.WriteLine(numbers.Aggregate((a,b)=>a+b));
            employeelist list = new employeelist();
            List<employee> emps = new List<employee>
        {
            new employee {Id= 10,Name="keerthana",Gender="Female" },
             new employee {Id= 30,Name="sravani",Gender="Female" },
            new employee { Id=20,Name="Sanjay",Gender="Male"}
        };
            // employee emp = new employee;
            var result = emps.Where(emp => emp.Gender == "Female").Select (emp=>new {Name = emp.Name, Gender = emp.Gender });
            foreach (var num in result)
            {
                Console.WriteLine( num.Name + " " + num.Gender);
            }
        }
        public static void partition()
        {
            List<string> strlist = new List<string>()
            {
                "one","two","Three","Hi","Four"
            };
            var takelist = strlist.Take(2);
            var skiplist = strlist.Skip(2);

        }
        public static void conversion()
        {
            employeelist list = new employeelist();
      
            var newset = list.emps.ToDictionary(x => x.Id);
        }
        public static void grouping()
        {
            employeelist list = new employeelist();
        
            var newset =list.emps.GroupBy(emp => emp.Gender);
            foreach(var group in newset)
            {
                Console.WriteLine(group.Key + " " + group.Count());

            }
        }
        public static void elementmethod()
        {
            List<int> list = new List<int> { 1 };
            Console.WriteLine(list.First());
            Console.WriteLine(list.FirstOrDefault());
            Console.WriteLine(list.ElementAt(0));
            Console.WriteLine(list.ElementAtOrDefault(0));
           // Console.WriteLine(list.Single());
            Console.WriteLine(list.SingleOrDefault());
        }
     public static void quantifier()
        {
            List<int> list = new List<int> { 1,2,3,6,7,8 };
            if (list.All(x => x < 8)){
                Console.WriteLine("all elements are less thyan eight");
            }
            if (list.Any(x => x > 6))
            {
                Console.WriteLine("few elements are greater vthan 6");
            }
        }
        //public static void conversion2()
        //{
        //    ArrayList list1 = new ArrayList();
        //    list1.Add(1);
        //}
    }
    
 public class employee
    {
        public int Id { get; set; }
        public string Name { get; set; }
        public string Gender { get; set; }
       //public employee(int i,string n,string g)
       // {
       //     Id = i;
       //     Name = n;
       //     Gender = g;
       // }
       
    }
    public class employeelist
    {
        public List<employee> emps = new List<employee>();
        public employeelist()
        {
            emps.Add(new employee { Id = 10, Name = "keerthana", Gender = "Female" });
            emps.Add(new employee { Id = 30, Name = "sravani", Gender = "Female" });
            emps.Add(new employee { Id=20,Name="Sanjay",Gender="Male"});
        }
   
    }
   
}
