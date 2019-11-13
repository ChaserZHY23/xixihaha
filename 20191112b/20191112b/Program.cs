using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _20191112b
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
    float IEnglishDimensions
        static void Main(string[] args)
        {
        }
    }
}
