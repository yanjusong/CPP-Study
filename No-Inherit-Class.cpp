#include <iostream>
using namespace std;

class Parent;
class Base {
    friend class Parent;
private:
    Base() {}
};

class Parent : virtual public Base {
public:
    Parent() : Base() {}
};

// class Child : public Parent {
// public:
//     Child() {}
// };

int main(int argc, char const *argv[])
{
    Parent p;

    return 0;
}