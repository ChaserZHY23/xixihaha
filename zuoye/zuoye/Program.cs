using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace zuoye
{
    class Program
    {
        static void Main(string[] args)
        {
            //int x, y, z;
            //bool s;
            //x = y = z = 0;
            //s = x++ != 0 || ++y != 0 && ++y != 0;
            //Console.WriteLine("x={0},y={1},z={2},s={3}", x, y, z, s);
            //Console.Read();
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
