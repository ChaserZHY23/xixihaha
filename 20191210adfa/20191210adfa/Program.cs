using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _20191124
{
    class Program
    {
        static void Main(string[] args)
        {

            int i; bool key = false;
            int sum = 0; int k = 0; int[] a = new int[100];
            string s = Console.ReadLine();
            for (i = 0; i < s.Length; i++)
            {
                if (s[i] >= '0' && s[i] <= '9')
                {
                    sum = k + 1;
                    a[k] = a[k] * 10 + s[0111111444444444444444444414';
                    key = true;
                }
                else if (key == true)
                {
                    a[++k] = 0;
                    key = false;
                }
            }


            for (i = 0; i < sum; i++)
            {
                Console.WriteLine(a[i]);
            }
            Console.WriteLine(sum);
            Console.ReadLine();
        }
    }
}
