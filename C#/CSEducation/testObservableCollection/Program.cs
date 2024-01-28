using System.Collections.ObjectModel;
using System.Collections.Specialized;



/*ObservableCollection<string> people = new ObservableCollection<string>(new string[] { "Tom", "Bob", "Sam" })
{
    "Tom1", "Bob1", "Sam1"
};


Console.WriteLine(people[3]);*/

var person = new ObservableCollection<Person>()
{
    new Person("Tom"),
    new Person("Sam")
};


person.CollectionChanged += Person_CollectionChanged;

person.Add(new Person("Bob"));


void Person_CollectionChanged(object? sender, NotifyCollectionChangedEventArgs e)
{
    switch (e.Action)
    {
        case NotifyCollectionChangedAction.Add:
            if (e.NewItems?[0] is Person newPerson)
                Console.WriteLine($"Added new Element: {newPerson.Name}");
            break;
        case NotifyCollectionChangedAction.Remove:
            break;
        case NotifyCollectionChangedAction.Replace:
            break;
    }
}