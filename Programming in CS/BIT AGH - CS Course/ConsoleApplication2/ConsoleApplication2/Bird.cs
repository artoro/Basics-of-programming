using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApplication2
{
    class Bird : Animal, IFlyable
    {
        public Bird(string name, string colour, int age, float weight) :
            base(name, colour, age, weight)
        {
        }

        public void Fly()
        {
            Console.WriteLine("^^ Ja latam ^^");
        }
    }
}
