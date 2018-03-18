using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApplication1
{
    public class Animal
    {
        public string Name { get; private set; }

        public Animal(string name)
        {
            Name = name;
        }
    }
}
