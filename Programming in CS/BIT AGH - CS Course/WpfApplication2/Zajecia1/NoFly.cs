using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Zajecia1
{
    public class NoFly : IFlyable
    {
        public void Fly()
        {
            Console.WriteLine("Not flying");
        }
    }
}
