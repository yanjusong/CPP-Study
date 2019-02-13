#include "SmartPtr.hpp"

#include <iostream>
using namespace std;

int main()
{
    int *p = new int(2);

    {
        SmartPtr<int> ptr1(p);
        cout << ptr1.use_count() << endl;
        {
            SmartPtr<int> ptr2(ptr1);
            cout << ptr1.use_count() << endl;
            cout << ptr2.use_count() << endl;
            {
                SmartPtr<int> ptr3 = ptr2;
                cout << ptr1.use_count() << endl;
                cout << ptr2.use_count() << endl;
                cout << ptr3.use_count() << endl;

                // cout << *ptr1 << endl;
                // *ptr1 = 20;
                // cout << *ptr2 << endl;
            }
        }
    }

    return 0;
}