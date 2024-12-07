using System;
using System.Collections.Generic;
using System.Linq;
using System.Runtime.InteropServices;
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

namespace AnagrammeWPF
{
    /// <summary>
    /// Interaction logic for MainWindow.xaml
    /// </summary>
    public partial class MainWindow : Window
    {

        private String[] tabMots;
        int motActu;
        int partie = 0; 
        int essaisrestants = 5;
        int coup = 0;
        //ajouter d'autres propriétés ici si besoin
        //
        //
        //


        public MainWindow()
        {
            InitializeComponent();
        }

        private void initialisation()
        {
            tabMots = new string[] {"LUNDI","MARDI","MERCREDI","JUNDI","VENDREDI","SAMEDI","DIMANCHE" };
            
        
        }

        private void Window_Loaded(object sender, RoutedEventArgs e)
        {
            initialisation();
            nouvellePartie();
        }
        private String melanger(String chaine)
        {
            String melanger="";
            Random r = new Random();
            String chainetemp=chaine;

            for(int i = 0; i < chainetemp.Length; i++)
            {
                
                int j = r.Next(chaine.Length);
                melanger=melanger.Insert(0,chaine[j].ToString());
                chaine=chaine.Remove(j,1);
            }

            return melanger; 
        }


        private void nouvellePartie()
        {
            Random r = new Random();
            int i = r.Next(tabMots.Length);
            LBLMot.Content = melanger(tabMots[i]);
            motActu = i;
            partie++;
        }


        private void motCorrect()
        {
            MessageBoxResult r= MessageBox.Show("Bravo, vous avez trouvé le mot qui était " + tabMots[motActu],"Voulez vous rejouez ?",MessageBoxButton.YesNo);
            LBXEssais.Items.Add("Partie " + partie + " - " + tabMots[motActu] + " Gagnée - " + (essaisrestants-coup) + "essais");
            if (r = MessageBoxResult.Yes)
            {
                nouvellePartie();
            }
            else
            {
                WNDprincipale.Close();
            }
        }

        private void motIncorrect()
        {

            if (coup == essaisrestants)
            {
                MessageBoxResult r = MessageBox.Show("Dommage, le mot que vous deviez troué était " + tabMots[motActu], "Voulez vous rejouez ?", MessageBoxButton.YesNo);
                LBXEssais.Items.Add("Partie " + partie + " - " + tabMots[motActu] + " Perdu - " + (essaisrestants - coup) + "essais");
                if (r = MessageBoxResult.Yes)
                {
                    nouvellePartie();
                }
                else
                {
                    WNDprincipale.Close();
                }

            }
           
        }

        private void BTNTest_Click(object sender, RoutedEventArgs e)
        {
            coup++;
            if(TBXMot.Text== tabMots[motActu])
            {
                
                motIncorrect();
            }
            else
            {
                motCorrect();
            }
        }


        //ajouter vos autres méthodes ici
        //
        //
        //

    }
}
