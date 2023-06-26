using Microsoft.EntityFrameworkCore;

namespace test_appsettings_connectionstrings
{
    public class ApplicationContext: DbContext
    {
        public ApplicationContext(DbContextOptions<ApplicationContext> options):base(options) {
            //Database.EnsureCreated();
        }
        public DbSet<chat_user> Users { get; set; } = null!;

    }
}
