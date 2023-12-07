class Person
{
    public string Name = "Undefined";
    public int Age;

    public Person(): this ("Undefined")
    {
        Console.WriteLine("Default contructor");
        //Age = 35;

    }

    public Person(string name) : this(name, 100) => Console.WriteLine("2 contructor");
    public Person(string name,int age)
    {
        Name = name;
        Age = age;
        Console.WriteLine("3 contructor");
    }

    //public Person(string name) { Name = name; Age = 100; }
    //public Person(string name, int age) { Name = name; Age = age; }

    //Console.WriteLine($"{Name} {Age}");
    public void Print() => Console.WriteLine($"{Name} {Age}");
}