using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Reflection;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleTest
{
    class Program
    {
        static void Main(string[] args)
        {
            string path = GetDatabasePath();
            string[] files = Directory.GetFiles(path);
            Console.WriteLine("Files in dir:");
            foreach (string f in files)
            {
                Console.WriteLine(f);
            }
            Console.WriteLine("Press any key to create a new profile");
            Console.ReadKey();

            Profile profile = new Profile("Ненаход", "Мефедронов", 19);
            path += "\\Nenaxod.dat";

            using (BinaryWriter bw = new BinaryWriter(File.Open(path, FileMode.Open)))
            {
                bw.Write(profile.FirstName);
                bw.Write(profile.LastName);
                bw.Write(profile.Age);

                using (BinaryWriter bw3 = new BinaryWriter(File.Open(path, FileMode.Open)))
                {
                    bw3.Write(profile.FirstName);
                    bw3.Write(profile.LastName);
                    bw3.Write(profile.Age);
                }
            }

            using (BinaryReader br = new BinaryReader(File.Open(path, FileMode.Open)))
            {
                Console.WriteLine(br.ReadString());
                Console.WriteLine(br.ReadString());
                Console.WriteLine(br.ReadInt32());
                br.Close();
            }

            Console.ReadKey();
        }

        public class Profile
        {
            public string FirstName { get; set; }
            public string LastName { get; set; }
            public int Age { get; set; }

            public Profile(string firstName, string lastName, int age)
            {
                FirstName = firstName;
                LastName = lastName;
                Age = age;
            }
        }

        static bool IsDatabaseExists()
        {
            string dir = GetDatabasePath();
            return Directory.Exists(dir);
        }

        static string GetDatabasePath()
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
}
