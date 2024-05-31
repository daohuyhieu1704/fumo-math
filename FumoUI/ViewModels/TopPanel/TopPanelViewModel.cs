using FumoUI.Utils;
using System;
using System.Collections.Generic;
using System.Collections.ObjectModel;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows;
using System.Windows.Input;
using static FumoUI.ViewModels.ViewModelBase;


namespace FumoUI.ViewModels.TopPanel
{
    public class TopPanelViewModel : ViewModelBase
    {
        private DatabaseInterop? _databaseInterop;

        private ObservableCollection<string> _fileItems;

        public ObservableCollection<string> FileItems
        {
            get => _fileItems;
            set
            {
                Set(ref _fileItems, value);
                OnPropertyChanged(nameof(FileItems));
            }
        }

        private string _fileSelected;
        public string FileSelected
        {
            get => _fileSelected;
            set
            {
                Set(ref _fileSelected, value);
                OnPropertyChanged(nameof(FileSelected));
            }
        }

        public TopPanelViewModel()
        {
            CancelCmd = new RelayCommand<Window>((p) => { return p != null; }, (p) => { p.Close(); });

            FileItems = new ObservableCollection<string>();
            FileItems.Add("Test 1.json");
            FileItems.Add("Test 2.json");

            FileSelected = FileItems[0];

            _databaseInterop = new DatabaseInterop();
        }
        public void DrawCircle()
        {
            DirectXHost.DrawCircle(100, 200, 50);
        }

        public readonly ICommand CancelCmd;

        public void Save()
        {
            try
            {
                if (_databaseInterop == null)
                {
                    throw new InvalidOperationException("DatabaseInterop is not initialized.");
                }
                _databaseInterop.SaveToJson("output.json");
                MessageBox.Show("Data has been saved to output.json successfully.");
            }
            catch (Exception ex)
            {
                MessageBox.Show($"Failed to save data: {ex.Message}");
            }
        }
    }
}
