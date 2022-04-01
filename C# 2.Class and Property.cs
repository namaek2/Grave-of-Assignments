using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _2.Class_and_Property.Classes
{
    class Person
    {
        private int height;

        public int Height
        {
            get
            {
                return height;
            }

            set
            {
                if (value < 0)
                {
                    Console.WriteLine("0보다 작은 값을 대입할 수 없습니다!");
                    return;
                }

                height = value;
            }
        }

        public int Weight;
        public string Name;

        public Person(int height, int weight, string name)
        {
            Height = height;
            Weight = weight;
            Name = name;
        }
        public void Greetings(Person person)
        {
            Console.WriteLine("안녕하세요 " + person.Name + "!");
        }
    }
}

using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using _2.Class_and_Property.Classes;

namespace _2.Class_and_Property
{
    internal class Program
    {
        static void Main(string[] args)
        {
            Person theGoodGuy = new Person(190, 80, "Good Guy");
            Person theBadGuy = new Person(170, 80, "Bad Guy");
            theGoodGuy.Height = -10;
            Console.WriteLine(theBadGuy.Height);
            Console.WriteLine(theGoodGuy.Height);
            theGoodGuy.Greetings(theBadGuy);
            theBadGuy.Greetings(theGoodGuy);
        }

        
    }
}
