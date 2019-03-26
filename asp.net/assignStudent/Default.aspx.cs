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

    protected void Button2_Click(object sender, EventArgs e)
    {
        warning.InnerHtml = " ";
        try
        {
            SqlConnection con = new SqlConnection("Data Source=DESKTOP-SS5H7HT;Initial Catalog=ncr;Integrated Security=True");
            con.Open();
            //  string command = "insert into StudentDetails values('" + TextBox1.Text + "','" + TextBox2.Text + "','" + TextBox3.Text + "','"+TextBox4.Text+"','"+TextBox5.Text+"')";
            string command2 = "insertDetails";
            SqlCommand cmd = new SqlCommand(command2, con);
            SqlParameter para1 = new SqlParameter("@Id", TextBox1.Text);
            cmd.Parameters.Add(para1);
            SqlParameter para2 = new SqlParameter("@Name", TextBox2.Text);
            cmd.Parameters.Add(para2);
            SqlParameter para3 = new SqlParameter("@Phone", TextBox3.Text);
            cmd.Parameters.Add(para3);
            SqlParameter para4 = new SqlParameter("@Email", TextBox4.Text);
            cmd.Parameters.Add(para4);
            SqlParameter para5 = new SqlParameter("@Addr", TextBox5.Text);
            cmd.Parameters.Add(para5);
            cmd.CommandType = CommandType.StoredProcedure;
            cmd.ExecuteNonQuery();
            
            con.Close();
        }catch (Exception ex)
        {
            warning.InnerHtml = "Waring:"+ex.Message;
        }

    }

    protected void Button3_Click(object sender, EventArgs e)
    {
        warning.InnerHtml = " ";
        try
        {
            SqlConnection con = new SqlConnection("Data Source=DESKTOP-SS5H7HT;Initial Catalog=ncr;Integrated Security=True");
            con.Open();
            string command = "deleteDetails";
            //  string command2 = "delete from StudentDetails where StudentId='"+TextBox1.Text+"'";
            SqlCommand cmd = new SqlCommand(command, con);
            SqlParameter para1 = new SqlParameter("@id", TextBox1.Text);
            cmd.CommandType = CommandType.StoredProcedure;
            cmd.Parameters.Add(para1);
            cmd.ExecuteNonQuery();
            con.Close();
        }catch(Exception ex)
        {
            warning.InnerHtml = "Warning" + ex.Message;
        }
    }

    protected void Button1_Click(object sender, EventArgs e)
    {
        warning.InnerHtml = " ";
        try
        {
            SqlConnection con = new SqlConnection("Data Source=DESKTOP-SS5H7HT;Initial Catalog=ncr;Integrated Security=True");
            con.Open();
            string command = "update StudentDetails set StudentName='" + TextBox2.Text + "',PhoneNumber='" + TextBox3.Text + "',emailId='" + TextBox4.Text + "',addr='" + TextBox5.Text + "' where StudentId='" + TextBox1.Text + "'";
            SqlCommand cmd = new SqlCommand(command, con);
        

            cmd.ExecuteNonQuery();
            con.Close();
        }catch(Exception ex)
        {
            warning.InnerHtml="Warning"+ex.Message;
        }
    }

    protected void Button4_Click(object sender, EventArgs e)
    {
        warning.InnerHtml = " ";
        SqlConnection con = new SqlConnection("Data Source=DESKTOP-SS5H7HT;Initial Catalog=ncr;Integrated Security=True");

        string command2 = "viewDetails";
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
}