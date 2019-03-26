using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Data;
using System.Data.SqlClient;

namespace studentDB
{
    class getstream
    {
        public  getstream()
        {
            SqlConnection con = new SqlConnection("Data Source=DESKTOP-SS5H7HT;Initial Catalog=ncr;Integrated Security=True");

            string command2 = "getStream";
            SqlCommand cmd = new SqlCommand(command2, con);
            cmd.CommandType = CommandType.StoredProcedure;
            //con.Open();
            //SqlDataReader dr = cmd.ExecuteReader();
            //GridView1.DataSource = dr;
            //GridView1.DataBind();
            //con.Close();
            SqlDataAdapter da = new SqlDataAdapter(cmd);
            DataSet ds = new DataSet();
            da.Fill(ds);
            return da.tables[0];
            //GridView1.DataSource = ds.Tables[0];
            //GridView1.DataBind();
        }
    }
}
