using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;
using System.Data;
using System.Data.SqlClient;

public partial class _Default : System.Web.UI.Page
{
    protected void Page_Load(object sender, EventArgs e)
    {

    }

    protected void Button1_Click(object sender, EventArgs e)
    {


        int a, b, c;
        a = int.Parse(TextBox2.Text);
        b = int.Parse(TextBox3.Text);
        c = a + b;
        TextBox1.Text = c.ToString();
        SqlConnection con = new SqlConnection("Data Source=DESKTOP-SS5H7HT;Initial Catalog=ASP.net;Integrated Security=True");
        con.Open();
        string command = "insert into table_1 values("+TextBox2.Text+","+TextBox3.Text+","+TextBox1.Text+",'+','10/12/2018')";
        string command2 = "sp_insertmath";
        
        SqlCommand cmd = new SqlCommand(command2, con);
        SqlParameter para1 = new SqlParameter("@Num1", TextBox2.Text);
        cmd.Parameters.Add(para1);
        SqlParameter para2 = new SqlParameter("@Num2", TextBox3.Text);
        cmd.Parameters.Add(para2);
        SqlParameter para3 = new SqlParameter("@result", TextBox1.Text);
        cmd.Parameters.Add(para3);
        SqlParameter para4 = new SqlParameter("@Operation","+");
        cmd.Parameters.Add(para4);
        SqlParameter para5 = new SqlParameter("@Date","10/12/2019");
        cmd.Parameters.Add(para5);
        cmd.CommandType = CommandType.StoredProcedure;
        cmd.ExecuteNonQuery();
        con.Close();
    }
    
}