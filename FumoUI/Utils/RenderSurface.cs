using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.Linq;
using System.Runtime.InteropServices;
using System.Text;
using System.Threading.Tasks;
using System.Windows;
using System.Windows.Interop;

namespace FumoUI.Utils
{
    public class RenderSurface : HwndHost
    {
        private IntPtr _hwnd = IntPtr.Zero;
        private readonly int _width = 300;
        private readonly int _height = 300;
        public int SurfaceId { get; private set; } = 0;
        public const int GWL_STYLE = (-16);
        public const int WS_CHILD = 0x40000000;

        [DllImport("FumoEngine.dll", CallingConvention = CallingConvention.Cdecl)]
        public static extern int InitializeApp(IntPtr hParent, IntPtr hInstance);

        [DllImport("FumoEngine.dll")]
        static extern int SetOwnWindowLong(IntPtr hWnd, int nIndex, UInt32 dwNewLong);


        protected override HandleRef BuildWindowCore(HandleRef hwndParent)
        {
            try
            {
                IntPtr hwnd = hwndParent.Handle;
                IntPtr hInstance = Marshal.GetHINSTANCE(typeof(MainWindow).Module);

                int result = InitializeApp(hwnd, hInstance);
                if (SurfaceId == -1)
                {
                    throw new Exception("Failed to initialize render surface.");
                }
            }
            catch (Exception ex)
            {
                MessageBox.Show($"Error initializing DirectX surface: {ex.Message}");
                // Log error or handle further
            }

            _hwnd = hwndParent.Handle;
            Debug.Assert(_hwnd != IntPtr.Zero);
            return new HandleRef(this, _hwnd);
        }


        protected override void DestroyWindowCore(HandleRef hwnd)
        {
            _hwnd = IntPtr.Zero;
        }
    }
}
