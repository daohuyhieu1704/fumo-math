using FumoUI.Utils;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace FumoUI.ViewModels.TopPanel
{
    public class TopPanelViewModel : ViewModelBase
    {
        public void DrawCircle()
        {
            DirectXHost.DrawCircle(100, 100, 50);
        }
    }
}
