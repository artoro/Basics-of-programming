using System.Collections.Generic;

namespace ConsoleApplication2
{
    public class MyZoo
    {
        private static MyZoo instance;
        public List<Animal> Animals { get; set; } = new List<Animal>();

        public MyZoo()
        {
            var kot = new Cat("Garfield", "red", 2, 5);
            var kot2 = new Cat("Filemon", "white", 1, 1);
            var piesel = new Dog("Burek", "brown", 3, 3);

            Animals.Add(kot);
            Animals.Add(kot2);
            Animals.Add(piesel);
        }

        public static MyZoo GetInstance()
        {
            if (instance == null)
            {
                instance = new MyZoo();
            }
            return instance;
        }

    }
}
