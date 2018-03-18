using System;

namespace ConsoleApplication2
{
    class Duck : Bird
    {
        public Duck(string name, string colour, int age, float weight) :
            base(name, colour, age, weight)
        {
        }

        public override void MakeSound()
        {
            Console.WriteLine("Kwa.. ");
        }
    }
}
