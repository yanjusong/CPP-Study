#include <iostream>
#include <memory>

class A
{
  public:
    void show()
    {
        std::cout << "A::show()\n";
    }
};

void consumeAutoptr(std::auto_ptr<A> p)
{
    p->show();
}

void notConsumeAutoptr(std::auto_ptr<A> &p)
{
    p->show();
}

int main()
{
    // p1 is an auto_ptr of type A
    std::auto_ptr<A> p1(new A);
    p1->show();

    // returns the memory address of p1
    std::cout << "p1.get():" << p1.get() << "\n";

    // copy constructor called, this makes p1 empty.
    std::auto_ptr<A> p2(p1);
    p2->show();

    std::cout << "p1 as a param pass to another auto_ptr obj's copy constructor.\n";
    // p1 is empty now
    std::cout << "p1.get():" << p1.get() << "\n";
    // p2 copy from p1
    std::cout << "p2.get():" << p2.get() << "\n";

    p1 = p2;

    std::cout << "p2 as a param pass to p1's assignment constructor.\n";
    // p1 copy from p2
    std::cout << "p1.get():" << p1.get() << "\n";
    // p2 is empty now
    std::cout << "p2.get():" << p2.get() << "\n";

    notConsumeAutoptr(p1);
    // p1 is not empty now
    std::cout << "p1.get():" << p1.get() << "\n";

    consumeAutoptr(p1);
    // p1 is empty now
    std::cout << "p1.get():" << p1.get() << "\n";

    return 0;
}
