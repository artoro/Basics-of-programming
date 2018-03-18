using System.Collections.Generic;

namespace Zajecia1
{
    public class MyData
    {
        private static MyData instance;
        public List<Animal> Animals { get; set; } = new List<Animal>();

        private MyData()
        {
            var kot = new Cat("Stefan", "black", 2, 5);
            var kot2 = new Cat("XD", "brown", 3, 6);
            var piesel = new Dog("PIESEL", "black", 10, 2);
            var golab = new Pidgeon("golabek", 1, 1, "green");

            Animals.Add(kot);
            Animals.Add(kot2);
            Animals.Add(piesel);
            Animals.Add(golab);
        }

        public static MyData GetInstance()
        {
            if(instance == null)
            {
                instance = new MyData();
            }
            return instance;
        }

    }
}
