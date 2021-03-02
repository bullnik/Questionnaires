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
        public DelegateCommand CreateNewProfile { get; set; }
        public DelegateCommand Back { get; set; }
        public DelegateCommand SaveCurrentProfile { get; set; }
        public ObservableCollection<File> Profiles { get; set; }
        public Profile CurrentProfile { get; set; }
        public string CurrentProfileName { get; set; }
        private Database Database { get; set; }
        public Visibility SelectProfileVisibility { get; set; }
        public Visibility ProfileViewVisibility { get; set; }

        public MainViewModel()
        {
            Database = new Database();
            Profiles = new ObservableCollection<File>();
            Back = new DelegateCommand(() =>
            {
                CurrentProfile = null;
                CurrentProfileName = null;
                ShowSelectionProfile();
                UpdateFiles();
                UpdateProfile();
            });
            SaveCurrentProfile = new DelegateCommand(() =>
            {
                if (CurrentProfileName == null)
                {
                    CurrentProfileName = CurrentProfile.FirstName + '-' + CurrentProfile.LastName;
                }
                Database.EditOrCreateNewProfile(CurrentProfileName, CurrentProfile);
            });
            OpenProfile = new DelegateCommand<string>((string str) =>
            {
                CurrentProfileName = str;
                CurrentProfile = Database.ReadProfileByName(str);
                ShowProfileView();
                UpdateProfile();
            });
            CreateNewProfile = new DelegateCommand(() =>
            {
                CurrentProfile = new Profile("", "", 0, "");
                ShowProfileView();
                UpdateProfile();
            });
            SelectProfileVisibility = Visibility.Visible;
            ProfileViewVisibility = Visibility.Hidden;
            UpdateFiles();
        }
        private void UpdateProfile()
        {
            RaisePropertyChanged("CurrentProfile");
        }
        private void ShowProfileView()
        {
            SelectProfileVisibility = Visibility.Hidden;
            ProfileViewVisibility = Visibility.Visible;
            RaisePropertyChanged("SelectProfileVisibility");
            RaisePropertyChanged("ProfileViewVisibility");
        }
        private void ShowSelectionProfile()
        {
            SelectProfileVisibility = Visibility.Visible;
            ProfileViewVisibility = Visibility.Hidden;
            RaisePropertyChanged("SelectProfileVisibility");
            RaisePropertyChanged("ProfileViewVisibility");
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
            RaisePropertyChanged("Profiles");
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
