using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ex5
{
    public enum WeatherType
    {
        cloudy,
        sunny,
        rain
    }
    public class WeatherEventArgs: EventArgs
    {
        public string Location { get; set; }
        public int Temperature { get; set; }
        public WeatherType Weather { get; set; }
    }
    public interface IWeather
    {
        event EventHandler<WeatherEventArgs> OnWeatherChanged;
        void ChangeWeather(string location);
    }
}
