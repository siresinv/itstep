using Microsoft.AspNetCore.Identity;
using Microsoft.AspNetCore.Mvc;
using Microsoft.EntityFrameworkCore;
using web70_for_add_ef_identity_api_controller;

[ApiController]
[Route("[controller]")]
public class UserController: ControllerBase {

    private readonly UserManager<ChatUser> _userManager;
    
    public UserController(UserManager<ChatUser> userManager)
    {
        _userManager = userManager;
    }

    [HttpPost]
    [Route("create")]
    public async Task<ActionResult> CreateAsync([FromBody] RegisterModel registerModel)
    {
        ChatUser user = new ChatUser { UserName = registerModel.Username };
        var result = await _userManager.CreateAsync(user, registerModel.Password);
        if (result.Succeeded)
        {
            return CreatedAtRoute("getbyname", new { name = user.UserName }, new ChatUserDTO(user));
        }
        else
        {
            return BadRequest(result);
        }

    }


    [HttpGet]
    public async Task<List<ChatUser>> GetAllAsync() => await _userManager.Users.ToListAsync(u => new ChatUserDTO(u));


    [HttpGet("name/{name}", Name = "getbyname")]
    public async Task<IActionResult> GetByNameAsync(string name)
    {
        var user = await _userManager.FindByNameAsync(name);
        if (user != null)
        {
            return Ok(new ChatUserDTO(user));
        }
        else
        {
            return NotFound(name);
        }
    }


    [HttpGet("id/{id}", Name = "getbyid")]
    public async Task<IActionResult> GetByIdAsync(string id)
    {
        var user = await _userManager.FindByIdAsync(id);
        if (user != null)
        {
            return Ok(new ChatUserDTO(user));
        }
        else
        {
            return NotFound(id);
        }
    }

}