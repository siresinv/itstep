using Microsoft.IdentityModel.Tokens;
using System.Text;

public class AuthOptions
{
    public const string ISSUER = "AuthServer";
    public const string AUDIENCE = "All";
    const string KEY = "mysupersecret_secretkey!";
    public static SymmetricSecurityKey GetSymmetricSecurityKey() =>
        new SymmetricSecurityKey(Encoding.UTF8.GetBytes(KEY));
}