using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Tutorial
{

    class Person
    {

        // private fields
        private string _firstname = "";
        private string _lastname = "";
        private string _occupation = "";
        private int _age = 0;

        // public fields or public properties
        public string FirstName { get { return _firstname; } }
        public string LastName { get { return _lastname; } }
        public string Occupation { get { return _occupation; } }
        public int Age { get { return _age; } }


        /// <summary>
        /// Constructor
        /// </summary>
        /// <param name="firstname">Person's first name</param>
        /// <param name="lastname">Person's last name</param>
        /// <param name="occupation">Person's occupation</param>
        /// <param name="age">Person's age</param>
        public Person(string firstname, string lastname, string occupation, int age)
        {
            _firstname = firstname;
            _lastname = lastname;
            _occupation = occupation;
            _age = age;
        }


    }
}