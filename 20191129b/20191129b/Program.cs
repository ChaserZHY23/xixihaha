using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Exel
{
    enum MonthName
    {
        January, February, March, April, May, June, July, August, September, October, November, December
    }
    class Program
    {
        static System.Collections.ICollection daysInMonth = new int[12] { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
        static void Main(string[] args)
        {
            try
            {
                Console.Write("Please input a day number between 1 and 356:");
                string line = Console.ReadLine();
                int dayNum = int.Parse(line);
                if (dayNum < 1 || dayNum > 365)
                {
                    throw new ArgumentOutOfRangeException("Day out of Range!");
                }
                int monthNum = 0;
                foreach (int daysInMonth in daysInMonth)
                {
                    if (dayNum <= daysInMonth)
                    {
                        break;
                    }
                    else
                    {
                        dayNum -= daysInMonth;
                        monthNum++;
                    }
                }
                MonthName temp = (MonthName)monthNum;
                string monthName = Enum.Format(typeof(MonthName), temp, "g");
                Console.WriteLine("{0} {1}", dayNum, monthName);
                Console.Read();
            }
            catch (Exception caught)
            {
                Console.WriteLine(caught);
            }
        }


    }
}