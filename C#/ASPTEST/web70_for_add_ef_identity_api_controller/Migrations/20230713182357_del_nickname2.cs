using Microsoft.EntityFrameworkCore.Migrations;

#nullable disable

namespace web70_for_add_ef_identity_api_controller.Migrations
{
    /// <inheritdoc />
    public partial class del_nickname2 : Migration
    {
        /// <inheritdoc />
        protected override void Up(MigrationBuilder migrationBuilder)
        {
            migrationBuilder.DropColumn(
                name: "NickName2",
                table: "AspNetUsers");
        }

        /// <inheritdoc />
        protected override void Down(MigrationBuilder migrationBuilder)
        {
            migrationBuilder.AddColumn<string>(
                name: "NickName2",
                table: "AspNetUsers",
                type: "text",
                nullable: true);
        }
    }
}
