using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Data;
using System.Windows.Documents;
using System.Windows.Input;
using System.Windows.Media;
using System.Windows.Media.Imaging;
using System.Windows.Navigation;
using System.Windows.Shapes;
using Zajecia1;

namespace Zajecia1WPF
{
    /// <summary>
    /// Interaction logic for MainWindow.xaml
    /// </summary>
    public partial class MainWindow : Window
    {
        MyData myData;

        public MainWindow()
        {
            myData = MyData.GetInstance();
            
            InitializeComponent();
            AnimalDataGrid.ItemsSource = myData.Animals;
        }

        private void AgeButton_Click(object sender, RoutedEventArgs e)
        {
            myData.Animals.Sort((a, b) => a.Age - b.Age);
            AnimalDataGrid.Items.Refresh();
        }

        private void WeightButton_Click(object sender, RoutedEventArgs e)
        {
            myData.Animals.Sort((a, b) => a.Weight - b.Weight);
            AnimalDataGrid.Items.Refresh();
        }
    }
}
