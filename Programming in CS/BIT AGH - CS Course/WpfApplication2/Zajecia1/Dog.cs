using System;

namespace Zajecia1
{
    public class Dog : Animal
    {


        public Dog(string name, string color, int weight, int age) :
            base(name, weight, age, color, new NoFly())
        {
            Console.WriteLine("Dog created");
        }

        public override void MakeSound()
        {
            Console.WriteLine("Bark!");
        }
    }
}
