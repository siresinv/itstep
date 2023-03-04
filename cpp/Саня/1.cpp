#include <iostream>

using namespace std;

int main()
{
	int a, b;
	cin >> a;
	cin >> b;
	if (a == 0) {
		if (b == 0)
			cout << "INF";

		else
			cout << "NO";

	}
	else {
		if (b % a == 0)
			cout << (-b) / a;
		else
			cout << "NO";
	}

	return 0;
}