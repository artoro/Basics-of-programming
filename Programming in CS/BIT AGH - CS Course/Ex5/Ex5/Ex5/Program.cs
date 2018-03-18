using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ex5
{
    class Program
    {
        static void Main(string[] args)
        {
            WeatherStation station = new WeatherStation();
            ConcretePerson1 person1 = new ConcretePerson1(station, "Krk");
            ConcretePerson2 person2 = new ConcretePerson2(station, "Warsaw");

            while (true)
            {
                Console.WriteLine("Location, Temp");
                string change = Console.ReadLine();
                int temperature;
                Int32.TryParse(change.Split(',')[1], out temperature);
                /*//Int32.TryParse(change.Split(',')[1], out int temperature);
                try
                {
                    int temp2 = Convert.ToInt32(change.Split(','));
                }
                catch (FormatException e)
                {
                    int temp2 = 16;
                    //throw new FormatException();
                }
                catch (Exception e)
                {

                }
                finally
                {
                    //blok zawsze wykonywany
                }*/

                foreach (var loc in station.WeatherList)
                {
                    loc.ChangeWeather(change.Split(',')[0]);
                }

                Console.WriteLine(person1.ToString());
                Console.WriteLine(person2.ToString());
            }
        }
    }
}
