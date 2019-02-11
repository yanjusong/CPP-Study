#include <iostream>

class Base
{
  public:
    virtual void f()
    {
        std::cout << "in Base::f()\n";
    }
    virtual void g()
    {
        std::cout << "in Base::g()\n";
    }

  private:
    virtual void h()
    {
        std::cout << "in Base::h()\n";
    }
};

typedef void (*VFunc)();

#if __SIZEOF_POINTER__ == 4
typedef int PtrType;
#elif __SIZEOF_POINTER__ == 8
typedef long long PtrType;
#endif

int main()
{
    Base b;
    PtrType *virtualFuncPtr = (PtrType *)(&b);
    PtrType *firstVirtualFunc = (PtrType *)*virtualFuncPtr;

    std::cout << "Virtual Function Addr: " << virtualFuncPtr << "\n";
    std::cout << "First Virtual Function Addr: " << firstVirtualFunc << "\n";

    for (int i = 0; i < 3; ++i)
    {
        VFunc func = (VFunc) * (firstVirtualFunc + i);
        func();
    }

    return 0;
}