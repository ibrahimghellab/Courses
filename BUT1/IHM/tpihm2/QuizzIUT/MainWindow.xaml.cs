using System;
using System.Collections.Generic;
using System.Linq;
using System.Reflection.PortableExecutable;
using System.Runtime.Intrinsics.X86;
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

namespace QuizzIUT
{
    /// <summary>
    /// Interaction logic for MainWindow.xaml
    /// </summary>
    public partial class MainWindow : Window
    {
        private int _numeroQuestion=-1 , _nbBonneReponse=0, _nbMauvaiseReponse=0;
        private string[] questions = { "Qui est le meilleur footballer ?","Quel est le prénom du créateur de l'IHM ?","Quelle est la capitale de l'Australie ?", "Quel est le language le plus utilisé ?", "Le nom du personnage principale de Final Fantasy VII ?" };
       private string[] réponses = { "Messi", "Ivan ", "Canberra", "Python", "Cloud Strife"};
        public MainWindow()
        {
            InitializeComponent();
            WNDFenetrePrincipale.Background = Brushes.WhiteSmoke;
            LBLTitre.Foreground = Brushes.DarkGray;
            LBLQuestion.Foreground = Brushes.DarkGray;
            LBLMauvaisesReponsesValeurs.Foreground = Brushes.DarkGray;
            LBLBonneRéponses.Foreground = Brushes.DarkGray;
            LBLBonneRéponsesValeurs.Foreground = Brushes.DarkGray;
            LBLMauvaisesRéponses.Foreground = Brushes.DarkGray;
        }

        private void BTNValider_Click(object sender, RoutedEventArgs e)
        {
            if (ReponseUser() == réponses[_numeroQuestion])
            {
                MessageBox.Show("Bravo! Bonne réponse!", "BRAVOO !!");
                _nbBonneReponse++;
                LBLBonneRéponsesValeurs.Content = _nbBonneReponse;
                NextQuestion();
                TBXReponse.Text = "";
            }
            else
            {
                string reponseAttendu = réponses[_numeroQuestion];
                MessageBox.Show("Faux! La bonne réponse est " + reponseAttendu, "NOOOOOOOONNNNNNN !!!");
                _nbMauvaiseReponse++;
                LBLMauvaisesReponsesValeurs.Content = _nbMauvaiseReponse;
                NextQuestion();
                TBXReponse.Text = "";
            }
        }


        private void BTNValider_Loaded(object sender, RoutedEventArgs e)
        {

        }

        private void WNDFenetrePrincipale_Loaded(object sender, RoutedEventArgs e)
        {
            NextQuestion();
        }

        private void SDRModeNuit_ValueChanged(object sender, RoutedPropertyChangedEventArgs<double> e)
        {
            
            if (SDRModeNuit.Value>=0.5)
            {
                WNDFenetrePrincipale.Background = Brushes.DarkGray;
                LBLTitre.Foreground = Brushes.White;
                LBLQuestion.Foreground = Brushes.White;
                LBLMauvaisesReponsesValeurs.Foreground = Brushes.White;
                LBLBonneRéponses.Foreground = Brushes.White;
                LBLBonneRéponsesValeurs.Foreground= Brushes.White;
                LBLMauvaisesRéponses.Foreground= Brushes.White; 
            }
            else
            {
                WNDFenetrePrincipale.Background = Brushes.WhiteSmoke;
                LBLTitre.Foreground = Brushes.DarkGray;
                LBLQuestion.Foreground = Brushes.DarkGray;
                LBLMauvaisesReponsesValeurs.Foreground = Brushes.DarkGray;
                LBLBonneRéponses.Foreground = Brushes.DarkGray;
                LBLBonneRéponsesValeurs.Foreground = Brushes.DarkGray;
                LBLMauvaisesRéponses.Foreground = Brushes.DarkGray;
            }
        }

        private void NextQuestion()
        {
            _numeroQuestion++;
            if(_numeroQuestion==questions.Length) { _numeroQuestion = 0; }
            LBLQuestion.Content = questions[_numeroQuestion];
        }

        private string ReponseUser()
        {
            return TBXReponse.Text;
        }
    }
}
