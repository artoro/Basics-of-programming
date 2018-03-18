using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ex5
{
    public class ConcretePerson2 : Person
    {
        public ConcretePerson2(WeatherStation weatherStation, string location) : 
            base(weatherStation, location)
        {
        }
    }
}
