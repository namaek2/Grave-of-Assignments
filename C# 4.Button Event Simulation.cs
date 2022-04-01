using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _4.Button_Event_Simulation.Classes
{
    delegate void ButtonClick(string a);
    internal class Button
    {
        public event ButtonClick callback;

        private int x;
        private int y;
        private int height;
        private int width;
        private string name;

        public int X;
        public int Y;
        public int Height;
        public int Width;
        public string Name;

        public Button(int x, int y,  int height, int width, string name)
        {
            X = x;
            Y = y;
            Height = height;
            Width = width;
            Name = name;
        }
        public void MouseClickedAt(int xpos, int ypos)
        {
            if(xpos>=X && xpos<=X+Height && ypos>=Y && ypos<=Y+Width)
            {
                callback(Name);
            }
        }
    }
}

using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using _4.Button_Event_Simulation.Classes;

namespace _4.Button_Event_Simulation
{
    class Program
    {

        static void Function1(string buttonName)
        {

            Console.WriteLine(buttonName + "에서 함수 1 실행됨");

        }
        static void Function2(string buttonName)
        {

            Console.WriteLine(buttonName + "에서 함수 2 실행됨");

        }
        static void Main(string[] args)
        {

            Button button1 = new Button(10, 10, 100, 50, "버튼1");
            Button button2 = new Button(10, 100, 100, 50, "버튼2");
            button1.callback += Function1;
            button2.callback += Function2;
            button1.MouseClickedAt(5, 5);
            button1.MouseClickedAt(15, 20);
            button2.MouseClickedAt(20, 130);
            button1.callback -= Function1;
            button1.callback += Function2;
            button2.callback -= Function2;
            button2.callback += Function1;
            button1.MouseClickedAt(5, 5);
            button1.MouseClickedAt(15, 20);
            button2.MouseClickedAt(20, 130);
        }
    }
}
