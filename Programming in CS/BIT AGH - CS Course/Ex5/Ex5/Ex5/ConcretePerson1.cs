using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ex5
{
    public class ConcretePerson1 : Person
    {
        public ConcretePerson1(WeatherStation weatherStation, string location) : 
            base(weatherStation, location)
        {
        }
    }
}
