#include <iostream>
using namespace std;

namespace YJS {
	class A;
}

class YJS::A {
public:
	void func();
};

void YJS::A::func()
{
	cout << "YJS::A::func() running" << endl;
}

int main(int argc, char const *argv[])
{
	YJS::A a;
	a.func();
	
	return 0;
}