using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _20191112c
{
    interface IEnglishDimensions
    {
        float Length();
        float Width();
    }
    interface IMetricDimensions
    {
        float Length();
        float Width();
    }
    class Box : IEnglishDimensions, IMetricDimensions
    {
        float lengthInches;
        float widthInches;
        public Box(float length,float width)
            { lengthInches=length;
            widthInches=width;
            }
        float IEnglishDimensions.Length()
        {
            return lengthInches;
        }
        float IEnglishDimensions.Width()
        {
            return widthInches;
        }
        float IMetricDimensions.Length()
        {
            return lengthInches * 2.54f;
        }
        float IMetricDimensions.Width()
        {
            return widthInches * 2.54f;
        }
        static void Main(string[] args)
        {
            Box myBox = new Box(30.0f, 20.0f);
            IEnglishDimensions eDimensions = (IEnglishDimensions)myBox;
            IMetricDimensions mDimensions = (IMetricDimensions)myBox;
            Console.WriteLine("Length(in):{0}:", eDimensions.Length());
            Console.WriteLine("Width(in):{0}:", eDimensions.Width());
            Console.WriteLine("Length(cm):{0}:", mDimensions.Length());
            Console.WriteLine("Width(cm):{0}:", mDimensions.Width());
            Console.Read();
        }
    }
}
