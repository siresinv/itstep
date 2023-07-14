using Microsoft.AspNetCore.Identity.EntityFrameworkCore;
using Microsoft.EntityFrameworkCore;

namespace web70_for_add_ef_identity_api_controller
{
    public class ApplicationContext: IdentityDbContext<ChatUser>
    {
        public DbSet<ChatUser> ChatUsers { get; set; } = null!;
        public ApplicationContext(DbContextOptions<ApplicationContext> options)
            : base(options)
        {
            //Database.EnsureCreated();
        }
    }
}
