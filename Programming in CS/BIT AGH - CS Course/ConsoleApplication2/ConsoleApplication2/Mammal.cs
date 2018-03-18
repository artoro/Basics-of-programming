using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApplication2
{
    class Mammal : Animal, IFlyable
    {
        public Mammal(string name, string colour, int age, float weight) :
            base(name, colour, age, weight)
        {
        }

        public void Fly()
        {
            Console.WriteLine("Nie umiem latać :(");
        }
    }
}
