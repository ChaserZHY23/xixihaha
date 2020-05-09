<%@ Page Language="C#" AutoEventWireup="true" CodeFile="ProShow.aspx.cs" Inherits="ProShow" %>

<!DOCTYPE html>

<html xmlns="http://www.w3.org/1999/xhtml">
<head runat="server">
<meta http-equiv="Content-Type" content="text/html; charset=utf-8"/>
    <title></title>
    <style type="text/css">
        .auto-style1 {
            width: 72px;
        }
        .auto-style3 {
            width: 72px;
            height: 23px;
        }
        .auto-style4 {
            width: 110px;
        }
        .auto-style8 {
            width: 103px;
        }
        .auto-style9 {
            width: 129px;
        }
    </style>
</head>
<body>
    <form id="form1" runat="server">
    <div>
    
        分类名：<asp:DropDownList ID="ddlCategory" runat="server" AutoPostBack="True" DataTextField="Name" DataValueField="CategoryId" OnSelectedIndexChanged="ddlCategory_SelectedIndexChanged">
        </asp:DropDownList>
        <asp:GridView ID="gvProduct" runat="server" AllowPaging="True" AutoGenerateColumns="False" OnPageIndexChanging="gvProduct_PageIndexChanging" PageSize="1" Width="475px">
            <Columns>
                <asp:TemplateField>
                    <ItemTemplate>
                        <table style="width:100%;">
                            <tr>
                                <td class="auto-style4" rowspan="4">
                                    <asp:Image ID="imgProduct" runat="server" Height="61px" ImageAlign="Middle" ImageUrl='<%# Bind("Image") %>' Width="95px" />
                                </td>
                                <td class="auto-style9">商品名称：</td>
                                <td class="auto-style3">
                                    <asp:Label ID="lblName" runat="server" Text='<%# Bind("Name") %>'></asp:Label>
                                </td>
                            </tr>
                            <tr>
                                <td class="auto-style9">商品价格：</td>
                                <td class="auto-style1">
                                    <asp:Label ID="lblListPrice" runat="server" Text='<%# Bind("ListPrice") %>'></asp:Label>
                                </td>
                            </tr>
                            <tr>
                                <td class="auto-style9">商品描述：</td>
                                <td class="auto-style1">
                                    <asp:Label ID="lblDescn" runat="server" Text='<%# Bind("Descn") %>'></asp:Label>
                                </td>
                            </tr>
                            <tr>
                                <td class="auto-style9">库存：</td>
                                <td class="auto-style1">
                                    <asp:Label ID="lblQty" runat="server" Text='<%# Bind("Qty") %>'></asp:Label>
                                </td>
                            </tr>
                        </table>
                    </ItemTemplate>
                </asp:TemplateField>
                <asp:HyperLinkField DataNavigateUrlFields="ProductId" DataNavigateUrlFormatString="~/ShopCart.aspx?ProductId={0}" HeaderText="放入购物车" Text="购买" />
            </Columns>
            <PagerSettings FirstPageText="首页" LastPageText="尾页" Mode="NextPrevious" NextPageText="下一页" Position="TopAndBottom" PreviousPageText="上一页" />
        </asp:GridView>
    
    </div>
    </form>
</body>
</html>
