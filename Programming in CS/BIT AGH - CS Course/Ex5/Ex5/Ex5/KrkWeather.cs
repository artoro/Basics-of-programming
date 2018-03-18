using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ex5
{
    public class KrkWeather : IWeather
    {
        public event EventHandler<WeatherEventArgs> OnWeatherChanged;

        public void ChangeWeather(string location)
        {
            if (location == "Warsaw")
                return;
            if (OnWeatherChanged != null)
            {
                OnWeatherChanged(this, new WeatherEventArgs()
                {
                    Location = "Krk",
                    Temperature = 31,
                    Weather = WeatherType.cloudy                    
                });
            }
        }
    }
}
