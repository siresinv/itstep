Person person1 = new Person("BOOOB");
Employee employee1 = new Employee();

Console.WriteLine(person1.Name);
Console.WriteLine(employee1.Name);
employee1.Print();
employee1.PrintEmployee();

Person person2 = employee1;
Employee epmloyee2 = (Employee)person2;
Person pers2 = (Employee)person2;
pers2.Print();
//Employee epmloyee2 = (Employee)person1;


Employee? employee3 = person1 as Employee;
if (employee3 == null)
{
    Console.WriteLine("!!!");
}


if(person1 is Employee empl)
{
    empl.PrintEmployee();
    Console.WriteLine("???");
}


epmloyee2.PrintEmployee();

person2.Print();


class Person
{
    public string Name { get; set; }
    public Person(string name) => Name = name;

    public Person()
    {
        Name = "Tom";
        Console.WriteLine("Constructor Person");
    }

    public void Print() => Console.WriteLine($"Person {Name}");
}

class Employee: Person
{
    public string? Company { get; set; }

    public Employee()
    {
        Console.WriteLine("Constructor Employee");
    }

    public void PrintEmployee()
    {
        Console.WriteLine("PrintEmployee");
    }

    //public Employee(string name, string company): base(name) => Company = company;
}

class Client: Person
{
    public string Bank { get; set; }

    public Client(string name, string bank) : base(name) => Bank = bank;
}