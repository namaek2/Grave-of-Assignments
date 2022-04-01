using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using _3.Interface_and_Inheritance.Interfaces;

namespace _3.Interface_and_Inheritance.Classes
{
    internal class Circle:Shape
    {
        private int r;

        public int R;
        public Circle(int r)
        {
            R = r;
        }
        double Shape.perimeter()
        {
            return (R + R) * 3.14; 
        }

        double Shape.area()
        {
            return R * R * 3.14;
        }
    }
    
    
}

using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using _3.Interface_and_Inheritance.Interfaces;

namespace _3.Interface_and_Inheritance.Classes
{
    internal class Rectangle : Shape
    {
        private int w;
        private int h;

        public int W;
        public int H;
        public Rectangle(int w, int h)
        {
            W = w;
            H = h;
        }
        double Shape.perimeter()
        {
            return (W + H) * 2;
        }

        double Shape.area()
        {
            return W * H;
        }
    }
}

using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _3.Interface_and_Inheritance.Interfaces
{
    internal interface Shape
    {
        double perimeter();
        double area();
    }
}


using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using _3.Interface_and_Inheritance.Classes;
using _3.Interface_and_Inheritance.Interfaces;

namespace _3.Interface_and_Inheritance
{
    internal class Program
    {
        static void Main(string[] args)
        {
            int w, h, r;
            w = Convert.ToInt32(Console.ReadLine());
            h = Convert.ToInt32(Console.ReadLine());
            r = Convert.ToInt32(Console.ReadLine());
            Shape Rect = new Rectangle(w, h);
            Shape Circ = new Circle(r);
            Console.WriteLine("Rectangle Perimeter : " + Rect.perimeter().ToString());
            Console.WriteLine("Rectangle Area : " + Rect.area().ToString());
            Console.WriteLine("Circle Perimeter : " + Circ.perimeter().ToString());
            Console.WriteLine("Circle Area : " + Circ.area().ToString());
        }
    }
}
