Person person1 = new() { Name = "tom", Age = 33 };
person1.Print();


void ChangePerson(ref Person person)
{
    person.Name = "Bob";

    person = new() { Name = "BILL"};
}

ChangePerson(ref person1);
person1.Print();


public class Person
{
    public string Name;
    public int Age;

    /*public Person(string name, int age)
    {
        Name = name;
        Age = age;
    }*/



    public void Print()
    {
        Console.WriteLine($"{Name} {Age}");
    }
}