namespace Zajecia1
{
    public class Animal
    {
        protected string color;
        public int Weight { get; private set; }
        public int Age { get; private set; }
        public string Name { get; private set; }
        public IFlyable FlyBehaviour;


        public Animal(string name, int weight, int age, string color)
        {
            Name = name;
            this.Weight = weight;
            this.Age = age;
            this.color = color;
        }
        public Animal(string name, int weight, int age, string color, IFlyable flyBehaviour)
        {
            Name = name;
            this.Weight = weight;
            this.Age = age;
            this.color = color;
            FlyBehaviour = flyBehaviour;
        }

        public virtual void MakeSound()
        {
            System.Console.WriteLine("Sound...");
        }

        public string GetColor() { return color; }

      
    }
}
