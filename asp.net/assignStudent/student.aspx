<%@ Page Language="C#" AutoEventWireup="true" CodeFile="student.aspx.cs" Inherits="student" %>

<!DOCTYPE html>

<html xmlns="http://www.w3.org/1999/xhtml">
<head runat="server">
    <title></title>
</head>
<body>
    <form id="form1" runat="server">
    <div>
        <table>
            <tr>
                <th>Name:</th>
                <td><asp:TextBox runat="server" ID="Name"></asp:TextBox></td>

            </tr>
            <th>Course:
            </th>
            <td><asp:DropDownList ID="DropDownList1" runat="server" OnSelectedIndexChanged="DropDownList1_SelectedIndexChanged">
                </asp:DropDownList></td>
           


        </table>
    
    </div>
    </form>
</body>
</html>
