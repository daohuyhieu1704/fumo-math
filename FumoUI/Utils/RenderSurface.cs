using System.Runtime.InteropServices;
using System.Windows.Interop;
using System;
using System.Windows;

namespace FumoUI.Utils
{
    public class RenderSurface : HwndHost
    {
        private static IntPtr _hwnd = IntPtr.Zero;
        public int SurfaceId { get; private set; } = 0;
        public const int GWL_STYLE = (-16);
        public const int WS_CHILD = 0x40000000;

        private const uint SWP_NOZORDER = 0x0004;
        private const uint SWP_NOACTIVATE = 0x0010;

        [DllImport("FumoEngine.dll", CallingConvention = CallingConvention.Cdecl)]
        public static extern IntPtr InitializeApp(IntPtr hParent, IntPtr hInstance);

        [DllImport("FumoEngine.dll")]
        static extern int SetOwnWindowLong(IntPtr hWnd, int nIndex, UInt32 dwNewLong);

        [DllImport("user32.dll", SetLastError = true)]
        public static extern bool SetWindowPos(IntPtr hWnd, IntPtr hWndInsertAfter, int X, int Y, int cx, int cy, uint uFlags);

        public static void ResizeWin32Window(int x, int y, int width, int height)
        {
            if (_hwnd == IntPtr.Zero)
            {
                return;
            }
            SetWindowPos(_hwnd, IntPtr.Zero, x, y, width, height, SWP_NOZORDER | SWP_NOACTIVATE);
        }

        protected override HandleRef BuildWindowCore(HandleRef hwndParent)
        {
            IntPtr hwnd = CreateHostWindow(hwndParent.Handle); 
            _hwnd = hwnd;
            if (_hwnd == IntPtr.Zero)
            {
                throw new Exception("Failed to create host window.");
            }
            return new HandleRef(this, _hwnd);
        }

        private IntPtr CreateHostWindow(IntPtr hwndParent)
        {
            return Marshal.GetHINSTANCE(typeof(MainWindow).Module);
        }

        protected override void DestroyWindowCore(HandleRef hwnd)
        {
            _hwnd = IntPtr.Zero;
        }

        internal void Initialize(IntPtr hwnd, IntPtr hInstance)
        {
            _hwnd = hwnd;
            IntPtr result = InitializeApp(_hwnd, hInstance);
            if (result == IntPtr.Zero)
            {
                MessageBox.Show("Failed to initialize the native application.");
                return;
            }
            _hwnd = result;
        }
    }
}
