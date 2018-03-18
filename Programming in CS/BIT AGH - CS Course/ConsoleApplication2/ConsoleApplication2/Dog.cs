using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApplication2
{
    public class Dog : Animal
    {
        public Dog(string name, string colour, int age, float weight) :
            base(name, colour, age, weight)
        {
        }

        public override void MakeSound()
        {
            Console.WriteLine("Hau.. ");
        }
    }
}
