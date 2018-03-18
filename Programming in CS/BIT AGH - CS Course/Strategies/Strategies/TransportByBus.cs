using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Controls;

namespace Strategies
{
    class TransportByBus : ITransportable
    {
        public void Transport(Label label)
        {
            label.Content = "Transport by bus.";
        }
    }
}
