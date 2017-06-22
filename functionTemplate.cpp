#include <iostream>
using namespace std;

template<typename T>
T MAX(T a, T b)
{
	return a > b ? a : b;
}

int main(int argc, char const *argv[])
{
	int ia = 10, ib = 11;
	cout << MAX(ia, ib) << endl;

	double da = 1.0, db = 0.9;
	cout << MAX(da, db) << endl;

	char ca = 'a', cb = 'a';
	cout << MAX(ca, cb) << endl;

	return 0;
}