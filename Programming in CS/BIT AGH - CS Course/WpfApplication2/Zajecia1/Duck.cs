using System;

namespace Zajecia1
{
    class Duck : Animal, IFlyable
    {
        public Duck(string name, int weight, int age, string color) : base(name, weight, age, color)
        {
        }

        public void Fly()
        {
            Console.WriteLine("I'm flying");
        }
    }
}
