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

int main()
{
    shared_ptr<A> p1(new A);
    shared_ptr<A> p2 = p1;
    weak_ptr<A> pu = p1;

    cout << p1.get() << endl;
    cout << p2.get() << endl;

    cout << p1.use_count() << endl;
    cout << p2.use_count() << endl;
    cout << pu.use_count() << endl;
    cout << pu.expired() << endl;
    if (shared_ptr<A> pa = pu.lock())
    {
        pa->show();
    }
    else
    {
        cout << "pu指向对象为空" << endl;
    }

    p1.reset();
    cout << p1.use_count() << endl;
    cout << p2.use_count() << endl;
    cout << pu.use_count() << endl;
    cout << pu.expired() << endl;
    if (shared_ptr<A> pa = pu.lock())
    {
        pa->show();
    }
    else
    {
        cout << "pu指向对象为空" << endl;
    }

    p2.reset();
    cout << p1.use_count() << endl;
    cout << p2.use_count() << endl;
    cout << pu.use_count() << endl;
    cout << pu.expired() << endl;
    if (shared_ptr<A> pa = pu.lock())
    {
        pa->show();
    }
    else
    {
        cout << "pu指向对象为空" << endl;
    }

    return 0;
}
