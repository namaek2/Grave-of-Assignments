using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows;
using static System.Math;

namespace WpfApp1.Classes
{
    internal class SimpleMath
    {
        public static double Add(double n1, double n2)
        {
            return n1 + n2;
        }
        public static double Sub(double n1, double n2)
        {
            return n1 - n2;
        }
        public static double Mul(double n1, double n2)
        {
            return n1 * n2;
        }

        public static double Root(double n1)
        {
            if (n1 < 0)
            {
                MessageBox.Show("음수입니다.");
                return 0;
            }
            return Sqrt(n1);
        }

        public static double Sqrd(double n1)
        {
            return n1 * n1;
        }

        public static double Divx(double n1)
        {
            return 1 / n1;
        }
            

        public static double Div(double n1, double n2)
        {
            if(n2 == 0)
            {
                MessageBox.Show("0으로 나눌 수 없습니다.");
                return 0;
            }
            else
                return n1 / n2;
        }

    }
}
