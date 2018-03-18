using System;

namespace Zajecia1
{
    public class Cat : Animal
    {

        public Cat(string name, string colour, int weight, int age) : base(name, weight, age, colour)
        {
            Console.WriteLine("Cat created");
        }

        public override void MakeSound()
        {
            Console.WriteLine("Meow...");
        }

    }
}
