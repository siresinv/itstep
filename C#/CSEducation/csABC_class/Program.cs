using firstclasslib;

Class1 class1 = new Class1();
class1.Print();

Person person = new Person();


person.Age = 23;
person.Print();




Person tom = new Person("Tom");
tom.Print();

Person bob = new Person(age: 44, name: "BOOOB");
bob.Print();

var sam = new Person2("BIILL");
Console.WriteLine(sam);