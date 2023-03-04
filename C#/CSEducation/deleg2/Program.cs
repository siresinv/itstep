//using System;


using System.Collections.ObjectModel;
using System.Collections.Specialized;

namespace ObserCollection
{

    

    class Program
    {

        static void Main(string[] args)
        {
            var people = new ObservableCollection<Person>()
            {
                new Person("Tom"),
                new Person("Sam")
            };

            people.CollectionChanged += People_CollectionChanged;

            foreach (Person person in people) Console.WriteLine(person.Name);
            


            people.Add(new Person("Bob"));
            Person newPerson = new Person("TIM");
            people.Add(newPerson);
            people.Add(newPerson);
            people.Add(newPerson);
            people.Remove(newPerson);
            people.RemoveAt(1);

            newPerson.Name = "timm";

            people[1] = new Person("Dig");


            foreach (Person person in people) Console.WriteLine(person.Name);


        }

        class Person
        {
            public string Name { get; set; }
            public Person(string name) => Name = name;
        }


        static void People_CollectionChanged(object? sender, NotifyCollectionChangedEventArgs e)
        {
            switch (e.Action)
            {
                case NotifyCollectionChangedAction.Add:
                    if (e.NewItems?[0] is Person newPerson)
                        Console.WriteLine($"Added new Person: {newPerson.Name}");
                    break;
                case NotifyCollectionChangedAction.Remove:
                    if (e.OldItems?[0] is Person person)
                        Console.WriteLine($"Removed Person: {person.Name}");
                    break;
                case NotifyCollectionChangedAction.Replace:
                    if ((e.NewItems?[0] is Person replacingPerson) &&
                        (e.OldItems?[0] is Person replacedPerson))
                        Console.WriteLine($"Person {replacedPerson.Name} was replaced by {replacingPerson.Name}");
                    break;
            }
        }

    }
}