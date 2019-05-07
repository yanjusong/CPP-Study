#include "SmartPtr.hpp"

#include <iostream>
using namespace std;

struct Student
{
    int id_;
    Student(int id) : id_(id) {}
};

int main()
{
    cout << "\ntest 1:\n";
    {
        SmartPtr<int> ptr1(new int(2));
        cout << "ptr1 use_count= " << ptr1.use_count() << endl;
        {
            SmartPtr<int> ptr2(ptr1);
            cout << "ptr1 use_count= " << ptr1.use_count() << endl;
            cout << "ptr2 use_count= " << ptr2.use_count() << endl;
            {
                SmartPtr<int> ptr3 = ptr2;
                cout << "ptr1 use_count= " << ptr1.use_count() << endl;
                cout << "ptr2 use_count= " << ptr2.use_count() << endl;
                cout << "ptr3 use_count= " << ptr3.use_count() << endl;

                cout << *ptr1 << endl;
                *ptr1 = 20;
                cout << *ptr2 << endl;
            }
            cout << "ptr1 use_count= " << ptr1.use_count() << endl;
            cout << "ptr2 use_count= " << ptr2.use_count() << endl;
        }
    }

    cout << "\ntest 2:\n";
    {
        SmartPtr<Student> ptr1(new Student(100));
        cout << "student id= " << (*ptr1).id_ << endl;
        cout << "student id= " << ptr1->id_ << endl;
        SmartPtr<Student> ptr2 = ptr1;
        ptr1->id_ = 101;
        cout << "after modify id\n";
        cout << "student id= " << (*ptr1).id_ << endl;
        cout << "student id= " << ptr1->id_ << endl;
    }

    return 0;
}