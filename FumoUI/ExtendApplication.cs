using System;
using System.Collections.Generic;
using System.Linq;
using System.Runtime.InteropServices;
using System.Text;
using System.Threading.Tasks;

namespace FumoUI
{
    internal class ExtendApplication
    {
        [DllImport("FumoEngine.dll", CallingConvention = CallingConvention.Cdecl)]
        public static extern int InitializeApp(IntPtr handle, int _width, int _height);
    }
}
