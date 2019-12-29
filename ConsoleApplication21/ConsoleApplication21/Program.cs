using System;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApplication4
{
    class Program
    {
        static void Main(string[] args)
        {
            Cperson cp1 = new Cperson();
            cp1.output_data();
            Cperson cp2 = new Cperson("小王", 10001, "男");
            cp2.output_data();
            CStudent cs1 = new CStudent();
            cs1.output_data();
            CStudent cs2 = new CStudent("小李", 10002, "男", 100);
            cs2.output_data();
            CTeacher ct1 = new CTeacher();
            ct1.output_data();
            CTeacher ct2 = new CTeacher("小陈", 10003, "女", 32);
            ct2.output_data();
            Console.ReadLine();
        }
    }
    class Cperson
    {
        private string name;
        private int number;
        private string sex;
        public Cperson(string name1, int number1, string sex1)
        {
            name = name1; number = number1; sex = sex1;
        }
        public Cperson()
        {
            name = ""; number = 0; sex = "";
        }
        public virtual void input_data()
        {
            Console.WriteLine("请输入您的姓名：");
            string name = Console.ReadLine();
            set_name(name);
            Console.WriteLine("请输入您的姓别：");
            string sex = Console.ReadLine(); set_sex(sex);
            Console.WriteLine("请输入您的编号：");
            int number = int.Parse(Console.ReadLine());
            set_number(number);
        }
        public virtual void output_data()
        {
            //Console.WriteLine("您的姓名为：{0}  ","您的编号为：{1}  ","您的性别为：{2}",this.get_name(),this.get_number(),this.get_sex());  
            Console.WriteLine("您的姓名为：{0}   您的编号为：{1}   您的性别为：{2}", this.get_name(), this.get_number(), this.get_sex());
            Console.WriteLine();
        }
        public string get_name()
        {
            return name;
        }
        public int get_number()
        {
            return number;
        }
        public string get_sex()
        {
            return sex;
        }
        public void set_name(string name1)
        {
            name = name1;
        }
        public void set_number(int number1)
        {
            number = number1;
        }
        public void set_sex(string sex1)
        {
            sex = sex1;
        }
    }
    class CStudent : Cperson
    {
        public double score;
        public CStudent(string name1, int number1, string sex1, double score1) : base(name1, number1, sex1)
        {
            score = score1;
        }
        public CStudent() : base()
        {
            score = 0;
        }
        public double get_score()
        {
            return score;
        }
        public void set_score(double score1)
        {
            score = score1;
        }
        public override void input_data()
        {
            Console.WriteLine("请输入学生的姓名：");
            string name = Console.ReadLine();
            set_name(name);
            Console.WriteLine("请输入学生的姓别：");
            string sex = Console.ReadLine();
            set_sex(sex);
            Console.WriteLine("请输入学生的编号：");
            int number = int.Parse(Console.ReadLine());
            set_number(number);
            Console.WriteLine("请输入学生的成绩：");
            double score = double.Parse(Console.ReadLine());
            set_score(score);
        }
        public override void output_data()
        {
            //Console.WriteLine("学生的姓名为：{0}", this.get_name(), "学生的编号为：{1}", this.get_number(), "学生的性别为：{2}", this.get_sex(), "学生的成绩为：{3}", this.get_score());    
            Console.WriteLine("学生的姓名为：{0}  学生的编号为：{1}  学生的性别为：{2}  学生的成绩为：{3}", this.get_name(), this.get_number(), this.get_sex(), this.get_score());
            Console.WriteLine();
        }
    }
    class CTeacher : Cperson
    {
        public int teach_age;
        public CTeacher(string name1, int number1, string sex1, int teach_age1) : base(name1, number1, sex1)
        {
            teach_age = teach_age1;
        }
        public CTeacher() : base()
        {
            teach_age = 0;
        }
        public int get_teach_age()
        {
            return teach_age;
        }
        public void set_teach_age(int teach_age1)
        {
            teach_age = teach_age1;
        }
        public override void input_data()
        {
            Console.WriteLine("请输入老师的姓名：");
            string name = Console.ReadLine();
            set_name(name);
            Console.WriteLine("请输入老师的姓别：");
            string sex = Console.ReadLine();
            set_sex(sex);
            Console.WriteLine("请输入老师的编号：");
            int number = int.Parse(Console.ReadLine());
            set_number(number);
            Console.WriteLine("请输入老师的教龄：");
            int teach_age = int.Parse(Console.ReadLine());
            set_teach_age(teach_age);
        }
        public override void output_data()
        {
            //Console.WriteLine("老师的姓名为：{0}", this.get_name(), "老师的编号为：{1}", this.get_number(), "老师的性别为：{2}",this.get_number(),  "老师的教龄为：{3}", this.get_teach_age());    
            Console.WriteLine("老师的姓名为：{0}  老师的编号为：{1}  老师的性别为：{2}  老师的教龄为：{3}", this.get_name(), this.get_number(), this.get_number(), this.get_teach_age());
            Console.WriteLine();
        }
    }
}