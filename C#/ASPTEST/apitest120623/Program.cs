using Microsoft.AspNetCore.Authorization;
using System.Linq.Expressions;
//using Microsoft.OpenApi;
//using Microsoft.AspNetCore.OpenApi;


var builder = WebApplication.CreateBuilder(args);

builder.Services.AddAuthentication().AddJwtBearer();
builder.Services.AddAuthorization();
//builder.Services.AddControllers();
builder.Services.AddEndpointsApiExplorer();
builder.Services.AddSwaggerGen();

var app = builder.Build();


app.UseAuthentication();
app.UseAuthorization();

if (app.Environment.IsDevelopment())
{
    app.UseSwagger();
    app.UseSwaggerUI();
}

app.MapGet("/list", [Authorize] () => "Hello World!");
//app.MapGet("/list2", () => "Hello, WORK!!!").WithOpenApi();
app.MapGet("/list2", () => "Hello, WORK!!!");



app.Run();


// var parseExpr = (string s) => int.Parse(s);