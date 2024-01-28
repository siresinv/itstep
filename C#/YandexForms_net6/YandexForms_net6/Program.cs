using Yandex.Cloud;
using Yandex.Cloud.Credentials;
using Yandex.Cloud.Functions;
using Yandex.Cloud.Resourcemanager.V1;



var sdk = new Sdk(new OAuthCredentialsProvider("y0_AgAAAAAnpEmGAATuwQAAAAD1utUB71L9ztpLSNqGD2He2TYUcl1kK7c"));
var response = sdk.Services.Resourcemanager.CloudService.List(new ListCloudsRequest());

//var resp1 = sdk.Services.Resourcemanager.CloudService.





foreach (var c in response.Clouds)
{
    Console.WriteLine($"{c.Name} ({c.Id})");
}


/*public class Handler: YcFunction<int, bool>
{
    public bool FunctionHandler(int number, Context c)
    {
        Console.WriteLine($"Function name: {c.FunctionId}");
        Console.WriteLine($"Function version: {c.FunctionVersion}");
        Console.WriteLine($"Service account token: {c.TokenJson}");
        return number % 2 == 0;
    }
}*/


