#include <iostream>
using namespace std;

int fun(int *ptr)
{
    *ptr = *ptr + 10;
    return (*ptr);
}

int fun(int &ptr)
{
    ptr += 10;
    return ptr;
}

void test1()
{
    cout << "in test1()" << endl;
    const int val = 10;
    const int *ptr = &val;
    int *ptr1 = const_cast<int *>(ptr);
    fun(ptr1);
    cout << val << endl;
}

void test2()
{
    cout << "in test2()" << endl;
    int val = 10;
    const int *ptr = &val;
    int *ptr1 = const_cast<int *>(ptr);
    fun(ptr1);
    cout << val << endl;
}

void test3()
{
    cout << "in test3()" << endl;
    const int val = 10;
    const int &ptr = val;
    int &ptr1 = const_cast<int &>(ptr);
    fun(ptr1);
    cout << val << endl;
}

void test4()
{
    cout << "in test4()" << endl;
    int val = 10;
    const int &ptr = val;
    int &ptr1 = const_cast<int &>(ptr);
    fun(ptr1);
    cout << val << endl;
}

int main()
{
    test1();
    test2();
    test3();
    test4();

    int a1 = 40; 
    const int* b1 = &a1; 
    // error: const_cast from 'const int *' to 'char *' is not allowed
    // char* c1 = const_cast <char *> (b1);

    return 0;
}
