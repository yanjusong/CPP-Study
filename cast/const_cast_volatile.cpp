#include <iostream>
#include <typeinfo>
using namespace std;

int main(void)
{
    int a1 = 40;
    const volatile int *b1 = &a1;
    // PVKi (pointer to a volatile and constant integer) 
    cout << "typeid of b1 " << typeid(b1).name() << '\n';

    int *c1 = const_cast<int *>(b1);
    // Pi (Pointer to integer)
    cout << "typeid of c1 " << typeid(c1).name() << '\n';
    return 0;
}
