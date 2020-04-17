<%@ Page Language="C#" AutoEventWireup="true" CodeFile="BootstrapCss.aspx.cs" Inherits="Ex2_BootstrapCss" %>

<!DOCTYPE html>

<html xmlns="http://www.w3.org/1999/xhtml">
<head runat="server">
<meta http-equiv="Content-Type" content="text/html; charset=utf-8"/>
    <title>利用Bootstrap.css和自定义.css文件进行页面布局</title>
    <link href="../Content/bootstrap.css" rel="stylesheet" />
    <link href="../Styles/Style.css" rel="stylesheet" />
</head>
<body>
    <form id="form1" runat="server">
   <header class="header">
       <asp:Image ID="ImgLogo" runat="server" ImageUrl="~/Images/logo.gif"/>
       <ul class="nav nav-pills">
           <li class="navDark">
            <asp:LinkButton ID="lnkbtnDefaullt" runat="server" ForeColor="White">首页</asp:LinkButton>
           </li>
           <li class ="navDark">
               <asp:LinkButton ID="lnkbtnRegister" runat="server" ForeColor="White">注册</asp:LinkButton>
        
           </li>
           <li class ="navDark">
<asp:LinkButton ID="lnkbtnLogin" runat="server" ForeColor="White">登录</asp:LinkButton>
             
           </li>
           <li class ="navDark">
                   <asp:LinkButton ID="lnkbtnCart" runat="server" ForeColor="White">购物车</asp:LinkButton>
               
           </li>
           <li class ="navDark">
                              <asp:LinkButton ID="lnkbtnSiteMap" runat="server" ForeColor="White">网站地图</asp:LinkButton>
           </li>
       </ul>
       <div class="status">
            登陆状态
       </div>
   </header>
        <nav class="sitemap">
            您的位置:
        </nav>
    </form>
</body>
</html>
