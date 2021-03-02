using Prism.Commands;
using Prism.Mvvm;
using System.Collections.Generic;
using System.Collections.ObjectModel;
using System.Linq;
using WPF.Models;

namespace WPF.ViewModels
{
    public class MainViewModel : BindableBase
    {
        private DelegateCommand a { get; set; }
        private ObservableCollection<File> Profiles { get; set; }
        private Database database { get; set; }

        public MainViewModel()
        {
            database = new Database();
            Profiles = new ObservableCollection<File>();
            UpdateFiles();
        }
        /// <summary>
        /// Verify profiles with database.
        /// </summary>
        public void UpdateFiles()
        {
            List<string> profiles = database.Profiles;
            Profiles.Clear();
            foreach(string profile in profiles)
            {
                Profiles.Add(new File(profile));
            }
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
