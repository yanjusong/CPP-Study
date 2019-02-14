#include <iostream>
using namespace std;

int main()
{
    float f = 3.5;
    int a = f; // this is how you do in C
    int b = static_cast<int>(f);
    cout << a << endl;
    cout << b << endl;

    char c = 'a'; 
    // error: static_cast from 'char *' to 'int *' is not allowed
    // int* pc = static_cast<int*>(&c); 

    return 0;
}
