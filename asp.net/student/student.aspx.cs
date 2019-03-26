using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;

public partial class student : System.Web.UI.Page
{
    protected void Page_Load(object sender, EventArgs e)
    {

        //initStreams();
        studentDb.Class1 obj = new studentDb.Class1();
        stream.DataSource = obj.getStreams();
        stream.DataValueField = "Code";
        stream.DataTextField = "Name";
        stream.DataBind();
        inittransport();
        initlanguages();
    }

private void initStreams()
    {
        studentDb.Class1 obj = new studentDb.Class1();
        stream.DataSource = obj.getStreams();
        stream.DataValueField = "Code";
        stream.DataTextField = "Name";
        stream.DataBind();

    }
    private void inittransport()
    {
        studentDb.Class1 obj = new studentDb.Class1();
        transport.DataSource = obj.gettransport();
        transport.DataValueField = "Tcode";
        transport.DataTextField = "Tname";
        transport.DataBind();
    }
    private void initlanguages()
    {
        studentDb.Class1 obj = new studentDb.Class1();
        lang.DataSource = obj.getlanguage();
        lang.DataValueField = "Lid";
        lang.DataTextField = "Lname";
        lang.DataBind();
    }
    protected void Button1_Click(object sender, EventArgs e)
    {
           entities.studentEntity entobj = new entities.studentEntity();
        entobj.Name = name.Text;
        entobj.stream = stream.SelectedValue;
        entobj.Transport = transport.SelectedValue;
        entobj.DOB = DOB.SelectedDate.ToString();
        entobj.lunch = lunch.Checked;
        foreach(ListItem item in lang.Items)
            if (item.Selected == true)
            {
                entobj.languages = entobj.languages + "," + item.Value;
            }
        string path = @"C:\Photos/"+Guid.NewGuid().ToString() + photoUpload.FileName;
        entobj.photopath = path;
        //photoUpload.SaveAs(
        //    studentDb.Class1 obj = new studentDb.Class1();
        }
    }