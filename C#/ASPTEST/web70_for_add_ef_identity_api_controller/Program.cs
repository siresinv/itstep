using Microsoft.EntityFrameworkCore;
using web70_for_add_ef_identity_api_controller;
using Microsoft.AspNetCore.Identity;
using Microsoft.IdentityModel.Tokens;
using Microsoft.AspNetCore.Authentication.JwtBearer;

var builder = WebApplication.CreateBuilder(args);

var connectionString = builder.Configuration.GetConnectionString("PostgreConnection") ?? throw new InvalidOperationException("Connection string 'PostgreConnection' not found.");
builder.Services.AddDbContext<ApplicationContext>(context =>
    context.UseNpgsql(connectionString));

builder.Services.AddIdentity<ChatUser, IdentityRole>().AddEntityFrameworkStores<ApplicationContext>();

builder.Services.AddAuthorization();

builder.Services.AddAuthentication(/*options => options.DefaultChallengeScheme = */JwtBearerDefaults.AuthenticationScheme)
    .AddJwtBearer(options => options.TokenValidationParameters = new TokenValidationParameters
    {
        ValidateIssuer = true,
        ValidIssuer = AuthOptions.ISSUER,
        ValidateAudience = true,
        ValidAudience = AuthOptions.AUDIENCE,
        ValidateLifetime = true,
        IssuerSigningKey = AuthOptions.GetSymmetricSecurityKey(),
        ValidateIssuerSigningKey = true
    });




builder.Services.AddControllers();
builder.Services.AddEndpointsApiExplorer();
builder.Services.AddSwaggerGen();


var app = builder.Build();

app.UseSwagger();
app.UseSwaggerUI();

app.UseAuthentication();
app.UseAuthorization();

app.MapControllers();

app.Run();
