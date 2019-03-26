using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Data;
using System.Data.SqlClient;

namespace studentDb
{
    public class Class1
    {
        
        public DataTable getStreams()
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
            con.Close();
            return ds.Tables[0];
        }
        public DataTable gettransport()
        {
            SqlConnection con = new SqlConnection("Data Source=DESKTOP-SS5H7HT;Initial Catalog=ncr;Integrated Security=True");

            string command2 = "gettransport";
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
            con.Close();
            return ds.Tables[0];
        }
        public DataTable getlanguage()
        {
            SqlConnection con = new SqlConnection("Data Source=DESKTOP-SS5H7HT;Initial Catalog=ncr;Integrated Security=True");

            string command2 = "getlanguage";
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
            con.Close();
            return ds.Tables[0];
        }
        public bool saveStudent(entities.studentEntity ent)
        {
            SqlConnection con = new SqlConnection("Data Source=DESKTOP-SS5H7HT;Initial Catalog=ncr;Integrated Security=True");

            string command2 = "savestudent";
            SqlCommand cmd = new SqlCommand(command2, con);
            cmd.Parameters.Add(new SqlParameter("@name", ent.Name));
            cmd.Parameters.Add(new SqlParameter("@stream", ent.stream));
            cmd.Parameters.Add(new SqlParameter("@transport", ent.Transport));
            cmd.CommandType = CommandType.StoredProcedure;
            con.Open();
            cmd.ExecuteNonQuery();
            con.Close();
            return true;

        }
    }
}
