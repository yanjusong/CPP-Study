// CPP program to illustrate Run Time Type Identification
#include <iostream>
using namespace std;

class B
{
  public:
    virtual ~B() {}
};

class D : public B
{
};

int main()
{
    B *b = new D;
    // if class B has no virtual function, then dynamic_cast will be error.
    D *d = dynamic_cast<D *>(b);
    if (d != NULL)
        cout << "works" << endl;
    else
        cout << "cannot cast B* to D*" << endl;

    return 0;
}
