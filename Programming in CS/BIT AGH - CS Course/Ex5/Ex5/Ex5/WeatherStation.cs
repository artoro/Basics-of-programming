using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ex5
{
    public class WeatherStation
    {
        public List<IWeather> WeatherList;

        public EventHandler<WeatherEventArgs> CracowWeatherChanged;
        public EventHandler<WeatherEventArgs> WarsawWeatherChanged;

        public WeatherStation()
        {
            WeatherList = new List<IWeather>
            {
                new KrkWeather(),
                new WarsawWeather()
            };
            Init();
        }

        private void Init()
        {
            foreach(var elem in WeatherList)
            {
                elem.OnWeatherChanged += OnWeatherChange;
            }
        }

        private void OnWeatherChange(object sender, WeatherEventArgs e)
        {
            if(e.Location == "Krk")
            {
                CracowWeatherChanged(this, e);
            }
            else
            {
                WarsawWeatherChanged(this, e);
            }
        }
    }
}
