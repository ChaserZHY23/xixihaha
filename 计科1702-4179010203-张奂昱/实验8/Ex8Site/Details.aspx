<%@ Page Language="C#" AutoEventWireup="true" CodeFile="Details.aspx.cs" Inherits="Details" %>

<!DOCTYPE html>

<html xmlns="http://www.w3.org/1999/xhtml">
<head runat="server">
<meta http-equiv="Content-Type" content="text/html; charset=utf-8"/>
    <title></title>
</head>
<body>
    <form id="form1" runat="server">
    <div>
    
        <asp:DetailsView ID="dvProduct" runat="server" AllowPaging="True" AutoGenerateRows="False" DataKeyNames="ProductId" DataSourceID="ldsProduct" Height="101px" Width="207px">
            <Fields>
                <asp:BoundField DataField="ProductId" HeaderText="ProductId" InsertVisible="False" ReadOnly="True" SortExpression="ProductId" />
                <asp:TemplateField HeaderText="CategoryId" SortExpression="CategoryId">
                    <EditItemTemplate>
                        <table cellpadding="0" cellspacing="0" style="margin:5px 0px; border:1px solid #A0A0A0;width:100%;height:100%">
                            <tr style="">
                                <td style="padding:4px;height:50px;vertical-align:top;">
                                    <asp:DropDownList ID="ddlCategoryId" runat="server" DataSourceID="ldsCategory" DataTextField="Name" DataValueField="CategoryId">
                                    </asp:DropDownList>
                                </td>
                            </tr>
                        </table>
                    </EditItemTemplate>
                    <InsertItemTemplate>
                        <asp:DropDownList ID="ddlCategoryId" runat="server" DataSourceID="ldsCategory" DataTextField="Name" DataValueField="CategoryId">
                        </asp:DropDownList>
                    </InsertItemTemplate>
                    <ItemTemplate>
                        <asp:Label ID="lblCategoryId" runat="server" Text='<%# Bind("CategoryId") %>'></asp:Label>
                    </ItemTemplate>
                </asp:TemplateField>
                <asp:BoundField DataField="ListPrice" HeaderText="ListPrice" SortExpression="ListPrice" />
                <asp:BoundField DataField="UnitCost" HeaderText="UnitCost" SortExpression="UnitCost" />
                <asp:TemplateField HeaderText="SuppId" SortExpression="SuppId">
                    <EditItemTemplate>
                        <asp:DropDownList ID="ddlSuppId" runat="server" DataSourceID="ldsSupplier" DataTextField="NAME" DataValueField="SuppId">
                        </asp:DropDownList>
                    </EditItemTemplate>
                    <InsertItemTemplate>
                        <asp:DropDownList ID="ddlSuppId" runat="server" DataSourceID="ldsSupplier" DataTextField="NAME" DataValueField="SuppId">
                        </asp:DropDownList>
                    </InsertItemTemplate>
                    <ItemTemplate>
                        <asp:Label ID="lblSuppId" runat="server" Text='<%# Bind("SuppId") %>'></asp:Label>
                    </ItemTemplate>
                </asp:TemplateField>
                <asp:BoundField DataField="Name" HeaderText="Name" SortExpression="Name" />
                <asp:BoundField DataField="Descn" HeaderText="Descn" SortExpression="Descn" />
                <asp:BoundField DataField="Image" HeaderText="Image" SortExpression="Image" />
                <asp:BoundField DataField="Qty" HeaderText="Qty" SortExpression="Qty" />
                <asp:CommandField ShowDeleteButton="True" ShowEditButton="True" ShowInsertButton="True" />
            </Fields>
        </asp:DetailsView>
        <asp:LinqDataSource ID="ldsProduct" runat="server" ContextTypeName="MyPetShopDataContext" EnableDelete="True" EnableInsert="True" EnableUpdate="True" EntityTypeName="" TableName="Product">
        </asp:LinqDataSource>
        <asp:LinqDataSource ID="ldsCategory" runat="server" ContextTypeName="MyPetShopDataContext" EntityTypeName="" Select="new (CategoryId, Name)" TableName="Category">
        </asp:LinqDataSource>
        <asp:LinqDataSource ID="ldsSupplier" runat="server" ContextTypeName="MyPetShopDataContext" EntityTypeName="" Select="new (SuppId, NAME)" TableName="Supplier">
        </asp:LinqDataSource>
    
    </div>
    </form>
</body>
</html>
