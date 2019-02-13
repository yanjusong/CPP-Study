#include <iostream>
#include <memory>
using namespace std;

class A
{
  public:
    void show()
    {
        cout << "A::show()" << endl;
    }
};

// Following sometimes error, and I don't known why?
// unique_ptr<A> getPtr()
// {
//     unique_ptr<A> ptr(new A);
//     return ptr;
// }

int main()
{
    unique_ptr<A> p1(new A);
    p1->show();

    // returns the memory address of p1
    cout << p1.get() << endl;

    // transfers ownership to p2
    unique_ptr<A> p2 = move(p1);
    p2->show();
    cout << p1.get() << endl;
    cout << p2.get() << endl;

    // transfers ownership to p3
    unique_ptr<A> p3 = move(p2);
    p3->show();
    cout << p1.get() << endl;
    cout << p2.get() << endl;
    cout << p3.get() << endl;

    unique_ptr<A> p4 = unique_ptr<A>(new A);
    p4->show();

    // any attempt to make a copy of unique_ptr will cause a compile time error
    // unique_ptr<string> p4 = p3;

    return 0;
}
