var app = WebApplication.Create(args);


app.UseHttpsRedirection();
app.UseStaticFiles();

app.MapGet("/", () => new {message = "Hello, WORK!!!"});
app.Run();