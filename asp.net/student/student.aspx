<%@ Page Language="C#" AutoEventWireup="true" CodeFile="student.aspx.cs" Inherits="student" %>

<!DOCTYPE html>

<html xmlns="http://www.w3.org/1999/xhtml">
<head runat="server">
    <title></title>
</head>
<body>
    <form id="form1" runat="server">
    <div>
        <table><tr>
            <th>
                <asp:RequiredFieldValidator ID="RequiredFieldValidator1" runat="server" ControlToValidate="name" ErrorMessage="*" ForeColor="Red"></asp:RequiredFieldValidator>
                Name:</th>
            <td><asp:TextBox runat="server" ID="name"></asp:TextBox></td>
            </tr>
            <tr>
                <th>Stream:</th>
                <td>
                   <asp:DropDownList runat="server" ID="stream"></asp:DropDownList>
                </td>
            </tr>
            <tr>
                <th>Transport:</th>
                <td><asp:RadioButtonList runat="server" ID="transport"></asp:RadioButtonList></td>
            </tr>
            <tr>
                <th>DOB:</th>
                <td><asp:Calendar runat="server" ID="DOB"></asp:Calendar></td>
            </tr>
            <tr>
                <th>Lunch:</th>
                <td>
                    <asp:CheckBox runat="server" ID="lunch"></asp:CheckBox>
                </td>
            </tr>
            <tr>
                <th>
                    Languages:
                </th>
                <td>
                    <asp:CheckBoxList runat="server" ID="lang"></asp:CheckBoxList>
                </td>
            </tr>
            <th>Photo:</th>
            <td>

                <asp:FileUpload ID="photoUpload" runat="server" style="margin-top: 2px" />

            </td>
            

        </table>
    
    </div>
        <p>
            <asp:Button ID="Button1" runat="server" OnClick="Button1_Click" Text="Save" />
        </p>
    </form>
</body>
</html>
