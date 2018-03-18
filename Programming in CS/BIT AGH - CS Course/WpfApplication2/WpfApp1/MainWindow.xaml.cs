using System.Collections.Generic;
using System.Collections.ObjectModel;
using System.Windows;
using Zajecia1;

namespace WpfApp1
{
    /// <summary>
    /// Interaction logic for MainWindow.xaml
    /// </summary>
    public partial class MainWindow : Window
    {
        private ObservableCollection<Animal> XD;
        public List<Animal> Animals { get; set; }

        public MainWindow()
        {
            var kot = new Cat("Stefan", "black", 2, 5);
            var kot2 = new Cat("XD", "brown", 3, 6);
            var piesel = new Dog("PIESEL", "black", 10, 2);
            var golab = new Pidgeon("golabek", 1, 1, "green");
            //    data.Animals[0] = kot;
            //    data.Animals[1] = kot2;
            //    data.Animals[2] = piesel;

            MyData.Animals.Add(kot);
            MyData.Animals.Add(kot2);
            MyData.Animals.Add(piesel);

            Animals = MyData.Animals;
            InitializeComponent();
            this.AnimalsDataGrid.ItemsSource = Animals;
        }

        private void NameButton_Click(object sender, RoutedEventArgs e)
        {
            Animals.Sort((a, b) => a.Weight - b.Weight);
            this.AnimalsDataGrid.Items.Refresh();
        }

        private void ColorButton_Click(object sender, RoutedEventArgs e)
        {
            Animals.Sort((a, b) => a.Age - b.Age);
            this.AnimalsDataGrid.Items.Refresh();
        }
    }
}
