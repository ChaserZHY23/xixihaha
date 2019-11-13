    using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _20191112
{
    interface IEnglishDimensions
    {
        float Length();
        float Width();
    }
    interface IMetricDimensions
    {
        float Legth();
        float Width();
    }
    class Box : IEnglishDimensions, IMetricDimensions
    {
        float lengthInches;
        float WidthInches;
        public Box(float length; float width)
     {  
            lengthInches=length;
            widthInches=width;
      }
    float IE










        static void Main(string[] args)
        {

        }
    }
}
