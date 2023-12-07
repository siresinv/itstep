using Microsoft.AspNetCore.Mvc;

namespace Authorization.IdentityServer.API.Controllers
{
    public class SiteController : Controller
    {
        public IActionResult Index()
        {
            return View();
        }
    }
}
