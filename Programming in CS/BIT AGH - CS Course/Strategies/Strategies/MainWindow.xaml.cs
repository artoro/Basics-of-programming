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

namespace Strategies
{
    /// <summary>
    /// Interaction logic for MainWindow.xaml
    /// </summary>
    public partial class MainWindow : Window
    {
        private ITransportable transporter;
        private TransporterFactory transporterFactory;

        public MainWindow()
        {
            InitializeComponent();
            transporterFactory = new TransporterFactory();
        }

        private void EditButton_Click(object sender, RoutedEventArgs e)
        {
            TextLabel.Content = "Głupie kliknięcie.";
        }
        
        private void BusButton_Click(object sender, RoutedEventArgs e)
        {
            transporter = transporterFactory.Create(TransporterType.Bus);
            transporter.Transport(TextLabel);
        }

        private void BikeButton_Click(object sender, RoutedEventArgs e)
        {
            transporter = transporterFactory.Create(TransporterType.Bike);
            transporter.Transport(TextLabel);
        }
    }
}
