
using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;
using System.Data;
using System.Data.SqlClient;

public partial class History : System.Web.UI.Page
{
    protected void Page_Load(object sender, EventArgs e)
    {

    }

    protected void Button2_Click(object sender, EventArgs e)
    {
        SqlConnection con = new SqlConnection("Data Source=DESKTOP-SS5H7HT;Initial Catalog=ASP.net;Integrated Security=True");
     
        string command2 = "retrieval";
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
        GridView1.DataSource = ds.Tables[0];
        GridView1.DataBind();
    }

    protected void GridView1_SelectedIndexChanged(object sender, EventArgs e)
    {

    }
}