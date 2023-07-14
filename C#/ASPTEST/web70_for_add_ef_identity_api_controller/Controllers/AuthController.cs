using Microsoft.AspNetCore.Identity;
using Microsoft.AspNetCore.Mvc;
using Microsoft.IdentityModel.Tokens;
using System.IdentityModel.Tokens.Jwt;
using System.Security.Claims;

namespace web70_for_add_ef_identity_api_controller.Controllers
{
    [ApiController]
    [Route("[controller]")]
    public class AuthController : ControllerBase
    {
        private readonly UserManager<ChatUser> _userManager;
        // private readonly SignInManager<ChatUser> _signInManager;

        public AuthController(UserManager<ChatUser> userManager/*, SignInManager<ChatUser> signInManager*/)
        {
            _userManager = userManager;
            // _signInManager = signInManager;
        }

        [HttpPost]
        [Route("login")]
        public async Task<ActionResult> LoginAsync(LoginModel loginModel)
        {
            string username = loginModel.Username;
            var user = await _userManager.FindByNameAsync(username);
            if (user != null)
            {
                // var signinResult = await _signInManager.PasswordSignInAsync(signInModel.Username, signInModel.Password, false, false);

                var checkPassResult = await _userManager.CheckPasswordAsync(user, loginModel.Password);

                if (checkPassResult)
                {
                    string guid = user.Id;

                    var jwt = new JwtSecurityToken(
                        issuer: AuthOptions.ISSUER,
                        audience: AuthOptions.AUDIENCE,
                        claims: new List<Claim>
                        {
                        new Claim (JwtRegisteredClaimNames.Sub, guid)
                        },
                        expires: DateTime.UtcNow.Add(TimeSpan.FromMinutes(300)),
                        signingCredentials: new SigningCredentials(AuthOptions.GetSymmetricSecurityKey(),
                            SecurityAlgorithms.HmacSha256));

                    var response = new
                    {
                        access_token = new JwtSecurityTokenHandler().WriteToken(jwt),
                        username = username
                    };

                    return Ok(response);
                }
            }

            return Unauthorized("Unauthorized");
        }
        
    }
}
