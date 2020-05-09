<%@ Page Language="C#" AutoEventWireup="true" CodeFile="Update.aspx.cs" Inherits="Update" %>

<!DOCTYPE html>

<html xmlns="http://www.w3.org/1999/xhtml">
<head runat="server">
<meta http-equiv="Content-Type" content="text/html; charset=utf-8"/>
    <title></title>
    <style type="text/css">
        .auto-style1 {
            width: 96px;
        }
        .auto-style2 {
            width: 96px;
            height: 27px;
        }
        .auto-style5 {
            height: 27px;
            width: 205px;
        }
        .auto-style7 {
            height: 27px;
            width: 372px;
        }
        .auto-style8 {
            width: 205px;
        }
        .auto-style9 {
            width: 372px;
        }
    </style>
</head>
<body>
    <form id="form1" runat="server">
    <div>
    
        <table aria-multiline="True" style="width: 89%;">
            <tr>
                <td class="auto-style1">分类Id：</td>
                <td class="auto-style8">
                    <asp:TextBox ID="txtCategoryId" runat="server"></asp:TextBox>
                </td>
                <td class="auto-style9">&nbsp;</td>
            </tr>
            <tr>
                <td class="auto-style2">分类名：</td>
                <td class="auto-style5">
                    <asp:TextBox ID="txtName" runat="server"></asp:TextBox>
                </td>
                <td aria-atomic="True" class="auto-style7"></td>
            </tr>
            <tr>
                <td class="auto-style1">&nbsp;描述：&nbsp;</td>
                <td class="auto-style8">
                    <asp:TextBox ID="txtDescn" runat="server" Height="89px" TextMode="MultiLine"></asp:TextBox>
                </td>
                <td class="auto-style9">
                    <br aria-atomic="True" />
                    <br />
                </td>
            </tr>
        </table>
    
    </div>
        <asp:Button ID="btnUpdate" runat="server" OnClick="btnUpdate_Click" Text="修改" />
        <asp:Button ID="btnReturn" runat="server" OnClick="btnReturn_Click" Text="返回" />
    </form>
</body>
</html>
