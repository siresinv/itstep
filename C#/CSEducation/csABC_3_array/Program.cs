// See https://aka.ms/new-console-template for more information

using _namespaces1;
using _namespaces2;
using firstclasslib;


Person1 person = new();
//Person2 person2 = new();


Console.WriteLine("Hello, World!");

int[] ar1 = new int[4] { 1, 2, 3, 4 };

foreach (int nums in ar1)
{
    Console.WriteLine(nums);
}


int[,] ar2_3 = new int[2, 3] { { 1, 2, 3 }, { 4, 5, 6 } };



for (int row = 0; row < 2; row++) 
{
    for (int col = 0; col < 3; col++)
    {
        Console.Write(ar2_3[row, col]);
    }
    Console.WriteLine();
}


int[][] ar3 = { 

    new int[] {1,2,3},
    new int[] {4,5},
    new int[] {6,7,8,9}
};


foreach (int num in ar3[2])
{
    Console.Write($"{num} ");
}


Console.WriteLine();


void Print(string mes) => Console.WriteLine(mes);

Print("!!!");


int sum(int x, int y) => x + y;

Console.WriteLine(sum(4,5));

int x = 55;

void func1(ref int x, out int res)
{
    x++;
    res = 10;
}

//int result;
func1(ref x, out int result);

Console.WriteLine(x + result);




int sum2 (params int[] par)
{
    int res = 0;
    foreach (int n in par)
    {
        res += n;
    }
    return res;
}


Console.WriteLine(sum2(1,2,3,4,5));


int fact(int n){

    if (n == 1) return 1;
    return n * fact(n - 1);
}


Console.WriteLine(fact(5));


int DoOperation(int op, int x, int y) => op switch
{
    1 => x+y,
    2 => x-y,
    3 => x*y,
    _ => 0
};

Console.WriteLine(DoOperation(5, 3, 3));


int DoOperation2 (int x, int y, operation op)
{
    int res = op switch
    {
        operation.add => x+y,
        operation.sub => x-y,
        operation.mult => x*y,
        operation.div => x/y,
        _ => 0

    };

    return res;
}


Console.WriteLine(DoOperation2(3, 33, operation.mult));


enum operation
{
    add,
    sub,
    mult,
    div
}





