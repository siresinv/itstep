using System.ComponentModel.DataAnnotations;

namespace web70_for_add_ef_identity_api_controller
{
    public class LoginModel
    {
        [Required]
        public string Username { get; set; } = null!;
        
        [Required]
        public string Password { get; set; } = null!;
    }
}
