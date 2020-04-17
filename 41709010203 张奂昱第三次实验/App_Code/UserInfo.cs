using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;

/// <summary>
/// UserInfo 的摘要说明
/// </summary>
public class UserInfo
{
    private string _Name;
    private DateTime _Birthday;
    public string Name
    {
        get { return _Name; }
        set { _Name = value; }
    }
    public DateTime Birthday
    {
        get { return _Birthday; }
        set { _Birthday = value; }
    }
    public UserInfo(string name,DateTime birthday)
    {
        this._Name = name;
        this._Birthday = birthday;
        //
        // TODO: 在此处添加构造函数逻辑
        //
    }
    public string DecideAge()
    {
        if (DateTime.Now.Year-_Birthday.Year<18)
        {
            return this._Name + ",您还没长大呢？";
        }
        else
        {
            return this._Name + ",您是成人了！";
        }
    }
}