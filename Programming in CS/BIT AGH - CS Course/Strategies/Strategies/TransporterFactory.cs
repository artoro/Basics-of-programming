using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Strategies
{
    class TransporterFactory
    {
        public ITransportable Create(TransporterType type)
        {
            ITransportable transport = null;
            switch (type)
            {
                case TransporterType.Bus:
                    transport = new TransportByBus();
                    break;
                case TransporterType.Bike:
                    transport = new TransportByBike();
                    break;
            }
            return transport;
        }
    }
}
