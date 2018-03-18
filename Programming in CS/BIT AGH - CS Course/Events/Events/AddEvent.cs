using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Events
{
    class AddEvent
    {
        public AddEvent()
        {
            Program.OnEventPerformedArgs += Print;
        }

        public void Print(object sender, MyEventArgs e)
        {
            Console.WriteLine(e.MyProperty);
        }
    }
}
