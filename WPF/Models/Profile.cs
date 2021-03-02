using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace WPF.Models
{
    public class Profile
    {
        public string FirstName { get; set; }
        public string LastName { get; set; }
        public int Age { get; set; }
        public string Job { get; set; }

        public Profile(string firstName, string lastName, int age, string job)
        {
            FirstName = firstName;
            LastName = lastName;
            Age = age;
            Job = job;
        }
    }
}
