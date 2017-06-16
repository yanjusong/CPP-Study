#include <iostream>
using namespace std;

struct A
{
    int data;

    A() : data(1) 
    {
        cout << "A() called" << endl;
    }

    ~A()
    {
        cout << "~A() called" << endl;
    }
};

A* getOneDimensionalArray1(unsigned int size)
{
    return new A[size];
}

void getOneDimensionalArray2(A **p, unsigned int size)
{
    *p = new A[10];
}

int main(int argc, char const *argv[])
{
    A *p1 = getOneDimensionalArray1(10);

    delete [] p1;
    p1 = NULL;


    A *p2 = NULL;
    getOneDimensionalArray2(&p2, 10);
    delete [] p2;
    p2 = NULL;

    return 0;
}