using System;
using System.Collections.Generic;
using System.IO;
using System.Reflection;

namespace WPF.Models
{
    public class Database
    {
        /// <summary>
        /// Database - folder "Profiles" near executable file.
        /// </summary>
        public Database()
        {
            if (!IsExists)
            {
                CreateFolder();
            }
        }
        /// <summary>
        /// Returns only string names of .dat files.
        /// </summary>
        public List<string> Profiles
        {
            get
            {
                string[] files = Directory.GetFiles(Path);
                List<string> profiles = new List<string>();
                foreach (string file in files)
                {
                    if (file.Substring(file.Length - 4, 4).Equals(".dat"))
                    {
                        profiles.Add(file);
                    }
                }
                return profiles;
            }
        }
        /// <summary>
        /// To make full path to .dat file.
        /// </summary>
        private string MakePathToProfile(string profileName)
        {
            return Path + '\\' + profileName + ".dat";
        }
        /// <summary>
        /// Rewrite or create .dat file in database.
        /// Returns false if can not write.
        /// </summary>
        public bool EditOrCreateNewProfile(string profileName, Profile profile)
        {
            try
            {
                using (BinaryWriter writer = new BinaryWriter(
                    File.Open(MakePathToProfile(profileName), 
                    FileMode.OpenOrCreate)))
                {
                    writer.Write(profile.FirstName);
                    writer.Write(profile.LastName);
                    writer.Write(profile.Age);
                    writer.Write(profile.Job);
                    writer.Close();
                }
                return true;
            }
            catch
            {
                return false;
            }
        }
        /// <summary>
        /// Returns object with content inside .dat file.
        /// Exception, if file doesnt exists.
        /// </summary>
        public Profile ReadProfileByName(string profileName)
        {
            using (BinaryReader reader = new BinaryReader(
                File.Open(MakePathToProfile(profileName), 
                FileMode.Open)))
            {
                string firstName = reader.ReadString();
                string lastName = reader.ReadString();
                int age = reader.ReadInt32();
                string job = reader.ReadString();
                reader.Close();
                return new Profile(firstName, lastName, age, job);
            }
        }
        /// <summary>
        /// Path to "Profiles" folder.
        /// </summary>
        public string Path 
        { 
            get
            {
                string pathToExe = Assembly.GetExecutingAssembly().Location;
                string pathToDatabaseDirectory = pathToExe;
                for (int i = pathToDatabaseDirectory.Length - 1; i > 0; i--)
                {
                    if (pathToDatabaseDirectory[i] == '\\')
                    {
                        pathToDatabaseDirectory = pathToDatabaseDirectory.Substring(0, i);
                        break;
                    }
                }
                pathToDatabaseDirectory += "\\Profiles";
                return pathToDatabaseDirectory;
            }
        }
        /// <summary>
        /// Is "Profiles" folder exists.
        /// </summary>
        public bool IsExists 
        { 
            get
            {
                return Directory.Exists(Path);
            }
        }
        /// <summary>
        /// Creates the "Profiles" folder near executable file.
        /// </summary>
        public void CreateFolder()
        {
            Directory.CreateDirectory(Path);
        }
    }
}
