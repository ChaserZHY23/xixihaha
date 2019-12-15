using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _20191123
{
    class Program
    {
        static void Main(string[] args)
        {
            char a;
            int t = 0;
            int i = 0;
            int[] b = new int[10] ;
            while (true)
            {
                a = Convert.ToChar(Console.ReadLine());
                if (a == '#')
                {
                    if (t == 1)
                    {
                        Console.WriteLine("{0}", b[i]);
                    }
                    break;
                }
                if (a >= '0' && a <= '9')
                {
                    t = 1;
                    b[i] = b[i] * 10 + (int)(a - 48);
                }
                else
                {
                    if (t == 1)
                    {
                        Console.WriteLine("{0}", b[i]);
                        i++;
                    }
                    t = 0;
                }
            }
            Console.Write("{0}", i + 1);
            Console.Read();
        }
    }
}
