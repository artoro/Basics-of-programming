using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ex5
{
    public class WarsawWeather : IWeather
    {
        public event EventHandler<WeatherEventArgs> OnWeatherChanged;

        public void ChangeWeather(string location)
        {
            if (location == "Krk")
                return;

            if (OnWeatherChanged != null)
            {
                OnWeatherChanged(this, new WeatherEventArgs()
                {
                    Location = "Warsaw",
                    Temperature = 10,
                    Weather = WeatherType.sunny
                });
            }
        }
    }
}
