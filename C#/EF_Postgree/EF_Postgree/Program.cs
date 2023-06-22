// See https://aka.ms/new-console-template for more information
// Console.WriteLine("Hello, World!");

using EF_Postgree;

using (ApplicationContext db = new ApplicationContext())
{
    User user1 = new User { Name = "Tom", Age = 33 };
    User user2 = new User { Name = "Bob", Age = 23 };

    db.Users.AddRange(user1, user2);
    db.SaveChanges();

}

using (ApplicationContext db = new ApplicationContext())
{
    var users = db.Users.ToList();
    Console.WriteLine("Users list:");
    foreach (User user in users)
    {
        Console.WriteLine($"{user.Id}.{user.Name} - {user.Age}");
    }
}