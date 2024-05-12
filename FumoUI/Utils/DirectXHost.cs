using System;
using System.Collections.Generic;
using System.Linq;
using System.Runtime.InteropServices;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Interop;

namespace FumoUI.Utils
{
    public class DirectXHost : HwndHost
    {
        private RendererWrapper? rendererWrapper;
        private IntPtr hwndHost;

        protected override HandleRef BuildWindowCore(HandleRef hwndParent)
        {
            rendererWrapper = new RendererWrapper();
            hwndHost = rendererWrapper.CreateRendererWindow(hwndParent.Handle);
            return new HandleRef(this, hwndHost);
        }

        protected override void DestroyWindowCore(HandleRef hwnd)
        {
            rendererWrapper?.DestroyRendererWindow();
        }
    }
}
