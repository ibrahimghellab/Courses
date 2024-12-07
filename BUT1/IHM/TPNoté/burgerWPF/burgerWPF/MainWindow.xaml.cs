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

namespace burgerWPF
{
    /// <summary>
    /// Interaction logic for MainWindow.xaml
    /// </summary>
    public partial class MainWindow : Window
    {
        double prix = 0;
        double prixprec = 0;

        public MainWindow()
        {
            InitializeComponent();
        }

        private void BTNCommander_Click(object sender, RoutedEventArgs e)
        {
            MessageBox.Show("Merci pour ta commande! La facture d'un montant de " + prix + "$ te sera envoyé par SMS.");
        }

       

        private void CBXSalade_Checked(object sender, RoutedEventArgs e)
        {
            if ((bool)CBXSalade.IsChecked)
            {
                prix += 0.25;
                majprix();
            }
        }

        private void CBXTomate_Checked(object sender, RoutedEventArgs e)
        {
            if ((bool)CBXTomate.IsChecked)
            {
                prix += 0.25;
                majprix();
            }
        }

        private void CBXOignons_Checked(object sender, RoutedEventArgs e)
        {
            if ((bool)CBXOignons.IsChecked)
            {
                prix += 0.25;
                majprix();
            }
          
        }

        private void CBXFromage_Checked(object sender, RoutedEventArgs e)
        {
            if ((bool)CBXFromage.IsChecked)
            {
                prix += 0.25;
                majprix();
            }
        }

        private void CBXSauceBurger_Checked(object sender, RoutedEventArgs e)
        {
            if ((bool)CBXSauceBurger.IsChecked)
            {
                prix += 0.25;
                majprix();
            }
        }

        private void CBXSalade_Unchecked(object sender, RoutedEventArgs e)
        {
            prix -= 0.25;
            majprix();
        }

        private void CBXTomate_Unchecked(object sender, RoutedEventArgs e)
        {
            prix -= 0.25;
            majprix();
        }

        private void CBXOignons_Unchecked(object sender, RoutedEventArgs e)
        {
            prix -= 0.25;
            majprix();
        }

        private void CBXFromage_Unchecked(object sender, RoutedEventArgs e)
        {
            prix -= 0.25;
            majprix();
        }

        private void CBXSauceBurger_Unchecked(object sender, RoutedEventArgs e)
        {
            prix -= 0.25;
            majprix();
        }

        private void majprix()
        {
            LBLPrix.Content = prix;
        }

        private void LBXPain_SelectionChanged(object sender, SelectionChangedEventArgs e)
        {
            if (LBXPain.SelectedItem == Nature)
            {
                prix += 2.5;
            }
            if(LBXPain.SelectedItem == Intégral)
            {
                prix += 3;
            }
            if (LBXPain.SelectedItem == Sésame)
            {
                prix += 3.5;
            }
            majprix() ;
        }

        private void LBXViande_SelectionChanged(object sender, SelectionChangedEventArgs e)
        {
            if (LBXPain.SelectedItem == Steack)
            {
                prix -= prixprec;
                prix += 5;
                prixprec = prix;
            }
            if (LBXPain.SelectedItem == Poulet)
            {
                prix -= prixprec;
                prix += 4;
                prixprec = prix;
            }
            if (LBXPain.SelectedItem == Soja)
            {
                prix -= prixprec;
                prix += 3;
                prixprec = prix;
            }
            if (LBXPain.SelectedItem == Haricots)
            {
                prix -= prixprec;
                prix += 3;
                prixprec = prix;
            }

            majprix();
        }
    }
}
