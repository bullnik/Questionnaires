using Prism.Commands;
using Prism.Mvvm;
using System.Collections.Generic;
using System.Collections.ObjectModel;
using System.Linq;
using System.Windows;
using WPF.Models;

namespace WPF.ViewModels
{
    public class MainViewModel : BindableBase
    {
        public DelegateCommand<string> OpenProfile { get; set; }
        public ObservableCollection<File> Profiles { get; set; }
        public Profile CurrentProfile { get; set; }
        private Database Database { get; set; }
        public Visibility SelectProfileVisibility { get; set; }
        public Visibility ProfileViewVisibility { get; set; }

        public MainViewModel()
        {
            Database = new Database();
            Profiles = new ObservableCollection<File>();
            Profiles.Add(new File("test1"));
            Profiles.Add(new File("test2"));
            OpenProfile = new DelegateCommand<string>((string str) =>
            {
                CurrentProfile = Database.ReadProfileByName(str);
                SelectProfileVisibility = Visibility.Hidden;
                ProfileViewVisibility = Visibility.Visible;
                RaisePropertyChanged("SelectProfileVisibility");
                RaisePropertyChanged("ProfileViewVisibility");
            });

            SelectProfileVisibility = Visibility.Visible;
            ProfileViewVisibility = Visibility.Hidden;
            //UpdateFiles();
        }
        /// <summary>
        /// Verify profiles with database.
        /// </summary>
        public void UpdateFiles()
        {
            List<string> profiles = Database.Profiles;
            Profiles.Clear();
            foreach(string profile in profiles)
            {
                Profiles.Add(new File(profile));
            }
        }


        public void ReadProfile(string fileName)
        {
            CurrentProfile = Database.ReadProfileByName(fileName);
            SelectProfileVisibility = Visibility.Hidden;
            ProfileViewVisibility = Visibility.Visible;
            RaisePropertyChanged("SelectProfileVisibility");
            RaisePropertyChanged("ProfileViewVisibility");
        }
    }

    public class File
    {
        public string FileName { get; private set; }

        public File(string fileName)
        {
            FileName = fileName;
        }
    }
}
