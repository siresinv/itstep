Person tom = new("BOOOB") { Age = 4, company = new Company() { Title = "IBM"} };
tom.Print();
Console.WriteLine(tom);

(string name, int age) = tom;

Console.WriteLine($"{name} {age}");

string name2;
System.Int32 age2;
tom.Deconstruct(out name2, out age2);
Console.WriteLine();

public class Person
{
    public string Name;
    public int Age;
    public Company company;

    public Person(string name)
    {
        Name = name;
    }

    public void Print()
    {
        Console.WriteLine($"{Name} {Age} {company.Title}");
    }

    public void Deconstruct(out string personName, out int personAge)
    {
        personName = Name;
        personAge = Age;
    }
}


public class Company
{
    public string Title = "Undefined";
}