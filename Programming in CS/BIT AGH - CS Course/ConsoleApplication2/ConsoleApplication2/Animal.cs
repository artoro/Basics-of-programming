using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApplication2
{
    public class Animal
    {
        protected string colour;
        protected float weight;
        public int Age { get; private set; }
        public string Name { get; private set; }
        public IFlyable FlyBehaviour;

        public Animal(string name, string colour, int age, float weight)
        {
            this.colour = colour;
            this.weight = weight;
            Age = age;
            Name = name;
        }

        public virtual void MakeSound()
        {
            System.Console.WriteLine("Sound...");
        }
        
        public string GetColour()
        {
            return colour;
        }
    }
}
