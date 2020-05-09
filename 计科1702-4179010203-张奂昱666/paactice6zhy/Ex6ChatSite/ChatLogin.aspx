<%@ Page Language="C#" AutoEventWireup="true" CodeFile="ChatLogin.aspx.cs" Inherits="ChatLogin" %>

<!DOCTYPE html>

<html xmlns="http://www.w3.org/1999/xhtml">
<head runat="server">
<meta http-equiv="Content-Type" content="text/html; charset=utf-8"/>
    <title></title>
<style type="text/css">
        .auto-style1 {
            width: 69%;
        }
        .auto-style2 {
        width: 188px;
    }
        .auto-style3 {
        width: 353px;
    }
    .auto-style4
    {
        width: 353px;
        height: 24px;
    }
    .auto-style5
    {
        width: 188px;
        height: 24px;
    }
    .auto-style6
    {
        height: 24px;
    }
    </style>
</head>
<body>
    <form id="form1" runat="server">
        <table class="auto-style1">
            <tr>
                <td class="auto-style4"></td>
                <td class="auto-style5" style="text-align: center">我的聊天室</td>
                <td class="auto-style6"></td>
            </tr>
            <tr>
                <td class="auto-style3" style="text-align: right">用户名：</td>
                <td class="auto-style2">
                    <asp:TextBox ID="txtName" runat="server" Width="187px"></asp:TextBox>
                </td>
                <td>
                    <asp:RequiredFieldValidator ID="rfvName" runat="server" ControlToValidate="txtName" ErrorMessage="RequiredFieldValidator">*</asp:RequiredFieldValidator>
                </td>
            </tr>
            <tr>
                <td class="auto-style3" style="text-align: right">密码：</td>
                <td class="auto-style2">
                    <asp:TextBox ID="txtPassword" runat="server" TextMode="Password" Width="188px"></asp:TextBox>
                </td>
                <td>
                    <asp:RequiredFieldValidator ID="rfvPassword" runat="server" ControlToValidate="txtPassword" ErrorMessage="RequiredFieldValidator">*</asp:RequiredFieldValidator>
                </td>
            </tr>
            <tr>
                <td class="auto-style3">&nbsp;</td>
                <td class="auto-style2">
                    <asp:Button ID="btnLogin" runat="server" OnClick="btnLogin_Click" Text="登录" />
                </td>
                <td>&nbsp;</td>
            </tr>
        </table>
    </form>
</body>
</html>
