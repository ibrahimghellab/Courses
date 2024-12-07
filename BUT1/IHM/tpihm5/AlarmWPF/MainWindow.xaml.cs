using System;
using System.Collections;
using System.IO.Packaging;
using System.Media;


using System.Windows;
using System.Windows.Controls;
using System.Windows.Media;
using System.Windows.Media.Imaging;
using System.Windows.Shapes;
using System.Windows.Threading;
using Prism.Services.Dialogs;



namespace AlarmWPF
{
    

    public partial class MainWindow : Window
    {
        DispatcherTimer timer;
        DispatcherTimer timersuppr;
        //Un cercle
        private Ellipse ellipse;
        //3 aiguilles
        private Line minutes;
        private Line hours;
        private Line seconds;
        

       ArrayList min = new ArrayList();
       ArrayList ho = new ArrayList();
       ArrayList day = new ArrayList();




        //replace alarme.wav with the path of yourfile .wav that you want to use
        SoundPlayer simpleSound = new SoundPlayer(@"alarme.wav");






        public MainWindow()
        {
            InitializeComponent();

            
            TXBHeureAlarme.Text = "";
            TXBMinuteAlarme.Text = "";






            BitmapImage backgroundImage = new BitmapImage(new Uri("unnamed.png",UriKind.Relative));
            ImageBrush imageBrush = new ImageBrush(backgroundImage);
            CNVClock.Background = imageBrush;

            
            
            
            
            
            timer = new DispatcherTimer();
            //Définit combien de secondes entre chaque déclenchement de l'événement Tick 
            timer.Interval = TimeSpan.FromSeconds(1);

            //Associe une procédure événementielle à l'événement Tick du Timer, il vous faut écrire cette procédure événementielle
            timer.Tick += timer_Tick;
            //Lance le Timer, obligatoire sinon rien ne se passe
           
            timer.Start();

            timersuppr= new DispatcherTimer();

            timersuppr.Interval = TimeSpan.FromMilliseconds(1);

            timersuppr.Tick += deleteDisabled;

            timersuppr.Start();

        }

        private void timer_Tick(object sender, EventArgs args)

        {

            
            LBLHeureActuelle.Content = DateTime.Now.Hour + " : " + DateTime.Now.Minute + " : " + DateTime.Now.Second;
            double longueurAiguilleSeconde = ellipse.Width / 2.1;
            seconds.X2 = ellipse.Width / 2 + Math.Cos(15 * Math.PI / 30 - DateTime.Now.Second * Math.PI / 30) * longueurAiguilleSeconde;
            seconds.Y2 = ellipse.Height / 2 + Math.Sin(-15 * Math.PI / 30 + DateTime.Now.Second * Math.PI / 30) * longueurAiguilleSeconde;

            double longueurAiguilleMinutes = ellipse.Width / 3;
            minutes.X2 = ellipse.Width / 2 + Math.Cos(15 * Math.PI / 30 - DateTime.Now.Minute * Math.PI / 30) * longueurAiguilleMinutes;
            minutes.Y2 = ellipse.Height / 2 + Math.Sin(-15 * Math.PI / 30 + DateTime.Now.Minute * Math.PI / 30) * longueurAiguilleMinutes;

            double longueurAiguilleHeures = ellipse.Width / 4;
            hours.X2 = ellipse.Width / 2 + Math.Cos(3 * Math.PI / 6 - DateTime.Now.Hour * Math.PI / 6) * longueurAiguilleHeures;
            hours.Y2 = ellipse.Height / 2 + Math.Sin(-3 * Math.PI / 6 + DateTime.Now.Hour* Math.PI / 6) * longueurAiguilleHeures;

            jouerAlarme();

            
            
        }
        private void Window_Loaded(object sender, RoutedEventArgs e)
        {
           
            ellipse = new Ellipse();
            CNVClock.Children.Add(ellipse);
            ellipse.Width = 300;
            ellipse.Height = 300;
            ellipse.Stroke = Brushes.Gray; ellipse.StrokeThickness = 1;
            
            
            seconds = new Line();
            CNVClock.Children.Add(seconds);
            seconds.Stroke = Brushes.Red; seconds.StrokeThickness = 1;
            //Le point d'origine est au centre du cercle
            seconds.X1 = ellipse.Width / 2;
            seconds.Y1 = ellipse.Height / 2;
            double longueurAiguilleSeconde = ellipse.Width / 2.1;
            seconds.X2 = ellipse.Width / 2 + Math.Cos(15 * Math.PI / 30 - DateTime.Now.Second * Math.PI / 30) * longueurAiguilleSeconde;
            seconds.Y2 = ellipse.Height / 2 + Math.Sin(-15 * Math.PI / 30 + DateTime.Now.Second * Math.PI / 30) * longueurAiguilleSeconde;
            
            minutes=new Line();
            CNVClock.Children.Add(minutes);
            minutes.Stroke = Brushes.Green; minutes.StrokeThickness = 1;
            minutes.X1 = ellipse.Width / 2;
            minutes.Y1 = ellipse.Height / 2;
            double longueurAiguilleMinutes = ellipse.Width / 3;
            minutes.X2 = ellipse.Width / 2 + Math.Cos(15 * Math.PI / 30 - DateTime.Now.Minute * Math.PI / 30) * longueurAiguilleMinutes;
            minutes.Y2 = ellipse.Height / 2 + Math.Sin(-15 * Math.PI / 30 + DateTime.Now.Minute * Math.PI / 30) * longueurAiguilleMinutes;

            hours = new Line();
            CNVClock.Children.Add(hours);
            hours.Stroke = Brushes.Purple; hours.StrokeThickness = 1;
            hours.X1 = ellipse.Width / 2;
            hours.Y1 = ellipse.Height / 2;
            double longueurAiguilleHeures = ellipse.Width / 4;
            hours.X2 = ellipse.Width / 2 + Math.Cos(3 * Math.PI / 6 - DateTime.Now.Hour * Math.PI / 6) * longueurAiguilleHeures;
            hours.Y2 = ellipse.Height / 2 + Math.Sin(-3 * Math.PI / 6 + DateTime.Now.Hour* Math.PI / 6) * longueurAiguilleHeures;

        }

        private void BTNAjouter_Click(object sender, RoutedEventArgs e)
        {
            int res = 0;

            if (!(int.TryParse(TXBHeureAlarme.Text, out res)) || !(int.TryParse(TXBMinuteAlarme.Text, out res)) || int.Parse(TXBHeureAlarme.Text) > 23 || int.Parse(TXBMinuteAlarme.Text) > 59 || int.Parse(TXBHeureAlarme.Text) < 0 || int.Parse(TXBMinuteAlarme.Text) < 0)
            {
                MessageBox.Show("Entre un chiffre entre 0 et 23 pour les heures et 0 et 59 pour les minutes");
            }
            else
            {


                bool trouveMemeAlarme = false;
                for (int i = 0; i < day.Count; i++)
                {
                    if ((day[i].Equals(DateTime.Now.ToShortDateString())) && (min[i].ToString().Equals(TXBMinuteAlarme.Text)) && (ho[i].ToString().Equals(TXBHeureAlarme.Text)))
                    {
                        trouveMemeAlarme = true;

                    }



                }
                if (trouveMemeAlarme)
                {
                    MessageBox.Show("Il y a déja une alarme pour ce créneau");

                }
                else
                {
                    LBXAlarme.Items.Add(DateTime.Now.ToShortDateString() + "-  " + TXBHeureAlarme.Text + ":" + TXBMinuteAlarme.Text);
                   
                    
                    
                    
                    day.Add(DateTime.Now.ToShortDateString());
                    min.Add(int.Parse(TXBMinuteAlarme.Text));
                    ho.Add(int.Parse(TXBHeureAlarme.Text));
                }




            }



            




        }

            private void BTNSupprimer_Click(object sender, RoutedEventArgs e)
        {

            if (LBXAlarme.Items.Count != 0)
            {
                day.RemoveAt(LBXAlarme.SelectedIndex);
                min.RemoveAt(LBXAlarme.SelectedIndex);
                ho.RemoveAt(LBXAlarme.SelectedIndex);
                LBXAlarme.Items.RemoveAt(LBXAlarme.SelectedIndex);
            }
            else
            {
                
            }
        }

        void deleteDisabled(object sender, EventArgs args)
        {
            if(LBXAlarme.SelectedIndex == -1)
            {
                BTNSupprimer.IsEnabled=false;
            }
            else
            {
                BTNSupprimer.IsEnabled=true;
            }
            
        }

        private void playMusique()
        {
            

            simpleSound.Play();
            
        }

        private void jouerAlarme()
        {
            for(int i = 0;i< LBXAlarme.Items.Count;i++)
            {

                if (DateTime.Now.Hour.Equals(ho[i]) && DateTime.Now.Minute.Equals(min[i]))
                {
                    Console.WriteLine(DateTime.Now.Hour);
                    Console.WriteLine(ho[i]);
                    playMusique();
                    
                    MessageBoxResult result = MessageBox.Show("Il est " + ho[i].ToString() + " : " + min[i].ToString() + ". Voulez-vous stopper l'alarme ?", "Titre de la boîte de dialogue",MessageBoxButton.YesNo);
                    if (result == MessageBoxResult.Yes)
                    {
                        simpleSound.Stop();
                    }
                    day.RemoveAt(i);
                    min.RemoveAt(i);
                    ho.RemoveAt(i);
                    LBXAlarme.Items.RemoveAt(i);
                    
                }
                   
            }
        }
    }
}

