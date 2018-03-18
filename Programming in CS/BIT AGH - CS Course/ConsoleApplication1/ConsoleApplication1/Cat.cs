using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApplication1
{
    public class Cat : Animal
    {
        private string colour;
        private int age;
        private float weight;

        public Cat(string name, string colour, int age, float weight) : base(name) // : bazowy_konstr(args)
        {
            this.colour = colour;
            this.age = age;
            this.weight = weight;
        }

        public void Meow()
        {
            Console.WriteLine("Miau.. " + Name);
        }

        public void Feed(string food)
        {
            float mass = food.Length;
            Console.Write(food + " -> ");
            for (int i = 0; i < food.Length; i++)
            {
                Console.Write("Am.. ");
            }
            Meow();
            weight += mass / 100;
        }
    }
}
