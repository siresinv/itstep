using Microsoft.EntityFrameworkCore;
using Microsoft.EntityFrameworkCore.Storage;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace EF_Postgree
{
    internal class ApplicationContext: DbContext
    {
        public DbSet<User> Users { get; set; }
        /*public ApplicationContext()
        {
            Database.EnsureCreated();
        }*/
        protected override void OnConfiguring(DbContextOptionsBuilder optionBuilder)
        {
            optionBuilder.UseNpgsql("Host=localhost; Port=5432;Database=usersdb2;Username=postgres;Password=root");
            //optionBuilder.UseNpgsql("Host=212.113.123.138; Port=32768;Database=chatusers;Username=admin;Password=iTtoURisT!23");
        }
    }
}
