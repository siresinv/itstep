public class Person2 /*(string Name, int Age)*/
{
    public string Name;
    public string Age;
    public Person2(string Name)/*: this (Name, 100)*/ { }
    public void Print() => Console.WriteLine($"{Name} {Age}");
}