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

A** getTwoDimensionalArray1(unsigned int row, unsigned int col)
{
    A **p = new A* [row];
    for(int i = 0; i < row; ++i) {
        p[i] = new A[col]; 
    }

    return p;
}

void getTwoDimensionalArray2(A ***p, unsigned int row, unsigned int col)
{
    *p = new A* [row];
    for(int i = 0; i < row; ++i) {
        // *p[i] = new A[col];
        (*p)[i] = new A[col];
    }
}

int main(int argc, char const *argv[])
{
    unsigned int row = 2;
    unsigned int col = 3;

    A **p1 = getTwoDimensionalArray1(row, col);

    for(int i = 0; i < row; ++i) {
        delete [] p1[i];
        p1[i] = NULL;
    }
    delete [] p1;
    p1 = NULL;

    /*******************************************************/

    A **p2 = NULL;
    getTwoDimensionalArray2(&p2, row, col);
    for(int i = 0; i < row; ++i) {
        delete [] p2[i];
        p2[i] = NULL;
    }
    delete [] p2;
    p2 = NULL;

    return 0;
}