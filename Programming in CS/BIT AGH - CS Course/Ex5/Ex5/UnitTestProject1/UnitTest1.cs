using System;
using Microsoft.VisualStudio.TestTools.UnitTesting;
using Ex5;

namespace UnitTestProject1
{
    [TestClass]
    public class PersonTest
    {
        [TestMethod]
        public void WeatherChanged_NoEventArgsGiven()
        {

        }

        [TestMethod]
        public void WeatherChanged_AlwaysTrue()
        {
            // Assign
            var station = new WeatherStation();
            var person = new ConcretePerson1(station, "krk");
            var startTemperature = person.Temperature;
            // Act
            foreach (var localization in station.WeatherList)
            {
                localization.ChangeWeather("krk", 10);
            }
            var endTemperature = person.Temperature;
            // Assert
            Assert.IsTrue(startTemperature != endTemperature);
        }
    }
}
