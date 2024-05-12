using FumoUI.Utils;
using System.Text;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Data;
using System.Windows.Documents;
using System.Windows.Input;
using System.Windows.Media;
using System.Windows.Media.Imaging;
using System.Windows.Navigation;
using System.Windows.Shapes;

namespace FumoUI
{
    /// <summary>
    /// Interaction logic for MainWindow.xaml
    /// </summary>
    public partial class MainWindow : Window
    {
        private DirectXHost directXHost;
        public MainWindow()
        {
            InitializeComponent();
            directXHost = new DirectXHost();
            hostContainer.Child = directXHost;
            hostContainer.MouseDown += HostContainer_MouseDown;
        }

        private void HostContainer_MouseDown(object sender, MouseButtonEventArgs e)
        {
            if (e.LeftButton == MouseButtonState.Pressed)
            {
                Point position = e.GetPosition(hostContainer);
                DirectXHost.DrawCircle((float)position.X, (float)position.Y, 50);
            }
        }
    }
}