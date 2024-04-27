using FumoUI.Utils;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Runtime.InteropServices;
using System.Text;
using System.Threading.Tasks;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Data;
using System.Windows.Documents;
using System.Windows.Input;
using System.Windows.Interop;
using System.Windows.Media;
using System.Windows.Media.Imaging;
using System.Windows.Navigation;
using System.Windows.Shapes;

namespace FumoUI.Views
{
    /// <summary>
    /// Interaction logic for GraphView.xaml
    /// </summary>
    public partial class GraphView : UserControl, IDisposable
    {
        private enum WinMsg
        {
            WM_SIZE = 0x0005,
            WM_CLOSE = 0x0010,
            WM_DESTROY = 0x0002,
            WM_SIZING = 0x0214,
            WM_ENTERSIZEMOVE = 0x0231,
            WM_EXITSIZEMOVE = 0x0232,
        }

        private RenderSurface _renderSurface = null;

        public GraphView()
        {
            InitializeComponent();
            this.Loaded += GraphView_Loaded;
        }

        private void GraphView_Loaded(object sender, RoutedEventArgs e)
        {
            try
            {
                Loaded -= GraphView_Loaded;
                Grid grid = this.Parent as Grid;
                MainWindow mainWindow = grid.Parent as MainWindow;
                var windowInteropHelper = new WindowInteropHelper(mainWindow);
                IntPtr hwnd = windowInteropHelper.Handle;
                IntPtr hInstance = Marshal.GetHINSTANCE(typeof(MainWindow).Module);

                // Call the InitializeApp function from the DLL
                int result = RenderSurface.InitializeApp(hwnd, hInstance);

                if (result == -1)
                {
                    MessageBox.Show("Failed to initialize the native application.");
                }
            }
            catch (Exception ex)
            {
                MessageBox.Show($"An error occurred: {ex.Message}");
            }
        }

        private IntPtr WndProc(IntPtr hwnd, int msg, IntPtr wParam, IntPtr lParam, ref bool handled)
        {
            switch ((WinMsg)msg)
            {
                case WinMsg.WM_SIZE:
                    break;
                case WinMsg.WM_CLOSE:
                    break;
                case WinMsg.WM_DESTROY:
                    break;
                case WinMsg.WM_SIZING:
                    break;
                case WinMsg.WM_ENTERSIZEMOVE:
                    break;
                case WinMsg.WM_EXITSIZEMOVE:
                    break;
            }
            return IntPtr.Zero;
        }

        protected virtual void Dispose(bool disposing)
        {
            if (disposing)
            {
                if (_renderSurface != null)
                {
                    _renderSurface.Dispose();
                    _renderSurface = null;
                }
            }
        }

        public void Dispose()
        {
            Dispose(true);
            GC.SuppressFinalize(this);
        }
    }
}
