using IdentityModel;
using IdentityServer4.Models;

namespace Authorization.IdentityServer.API
{
    public static class Configuration
    {
        internal static IEnumerable<ApiResource> GetApiResources() =>
            new List<ApiResource>
            {
                new ApiResource("OrdersAPI")
            };

        internal static IEnumerable<IdentityResource> GetIdentityResouces() =>
            new List<IdentityResource>
            {
                new IdentityResources.OpenId()
            };
    

        internal static IEnumerable<Client> GetClients() => 
        new List<Client>
        { 
            new Client
            {
                ClientId = "client_id",
                ClientSecrets = {new Secret("client_secret".Sha256())},

                AllowedGrantTypes = GrantTypes.ClientCredentials,

                AllowedScopes =
                {
                    "OrdersAPI"
                }
                
            }

        };

        internal static IEnumerable<ApiScope> GetApiScopes() =>
            new List<ApiScope>
            {
                new ApiScope(name: "OrdersApii")
            };
    }
}
