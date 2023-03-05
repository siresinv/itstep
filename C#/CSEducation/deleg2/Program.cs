//using System;


using System.Collections.ObjectModel;
using System.Collections.Specialized;
using System.Diagnostics.Metrics;
using System.Globalization;

namespace ObserCollection
{

    

    class Program
    {

        interface IMovable
        {
            public void Move() => Console.WriteLine("DEFAULT");
            public string Name { get; }
            delegate void MoveHandler(); //protected internal 
            event MoveHandler MoveEvent;

        }


        class Person : IMovable
        {
            string name;

            public IMovable.MoveHandler? moveEvent;

             public event IMovable.MoveHandler MoveEvent
            {
                add => moveEvent += value;
                remove => moveEvent -= value;
            }

            public string Name { get => name; }

            public Person(string name) => this.name = name;

            public void Move()
            {
                Console.WriteLine($"{name} is walking");
                moveEvent?.Invoke();
            }
        }



        static void Main(string[] args)
        {
            IMovable tom = new Person("Tom");
            tom.MoveEvent += () => Console.WriteLine($"{tom.Name} is moving");
            tom.Move();

        }


    }
}