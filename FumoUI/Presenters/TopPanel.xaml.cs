﻿using FumoUI.ViewModels.TopPanel;
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
                if (!(DataContext is TopPanelViewModel model))
                {
                    return;
                }

                callback(model);
            }
            catch (Exception)
            {

            }
        }

        private void DrawCircle_Click(object sender, RoutedEventArgs e)
        {
            CommandAction(model => model.DrawCircle());
        }
    }
}
