using System;
using System.Collections.Generic;
using System.Drawing;
using System.Linq;
using System.Runtime.InteropServices;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Interop;

namespace FumoUI.Utils
{
    public class DirectXHost : HwndHost
    {
        private static RendererWrapper? rendererWrapper;
        private IntPtr hwndHost;

        protected override HandleRef BuildWindowCore(HandleRef hwndParent)
        {
            rendererWrapper = RendererWrapper.Instance;
            hwndHost = rendererWrapper.CreateRendererWindow(hwndParent.Handle);
            return new HandleRef(this, hwndHost);
        }

        protected override void DestroyWindowCore(HandleRef hwnd)
        {
            rendererWrapper?.DestroyRendererWindow();
        }

        public static void DrawCircle(float centerX, float centerY, float radius)
        {
        }
    }
}
