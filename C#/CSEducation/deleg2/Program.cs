using System.Runtime.CompilerServices;

namespace extensionMethods
{


    public static class StringExtension
    {
        public static int CharCount(this string str, char c)
        {
            int counter = 0;
            for (int i = 0; i<str.Length; i++)
            {
                if (str[i] == c)
                {
                    counter++;
                }
            }
            return counter;
        }
    }


    class User
    {
        public string Name { get; set; }
        public User(string name) => Name = name;
    }

    static class UserExtension
    {
        public static string GetName(this User obj)
        {
            return obj.Name;
        }

    }

    class Program
    {


        

        static void Main(string[] args)
        {
            string str = "Hello, WORK!";

            Console.WriteLine(str.CharCount('l'));


            User user1 = new User("Tom");

            Console.WriteLine(user1.GetName());
        }
    }
}