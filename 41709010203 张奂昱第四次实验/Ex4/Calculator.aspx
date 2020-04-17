﻿<%@ Page Language="C#" AutoEventWireup="true" CodeFile="Calculator.aspx.cs" Inherits="Ex4_Calculator" %>

<!DOCTYPE html>

<html xmlns="http://www.w3.org/1999/xhtml">
<head runat="server">
<meta http-equiv="Content-Type" content="text/html; charset=utf-8"/>
    <title></title>
</head>
<body>
    <form runat="server">
        <div style="text-align: center">
            <asp:TextBox ID="txtDisplay" ReadOnly="true" Width="110px" runat="server"></asp:TextBox><br />
            <asp:Button ID="btnOne" runat="server" Text="1" OnClick="btnOne_Click"  Width="40px" />
            <asp:Button ID="btnTwo" runat="server" Text="2" OnClick="btnTwo_Click" Width="40px"/>
            <asp:Button ID="btnThree" runat="server" Text="3" OnClick="btnThree_Click" Width="40px" /><br />
            <asp:Button ID="btnAdd" runat="server" Text="+"  OnClick="btnAdd_Click"  Width="40px"/>
            <asp:Button ID="btnSubtract" runat="server" Text="-" OnClick="btnSubtract_Click" Width="40px"/>
            <asp:Button ID="btnEqual" runat="server" Text="=" OnClick="btnEqual_Click" Width ="40px" />
        </div>
    </form>
</body>
</html>
