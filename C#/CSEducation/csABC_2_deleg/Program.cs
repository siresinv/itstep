//using System.Threading.Channels;

Operation<int, int>? op1 = Square;
Operation<int, int> op2 = new Operation<int, int>(Square);

op1 -= Square;

Console.WriteLine(op1?.Invoke(5));
Console.WriteLine(op2(6));

MathOperation operation = Mult;

Console.WriteLine(DoOperation(5, 6, Add));
Console.WriteLine(DoOperation(5, 6, Substract));
Console.WriteLine(operation(7,7));

int xx = 25;

Print();

static void Print()
{
    // Console.WriteLine(xx); //
}

static int DoOperation(int x, int y, MathOperation opearation) => opearation(x, y);

static int Square(int x) => x* x;

static int Add(int x, int y) => x + y;
static int Substract(int x, int y) => x - y;
static int Mult(int x, int y) => x * y;

delegate int MathOperation(int x, int y);

delegate T Operation<T, K>(K x);
    

