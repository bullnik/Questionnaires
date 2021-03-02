using Prism.Commands;
using Prism.Mvvm;
using System.Collections.Generic;
using System.Collections.ObjectModel;
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
        public DelegateCommand EditCurrentProfile { get; set; }
        public ObservableCollection<File> Profiles { get; set; }
        public Profile CurrentProfile { get; set; }
        public string CurrentProfileName { get; set; }
        private Database Database { get; set; }
        public Visibility SelectProfileVisibility { get; set; }
        public Visibility ProfileViewVisibility { get; set; }
        private bool _IsChangingEnable;
        public bool IsChangingEnable 
        { 
            get
            {
                return _IsChangingEnable;
            }
            set
            {
                _IsChangingEnable = value;
                RaisePropertyChanged("IsChangingEnable");
                RaisePropertyChanged("IsEditButtonEnable");
            }
        }
        public bool IsEditButtonEnable
        {
            get
            {
                return !_IsChangingEnable;
            }
        }

        public MainViewModel()
        {
            Database = new Database();
            Profiles = new ObservableCollection<File>();
            Back = new DelegateCommand(() =>
            {
                Database.UnlockProfile(CurrentProfileName);
                CurrentProfile = null;
                CurrentProfileName = null;
                IsChangingEnable = false;
                ShowSelectionProfile();
                UpdateFiles();
                UpdateProfile();
            });
            EditCurrentProfile = new DelegateCommand(() =>
            {
                if (Database.GetProfileAccessType(CurrentProfileName) 
                        == System.IO.FileShare.ReadWrite)
                {
                    Database.UnlockProfile(CurrentProfileName);
                    Database.LockProfile(CurrentProfileName, System.IO.FileShare.None);
                    IsChangingEnable = true;
                }
                else
                {
                    MessageBox.Show("Access denied", "Information");
                }
            });
            SaveCurrentProfile = new DelegateCommand(() =>
            {
                if (CurrentProfileName == null)
                {
                    CurrentProfileName = CurrentProfile.FirstName + '-' + CurrentProfile.LastName;
                }
                Database.UnlockProfile(CurrentProfileName);
                Database.EditOrCreateNewProfile(CurrentProfileName, CurrentProfile);
                IsChangingEnable = false;
            });
            OpenProfile = new DelegateCommand<string>((string str) =>
            {
                CurrentProfileName = str;
                System.IO.FileShare accessType = Database
                                .GetProfileAccessType(CurrentProfileName);
                if (accessType == System.IO.FileShare.ReadWrite 
                        || accessType == System.IO.FileShare.Read)
                {
                    CurrentProfile = Database.ReadProfileByName(str);
                    ShowProfileView();
                    Database.LockProfile(str, System.IO.FileShare.Read);
                    UpdateProfile();
                }
                else
                {
                    MessageBox.Show("Access denied", "Information");
                    CurrentProfileName = null;
                }
            });
            CreateNewProfile = new DelegateCommand(() =>
            {
                IsChangingEnable = true;
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
        private void UpdateFiles()
        {
            List<string> profiles = Database.Profiles;
            Profiles.Clear();
            foreach(string profile in profiles)
            {
                Profiles.Add(new File(profile));
            }
            RaisePropertyChanged("Profiles");
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
