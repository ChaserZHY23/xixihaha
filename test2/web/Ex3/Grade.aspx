﻿<%@ Page Language="C#" AutoEventWireup="true" CodeFile="Grade.aspx.cs" Inherits="Ex3_Grade" %>

<!DOCTYPE html>

<html xmlns="http://www.w3.org/1999/xhtml">
<head runat="server">
<meta http-equiv="Content-Type" content="text/html; charset=utf-8"/>
    <title></title>
</head>
<body>
    <form id="form1" runat="server">
    <div>
    
        <asp:TextBox ID="txtinput" runat="server"></asp:TextBox>
        <asp:Button ID="BtnSubmit" runat="server" OnClick="BtnSubmit_Click" Text="等级" />
        <asp:Label ID="lblDisplay" runat="server"></asp:Label>
    
    </div>
    </form>
</body>
</html>
