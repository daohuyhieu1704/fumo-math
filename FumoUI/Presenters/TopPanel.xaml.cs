using FumoUI.ViewModels.TopPanel;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Data;
using System.Windows.Documents;
using System.Windows.Input;
using System.Windows.Media;
using System.Windows.Media.Imaging;
using System.Windows.Navigation;
using System.Windows.Shapes;
using Microsoft.Win32;

namespace FumoUI.Presenters
{
    /// <summary>
    /// Interaction logic for TopPanel.xaml
    /// </summary>
    public partial class TopPanel : UserControl
    {
        public TopPanel()
        {
            InitializeComponent();
            DataContext = new TopPanelViewModel();
        }

        private void CommandAction(Action<TopPanelViewModel> callback)
        {
            try
            {
                if (DataContext is not TopPanelViewModel model)
                {
                    return;
                }

                callback(model);
            }
            catch (Exception)
            {

            }
        }

        private void New_Click(object sender, RoutedEventArgs e)
        {
            string newTabName = "Untitled";
            CommandAction(model =>
            {
                model.AddNewTab(newTabName);
                model.IsNewFile = true;
            });
        }

        private void Open_Click(object sender, RoutedEventArgs e)
        {
            OpenFileDialog openFileDialog = new OpenFileDialog
            {
                Filter = "JSON files (*.json)|*.json"
            };

            if (openFileDialog.ShowDialog() == true)
            {
                string fileName = openFileDialog.FileName;
                CommandAction(model =>
                {
                    model.Open(fileName);
                    model.IsNewFile = false;
                });
            }
        }

        private void Save_Click(object sender, RoutedEventArgs e)
        {
            if (DataContext is not TopPanelViewModel viewModel)
            {
                return;
            }

            if (viewModel.FileSelected == null)
            {
                MessageBox.Show("Please select a file to save.");
                return;
            }

            if (viewModel.IsNewFile)
            {
                SaveFileDialog saveFileDialog = new SaveFileDialog
                {
                    Filter = "JSON files (*.json)|*.json",
                    FileName = viewModel.FileSelected
                };

                if (saveFileDialog.ShowDialog() == true)
                {
                    string newFileName = saveFileDialog.FileName;
                    viewModel.Save(newFileName);
                }
            }
            else
            {
                string existingFileName = viewModel.FileSelected;
                viewModel.Save(existingFileName);
            }
        }

        private void Undo_Click(object sender, RoutedEventArgs e)
        {
        }

        private void Redo_Click(object sender, RoutedEventArgs e)
        {

        }

        private void CircleMode_Click(object sender, RoutedEventArgs e)
        {
            if (DataContext is not TopPanelViewModel viewModel)
            {
                return;
            }
            CommandAction(model => { viewModel.SetMode(1); });
        }

        private void LineMode_Click(object sender, RoutedEventArgs e)
        {
            if (DataContext is not TopPanelViewModel viewModel)
            {
                return;
            }
            CommandAction(model => { viewModel.SetMode(2); });
        }
    }
}
