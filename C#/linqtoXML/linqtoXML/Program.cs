using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.IO;

namespace linqtoXML
{
    class Program
    {
        static void Main(string[] args)
        {
            DataClasses1DataContext dbc = new linqtoXML.DataClasses1DataContext();
            
            emp obj = new linqtoXML.emp();
            obj.empno = 10;
            obj.ename = "keerthana";
            obj.hiredate =null;
            obj.job = "ANALYST";
            obj.sal = 10000;
            obj.mgr = 7900;
            obj.comm = null;
            obj.deptno = 30;
            dbc.emps.InsertOnSubmit(obj);
            //Response.Write(dbc.Log);
           // dbc.InsertOnSubmit(obj);
            dbc.SubmitChanges();
           // Response.Write(dbc.Log);

        }
    }
}
