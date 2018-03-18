namespace Zajecia1
{
    class Pidgeon : Animal
    {
        public Pidgeon(string name, int weight, int age, string color) : 
            base(name, weight, age, color, new YesFly())
        {
        }
       
    }
}
