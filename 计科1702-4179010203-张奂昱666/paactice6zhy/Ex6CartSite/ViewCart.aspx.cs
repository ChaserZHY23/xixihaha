using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;

public partial class ViewCart : System.Web.UI.Page
{
    protected void Page_Load(object sender, EventArgs e)
    {
        if (!IsPostBack)
        {
            if (Session["cart"] == null)
            {
                IbIMsg.Text = "没有选购任何宠物!";
                btnClear.Enabled = false;
            }
            else
            {
                String strpets = Session["cart"].ToString();
                System.Collections.ArrayList pets = new System.Collections.ArrayList();
                int iposition = strpets.IndexOf(",");
                while (iposition != -1)
                {
                    String strpet = strpets.Substring(0, iposition);
                    if (strpet != "")
                    {
                        pets.Add(strpet);
                        strpets = strpets.Substring(iposition + 1);
                        iposition = strpets.IndexOf(",");
                    }
                }
                IbIMsg.Text = "购物车中现有宠物";
                chklsPet.DataSource = pets;
                chklsPet.DataBind();
            }
        }
    }
    protected void btnClear_Click(object sender, EventArgs e)
    {
        Session.Remove("cart");
        IbIMsg.Text = "没有选购任何宠物!";
        chklsPet.Visible = false;
        btnClear.Enabled = false;
    }
    protected void btnContinue_Click(object sender, EventArgs e)
    {
        Response.Redirect("Default.aspx");
    }
}