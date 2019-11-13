using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _20191112d
{
    class CRect
    {
        private int top, bottom, left, right;
        private static int total_rects = 0;
        private static long total_rect_area = 0;
        public CRect()
        {
            left = top = right = bottom = 0;
            total_rects++;
            total_rect_area += getHeight() * getWidth();
            Console.WriteLine("CRect()Constructing rectange number:{0}", total_rects);
            Console.WriteLine("Total rectangle areas is:{0}", total_rect_area);
        }
        public CRect(int x1, int y1, int x2, int y2)
        {
            left = x1; top = y1;
            right = x2; bottom = y2;
            total_rects++;
            total_rect_area += getHeight() * getWidth();
            Console.WriteLine("CRect(int,int,int,int)Constructing rectangle number{0}", total_rects);
            Console.WriteLine("Total rectangle areas is:{0}", total_rect_area);
        }
        public CRect(CRect r)
        {
            left = r.left; right = r.right;
            top = r.top; bottom = r.bottom;
            total_rects++;
            total_rect_area += getHeight() * getWidth();
            Console.WriteLine("CRect(CRect&)Constructing rectangle number{0}", total_rects);
            Console.WriteLine("Total rectangle areas is:{0}", total_rect_area);
        }
        public int getHeight()
        {
            return top > bottom ? top - bottom : bottom - top;
        }
        public int getWidth()
        {
            return right > left ? right - left : left - right;
        }
        public static int getTotalRects()
        {
            return total_rects;
        }
        public static long getTotalRectArea()
        {
            return total_rect_area;
        }
        class _20191112d
        {
            static void Main(string[] args)
            {
                CRect rect1 = new CRect(1, 3, 6, 4), rect2 = new CRect(rect1);
                Console.Write("Rectangle2:Height:{0}", rect2.getHeight());
                Console.WriteLine(",Width:{0}", rect2.getWidth());
                {
                    CRect rect3 = new CRect();
                    Console.Write("Rectangle3:Height :{0}", rect3.getHeight());
                    Console.WriteLine(",Width:{0}", rect3.getWidth());
                }
                Console.Write("total_rects={0},", CRect.total_rects);
                Console.WriteLine("Total_rect_area={0}", CRect.total_rect_area);
                Console.Read();
            }
        }
    }
}
