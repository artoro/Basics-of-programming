using System;
using System.Collections;

namespace Zajecia1
{
    class Program
    {
        static void Main(string[] args)
        {
            //var kot = new Cat("Stefan", "black", 2, 5);
            //var kot2 = new Cat("XD", "brown", 3, 6);
            //var piesel = new Dog("PIESEL", "black", 10, 2);
            //var golab = new Pidgeon("golabek", 1, 1, "green");
            //////    data.Animals[0] = kot;
            ////    data.Animals[1] = kot2;
            ////    data.Animals[2] = piesel;


            //    foreach (var animal in data.Animals)
            //    {
            //        Console.WriteLine(animal.Name + animal.GetColor());
            //    }
            //Console.WriteLine(kot.GetColour() + kot.Name);
            //Console.WriteLine(kot2.GetColour() + kot2.Name);
            //piesel.FlyBehaviour.Fly();
            //golab.FlyBehaviour.Fly();
            //while (true)
            //{
            //    Console.WriteLine(ReadLine());
            //}
            


            //var myFactory = new AnimalFactory();



            //while (false)
            //{
            //    string animalID = Console.ReadLine();
            //    var animal = myFactory.CreateAnimal(animalID, 3.5f, 2, "AAA", "brown");
            //}




            //Console.Read();
        }

        static string ReturnString()
        {
            string s;
            s = Console.ReadLine();
            return s;
        }

        static string ReadLine()
        {
            string s;
            string p = "NIE KOT";
            s = Console.ReadLine();
            if (s == "kot" || s == "KOT")
            {
                p = "KOT";
            }
            return p;
        }
    }
}
