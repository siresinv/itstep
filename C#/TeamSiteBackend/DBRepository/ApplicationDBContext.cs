using Microsoft.EntityFrameworkCore;
using Models;
using System.Net.Mail;


namespace DBRepository
{
    public class ApplicationDBContext: DbContext
    {
        DbSet<MainMenu> menuItems { get; set; } = null!;
        public ApplicationDBContext(DbContextOptions<ApplicationDBContext> options)
            : base(options)
        {
            Database.EnsureCreated();
        }

    }
}
