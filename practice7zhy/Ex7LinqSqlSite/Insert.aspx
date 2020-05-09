<%@ Page Language="C#" AutoEventWireup="true" CodeFile="Insert.aspx.cs" Inherits="Insert" %>

<!DOCTYPE html>

<html xmlns="http://www.w3.org/1999/xhtml">
<head runat="server">
<meta http-equiv="Content-Type" content="text/html; charset=utf-8"/>
    <title></title>
    <style type="text/css">
        .auto-style1 {
            width: 338px;
        }
        .auto-style2 {
            width: 82px;
        }
    </style>
</head>
<body>
    <form id="form1" runat="server" submitdisabledcontrols="True">
        <table class="auto-style1" style="width:100%;">
            <tr>
                <td class="auto-style2">分类名：</td>
                <td>
                    <asp:TextBox ID="txtName" runat="server"></asp:TextBox>
                </td>
                <td>&nbsp;</td>
            </tr>
            <tr>
                <td aria-autocomplete="none" class="auto-style2">&nbsp;&nbsp; 描述：</td>
                <td>
                    <asp:TextBox ID="txtDescn" runat="server" Height="71px" TextMode="MultiLine" Width="180px"></asp:TextBox>
                </td>
                <td>&nbsp;</td>
            </tr>
            <tr>
                <td class="auto-style2">
                    <asp:Button ID="btnInsert" runat="server" OnClick="btnInsert_Click" Text="插入" />
                </td>
                <td>
                    <asp:Button ID="btnReturn" runat="server" OnClick="btnReturn_Click" Text="返回" />
                </td>
                <td>&nbsp;</td>
            </tr>
        </table>
    </form>
</body>
</html>
