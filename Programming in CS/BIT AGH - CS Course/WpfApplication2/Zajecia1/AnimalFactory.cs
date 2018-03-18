using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Zajecia1
{
    public class AnimalFactory {
        public Animal CreateAnimal(string id, int w, int a, string n, string c)
        {
            Animal res = null;
            switch (id)
            {
                case "cat": 
                    {
                        res = new Cat(n, c, w, a);
                        break;
                    }
                case "dog":
                    {
                        res = new Dog(n, c, w, a);
                        break;
                    }

            }
            return res;
        }
    }
}
