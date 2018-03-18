using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApplication1
{
    class Program
    {
        static void Main(string[] args)
        {
            //KONSOLA
            Console.WriteLine("KOT");

            //PĘTLA
            for (int i = 0; i < 3; i++)
                Console.WriteLine("LUBIĘ KOTY");

            //METODA
            Console.WriteLine(WriteString());

            //METODA Z WARUNKIEM
            Console.WriteLine(TestString());

            //KLASA
            var kot = new Cat("Garfield", "Red", 2, 1.3f);
            Console.WriteLine(kot.Name);
            kot.Meow();
            kot.Feed("Chrupki");

            //WYŁĄCZNIK
            Console.ReadKey();
        }

        static string WriteString()
        {
            string s;
            Console.Write("ECHO: ");
            s = Console.ReadLine();
            return s;
        }

        static string TestString()
        {
            string s;
            string p = "NIE KOT";
            Console.Write("TEST KOTA: ");
            s = Console.ReadLine();
            if (s == "kot" || s == "KOT")
            {
                p = s;
            }
            return p;
        }
    }
}
