using Microsoft.EntityFrameworkCore;
using test_appsettings_connectionstrings;

var builder = WebApplication.CreateBuilder();

builder.Services.AddDbContext<ApplicationContext>(option => option.UseNpgsql(builder.Configuration.GetConnectionString("PostgreConnection")));

var app = builder.Build();

app.UseHttpsRedirection();


app.Run();