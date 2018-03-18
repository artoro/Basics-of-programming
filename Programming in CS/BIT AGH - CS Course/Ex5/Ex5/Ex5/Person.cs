using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ex5
{
    public class Person
    {
        protected WeatherStation weatherStation;

        public List<MobileDevice> mobileDevices;

        public Person(WeatherStation weatherStation, string location)
        {
            this.weatherStation = weatherStation;

            mobileDevices = new List<MobileDevice>
            {
                new Phone(),
                new Tablet()
            };
            loc = location;
            weather = WeatherType.rain;
            ConnectToWeatherNotification(location);
        }

        public void ConnectToWeatherNotification(string location)
        {
            if(location == "Krk")
            {
                weatherStation.CracowWeatherChanged += WeatherChanged;
            }
            else
            {
                weatherStation.WarsawWeatherChanged += WeatherChanged;
            }
        }

        private string loc;
        private WeatherType weather;

        public void WeatherChanged(object sender, WeatherEventArgs e)
        {
            weather = e.Weather;
            loc = e.Location;
        }

        public override string ToString()
        {
            return loc + " " + weather.ToString();
        }
    }
}
