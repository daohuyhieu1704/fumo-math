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
        private IntPtr hwndDirectX = IntPtr.Zero;
        private int hostHeight, hostWidth;

        public DirectXHost(int height, int width)
        {
            hostHeight = height;
            hostWidth = width;
        }

        protected override HandleRef BuildWindowCore(HandleRef hwndParent)
        {
            throw new NotImplementedException();
        }

        protected override void DestroyWindowCore(HandleRef hwnd)
        {
            throw new NotImplementedException();
        }
    }
}
