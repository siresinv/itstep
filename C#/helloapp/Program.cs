using System.Reflection.PortableExecutable;

WebApplicationOptions options = new WebApplicationOptions() { Args = args};

WebApplicationBuilder builder = WebApplication.CreateBuilder(options);

WebApplication app = builder.Build();

//app.UseWelcomePage();

//app.MapGet("/a", () => "Hello World!");



app.Run(async(context) =>
{
    context.Response.ContentType = "text/html; charset=unf-8";

    var stringBulder = new System.Text.StringBuilder("<table>");

    foreach (var header in context.Request.Headers)
    {
        stringBulder.Append($"<tr><td>{header.Key}</td><td>{header.Value}</td></tr>");
    }

    stringBulder.Append("</table>");

    await context.Response.WriteAsync(stringBulder.ToString());


});

app.Run();
