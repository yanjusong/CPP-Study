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

class Derived : public Base
{
  public:
    virtual void f_new()
    {
        std::cout << "in Derived::f_new()\n";
    }
    virtual void g_new()
    {
        std::cout << "in Derived::g_new()\n";
    }

  private:
    virtual void h_new()
    {
        std::cout << "in Derived::h_new()\n";
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
    Derived d;
    PtrType *virtualFuncPtr = (PtrType *)(&d);
    PtrType *firstVirtualFunc = (PtrType *)*virtualFuncPtr;

    std::cout << "Virtual Function Addr: " << virtualFuncPtr << "\n";
    std::cout << "First Virtual Function Addr: " << firstVirtualFunc << "\n";

    for (int i = 0; i < 6; ++i)
    {
        VFunc func = (VFunc) * (firstVirtualFunc + i);
        func();
    }

    return 0;
}