using Microsoft.AspNetCore.Mvc;
using System.Reflection.Metadata.Ecma335;

namespace Authorization.Users.API.Controllers
{
    [Route("[controller]")]
    public class SiteController : Controller
    {
        private readonly IHttpClientFactory _httpClientFactory;

        public SiteController(IHttpClientFactory httpClientFactory)
        {
            _httpClientFactory = httpClientFactory;
        }

        [Route("[action]")]
        public IActionResult Index()
        {
            return View();
        }


        [Route("[action]")]
        public async Task<IActionResult> GetOrdersAsync()
        {
            //ViewBag.Message = "Test";

            var ordersClient = _httpClientFactory.CreateClient();

            var response = await ordersClient.GetAsync("https://localhost:5001/site/secret");

            var message = await response.Content.ReadAsStringAsync();

            ViewBag.Message = message;

            return View();
        }

    }
}
