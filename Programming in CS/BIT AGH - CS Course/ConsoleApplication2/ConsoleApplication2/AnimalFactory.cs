using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApplication2
{
    public class AnimalFactory
    {
        public static Animal CreateAnimal(string ID, string name, string colour, int age, float weight)
        {
            Animal a = null;
            switch (ID)
            {
                case "cat":
                    a = new Cat(name, colour, age, weight);
                    break;
                case "dog":
                    a = new Dog(name, colour, age, weight);
                    break;
                case "duck":
                    a = new Duck(name, colour, age, weight);
                    break;
                case "pidgeon":
                    a = new Pidgeon(name, colour, age, weight);
                    break;
            }
            return a;
        }
    }
}
