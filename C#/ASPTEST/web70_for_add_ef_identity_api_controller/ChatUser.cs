using Microsoft.AspNetCore.Identity;
using web70_for_add_ef_identity_api_controller;

namespace web70_for_add_ef_identity_api_controller
{
    public class ChatUser: IdentityUser
    {
        // public string NickName2 { get; set; } = null!;
        // [NotMapped] для ненужных полей можно попробовать сделать
    }
}


public class ChatUserDTO
{
    public string Id { get; set; } = null!;
    public string UserName { get; set; } = null!;

    public ChatUserDTO() { }
    public ChatUserDTO(ChatUser chatuser) =>
        (Id, UserName) = (chatuser.Id, chatuser.UserName);
}
