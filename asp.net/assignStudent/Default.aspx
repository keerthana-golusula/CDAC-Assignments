<%@ Page Language="C#" AutoEventWireup="true" CodeFile="Default.aspx.cs" Inherits="_Default" %>

<!DOCTYPE html>

<html xmlns="http://www.w3.org/1999/xhtml">
<head runat="server">
    <title></title>
</head>
<body >
    <form id="form1" runat="server">
    <div>
    
        StudentId:&nbsp;&nbsp;&nbsp;
        <asp:TextBox ID="TextBox1" runat="server"></asp:TextBox>
    
    </div>
      <div>
          Student Name:&nbsp;&nbsp;&nbsp;
            <asp:TextBox ID="TextBox2" runat="server"></asp:TextBox>

      </div>
        <div>
          PhoneNumber:&nbsp;&nbsp;&nbsp;
            <asp:TextBox ID="TextBox3" runat="server"></asp:TextBox>

      </div>
        <div>
          Email:&nbsp;&nbsp;&nbsp;
            <asp:TextBox ID="TextBox4" runat="server"></asp:TextBox>

      </div>
        <div>
          Address:&nbsp;&nbsp;&nbsp;
            <asp:TextBox ID="TextBox5" runat="server"></asp:TextBox>

      </div>
        <br />
        <asp:Button ID="Button2" runat="server" OnClick="Button2_Click" Text="Insert" />&nbsp;
        <asp:Button ID="Button1" runat="server" OnClick="Button1_Click" Text="Update" />&nbsp;
            
    
        <asp:Button ID="Button3" runat="server" OnClick="Button3_Click" Text="Delete" />
            
     &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
        <p>
            <asp:Button ID="Button4" runat="server" Text="View all Student Details" OnClick="Button4_Click" />
        </p>
            
   <p id="warning" runat="server" style="color:coral"></p>
        <asp:GridView ID="GridView1" runat="server">
        </asp:GridView>
            
    
    </form>
</body>
</html>
