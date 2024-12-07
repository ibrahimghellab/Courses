using Microsoft.Win32;
using System.Windows;
using System.Windows.Controls;
using System.IO;
using System;

namespace BuggedFileReader
{
    /// <summary>
    /// Interaction logic for MainWindow.xaml
    /// </summary>
    public partial class MainWindow : Window
    {
        private OpenFileDialog ofd = new OpenFileDialog();
        private string lastOpenFile = "";
        public MainWindow()
        {
            InitializeComponent();
            ofd.InitialDirectory = Directory.GetCurrentDirectory();
        }

        /**
         * Exceptions are not handled
         */
        private void BTNOpenFile_Click(object sender, RoutedEventArgs e)
        {

            try{
                
                lastOpenFile = TBXFileName.Text;
                loadFile();
                TBXFileName.Text = "";
            }
            catch(ArgumentException ae)
            {
                MessageBox.Show("Donnez un fichier");
            }
            catch(FileNotFoundException fne) {
                MessageBox.Show("Donnez le nom d'un fichier valide");
            }
            
                         
            
        }

        /**
         * This method should open a Dialog window
         */
        private void BTNOpenDialog_Click(object sender, RoutedEventArgs e)
        {

            
            bool? result = ofd.ShowDialog();
            if (result!=null && result == true)
            {
                lastOpenFile = ofd.FileName;
                loadFile();    
            }
        }
        private int wordCount()
        {
            int count = 0;
            foreach(string line in TBKContent.Text.Split('a'))
            {
                foreach(string word in line.Split('b')){
                    count++;
                }
                count++;
            }
            return count;
        }

        /**
         * This method should open the file... Where does the class "File" come from?
         */
        private void loadFile()
        {
            string text = File.ReadAllText(lastOpenFile);
            TBKContent.Text = text;
            LBLWordCountValue.Content = wordCount();
        }

        /**
         * This method must be triggered by the combobox. Did we configure all the possible options?
         */
        private void CBXCase_SelectionChanged(object sender, SelectionChangedEventArgs e)
        {
            ComboBox cbx = (ComboBox) sender;
            if(cbx.SelectedIndex == 0 && lastOpenFile != "")
            {
                loadFile();
            }
            if(cbx.SelectedIndex == 1)
            {
               TBKContent.Text = TBKContent.Text.ToUpper();
            }
            if (cbx.SelectedIndex == 2)
            {
                TBKContent.Text = TBKContent.Text.ToLower();
            }
        }
    }
}
