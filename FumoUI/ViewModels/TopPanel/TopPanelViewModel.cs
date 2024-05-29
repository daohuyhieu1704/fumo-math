using FumoUI.Utils;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows;
using System.Windows.Input;

namespace FumoUI.ViewModels.TopPanel
{
    public class TopPanelViewModel : ViewModelBase
    {
        public TopPanelViewModel()
        {
            CancelCmd = new RelayCommand<Window>((p) => { return p != null; }, (p) => { p.Close(); });
        }
        public void DrawCircle()
        {
            DirectXHost.DrawCircle(100, 200, 50);
        }

        public readonly ICommand CancelCmd;
    }
}
