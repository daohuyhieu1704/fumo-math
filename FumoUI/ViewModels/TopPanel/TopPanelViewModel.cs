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

        private bool _isNewFile;
        public bool IsNewFile
        {
            get => _isNewFile;
            set
            {
                Set(ref _isNewFile, value);
                OnPropertyChanged(nameof(IsNewFile));
            }
        }

        public TopPanelViewModel()
        {
            CancelCmd = new RelayCommand<Window>((p) => { return p != null; }, (p) => { p.Close(); });

            FileItems = new ObservableCollection<string>();

            if (FileItems.Count > 0)
            {
                FileSelected = FileItems[0];
            }

            _databaseInterop = new DatabaseInterop();

            CloseTabCommand = new RelayCommand<string>((fileName) => true, (fileName) => CloseTab(fileName));
        }
        public void DrawCircle()
        {
            DirectXHost.DrawCircle(100, 200, 50);
        }

        public readonly ICommand CancelCmd;
        public ICommand CloseTabCommand { get; }

        public void AddNewTab(string newTabName)
        {
            FileItems.Add(newTabName);
            FileSelected = newTabName;
        }

        public void Open(string fileName)
        {
            string fileNameWithoutPath = System.IO.Path.GetFileName(fileName);

            if (!_fileItems.Contains(fileNameWithoutPath))
            {
                _fileItems.Add(fileNameWithoutPath);
            }
            FileSelected = fileNameWithoutPath;
            IsNewFile = false;
        }

        public void Save(string newFileName)
        {
            try
            {
                if (_databaseInterop == null)
                {
                    throw new InvalidOperationException("DatabaseInterop is not initialized.");
                }
                _databaseInterop.SaveToJson(newFileName);
                MessageBox.Show($"Data has been saved to {newFileName} successfully.");

                string newFileNameWithoutPath = System.IO.Path.GetFileName(newFileName);

                int selectedIndex = FileItems.IndexOf(FileSelected);
                if (selectedIndex >= 0)
                {
                    FileItems[selectedIndex] = System.IO.Path.GetFileName(newFileName);
                    FileSelected = FileItems[selectedIndex];
                }

                IsNewFile = false;
            }
            catch (Exception ex)
            {
                MessageBox.Show($"Failed to save data: {ex.Message}");
            }
        }

        private void CloseTab(string fileName)
        {
            if (FileItems.Contains(fileName))
            {
                FileItems.Remove(fileName);
                if (FileItems.Count > 0)
                {
                    FileSelected = FileItems[0];
                }
            }
        }
    }
}
