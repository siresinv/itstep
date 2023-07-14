// See https://aka.ms/new-console-template for more information
Console.WriteLine("Hello, WORK! csABS_1");

var v1 = new { prop1 = 1, prop2 = "2" };
var v2 = new { prop1 = 2, prop2 = "2" };

//v1.prop1 = 3;

Console.WriteLine(v1.prop1 + v2.prop2);
Console.WriteLine(v1.Equals(v2));

Console.WriteLine(3.Equals("3"));


//Contact contact1 = new("ivan", "saransk");
//Contact contact2 = new("petr");


//Contact contact3 { "ivan", "sarans"};

Contact contact4 = new Contact { Name = "stepan", Address = "moscow" };

contact4.Name = "asd";
contact4.Address = "ADF";

Console.WriteLine(contact4.Name);

class Person_init
{

}


class Contact
{
    public string Name { get; init; } = "";
    public string Address { get; set; } = "";


    /*public Contact (string contactName, string contactAddress)
    {
        Name = contactName;
        Address = contactAddress;
    }*/

    /*public Contact(string contactName)
    {
        Name = contactName;
        //Address = contactAddress;
    }*/

    //public void ChangeAddress(string newName) => Name = newName;

    public void ChangeAddress(string newAddress) => Address = newAddress;

}

