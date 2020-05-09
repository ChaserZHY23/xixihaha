using System;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;

public partial class DataManage : System.Web.UI.Page
{
    MyPetShopDataContext db = new MyPetShopDataContext();
    protected void Page_Load(object sender, EventArgs e)
    {

    }
    protected void Bind() //本行应 自行输入
    {
        var results = from c in db.Category
                      select c;
        gvCategory.DataSource = results;
        gvCategory.DataBind();

    }
    protected void btnQueryAll_Click(object sender, EventArgs e)
    {
        Bind();
    }
    protected void btnFuzzy_Click1(object sender, EventArgs e)
    {
        Response.Redirect("FuzzyQuery.aspx");
    }
    protected void btnInsert_Click1(object sender, EventArgs e)
    {
        Response.Redirect("Insert.aspx");
    }
    protected void btnUpdate_Click1(object sender, EventArgs e)
    {
        Response.Redirect("Update.aspx?CategoryId=" + txtCategoryId.Text);
    }
    protected void btnDelete_Click1(object sender, EventArgs e)
    {
        var results = from c in db.Category
                      where c.CategoryId == int.Parse(txtCategoryId.Text)
                      select c;
        db.Category.DeleteAllOnSubmit(results);
        //db.Category.DeleteAllOnSubmit(results);
        db.SubmitChanges();
        Bind(); //调用自定 义方法，在gvCategory中显示Category表的最新结果
    }
}