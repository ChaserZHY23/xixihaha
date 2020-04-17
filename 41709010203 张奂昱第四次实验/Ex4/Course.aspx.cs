using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;

public partial class Ex4_Course : System.Web.UI.Page
{
    protected void Page_Load(object sender, EventArgs e)
    {
        if(!IsPostBack)
        {
            BindYear();
            BindTerm();
            BindCollege();
            BindTeacher();
        }
    }
    protected void BindYear()
    {
        ddlYear.Items.Clear();
        int startYear = DateTime.Now.Year - 10;
        int currentYear = DateTime.Now.Year;
        for(int i=startYear;i<=currentYear;i++)
        {
            ddlYear.Items.Add(new ListItem((i - 1).ToString() + "-" + i.ToString()));
        }
        ddlYear.SelectedValue = (currentYear - 1).ToString() + "-" + currentYear.ToString();
    }
    protected void BindTerm()
    {
        ddlTerm.Items.Clear();
        for(int i=1;i<=2;i++)
        {
            ddlTerm.Items.Add(i.ToString());
        }
    }
    protected void BindCollege()
    {
        ddlCollege.Items.Clear();
        ddlCollege.Items.Add(new ListItem("计算机学院"));
        ddlCollege.Items.Add(new ListItem("外国语学院"));
        ddlCollege.Items.Add(new ListItem("机电学院"));
    }
    protected void ddlCollege_SelectedIndexChanged(object sender,EventArgs e)
    {
        BindTeacher();
    }
    protected void BindTeacher()
    {
        ddlTeacher.Items.Clear();
        switch (ddlCollege.SelectedValue)
        {
            case "计算机学院":
                ddlTeacher.Items.Add(new ListItem("张三"));
                ddlTeacher.Items.Add(new ListItem("张三12"));
                ddlTeacher.Items.Add(new ListItem("张三212"));
                break;
            case "外国语学院":
                  ddlTeacher.Items.Add(new ListItem("张三21212"));
                ddlTeacher.Items.Add(new ListItem("张三2122"));
                ddlTeacher.Items.Add(new ListItem("张三31313213"));
                break;
            case "机电学院":
                  ddlTeacher.Items.Add(new ListItem("张三1313131"));
                ddlTeacher.Items.Add(new ListItem("张三1313133"));
                break;
        }
    }
}