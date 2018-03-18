using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Csharp_lekcja_1
{
    class Program
    {
        static void Main(string[] args)
        {
            Ex2();
            Console.ReadKey();
        }

        static void Ex1() //Zamiana temperatury ze stopni Fahrenheita na stopnie Celsjusza
        {
            double F, C;
            Console.WriteLine("Podaj temperaturę w stopniach Fahrenheita");
            try { F = double.Parse(Console.ReadLine()); } //double.Parse() - konwersja String to double
            // F = Convert.ToDouble(Console.ReadLine()); - inny sposob konwersji
            catch { Console.WriteLine("Podano nieprawidłowe dane!"); return; }
            C = 5.0 / 9 * (F - 32);
            Console.WriteLine("Temperatura wynosi " + C + "°C");
        }

        static void Ex2() //operacje matematyczno-tekstowe
        {
            double A = 1, B = -2, C = 3;
            Console.Write("A={0,-3}", A); //wyswietla be znaku \n
            Console.WriteLine("B={0}  C={1}", B, C);
            Console.WriteLine("A + B + C = " + A + B + C);
            Console.WriteLine("A + B + C = " + (A + B + C).ToString());
            Console.WriteLine("logA + sqrt(|B|) + C^3 = {0,9:F4}", Math.Log10(A) + Math.Sqrt(Math.Abs(B)) + Math.Pow(C, 3));
            Console.WriteLine("logA + sqrt(|B|) + C^3 = {0,-9:F4}", Math.Log10(A) + Math.Sqrt(Math.Abs(B)) + Math.Pow(C,3));
            Console.WriteLine("A / B * {0,1:P} = {1,1:P}", 1, A/B);
        }
        
    }
}
