using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _20191119b
{
    class Program
    {
        static void Main(string[] args)
        {
            int i, j;
            for(i=0;i<10;i++)
            {
                j = i * 10 + 6;
                if(j%3!=0)
                {
                    continue;
                }
                Console.WriteLine("{0}", j);
            }
            Console.Read();
        }
    }
}
