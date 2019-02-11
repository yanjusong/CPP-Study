#include <iostream>

class Base1
{
  public:
    virtual void f()
    {
        std::cout << "in Base1::f()\n";
    }

  private:
    virtual void g()
    {
        std::cout << "in Base1::g()\n";
    }
};

class Base2
{
  public:
    virtual void f()
    {
        std::cout << "in Base2::f()\n";
    }

  private:
    virtual void g()
    {
        std::cout << "in Base2::g()\n";
    }
};

class Derived : public Base1, public Base2
{
  public:
    virtual void f_new()
    {
        std::cout << "in Derived::f_new()\n";
    }
};

class DerivedCover : public Base1, public Base2
{
  public:
    virtual void f()
    {
        std::cout << "in DerivedCover::f()\n";
    }
};

typedef void (*VFunc)();

#if __SIZEOF_POINTER__ == 4
typedef int PtrType;
#elif __SIZEOF_POINTER__ == 8
typedef long long PtrType;
#endif

void callVirtualFuncNoCover()
{
    Derived d;
    PtrType *virtualFuncPtr = (PtrType *)(&d);
    PtrType *firstVirtualFunc = (PtrType *)*virtualFuncPtr;

    std::cout << "\n------------------------------------\n";
    std::cout << "First Virtual Function Addr: " << virtualFuncPtr << "\n";
    std::cout << "First Virtual Function Addr: " << firstVirtualFunc << "\n";

    for (int i = 0; i < 3; ++i)
    {
        VFunc func = (VFunc) * (firstVirtualFunc + i);
        func();
    }

    virtualFuncPtr = (PtrType *)(&d) + 1;
    firstVirtualFunc = (PtrType *)*virtualFuncPtr;

    std::cout << "\n------------------------------------\n";
    std::cout << "Second Virtual Function Addr: " << virtualFuncPtr << "\n";
    std::cout << "Second Virtual Function Addr: " << firstVirtualFunc << "\n";

    for (int i = 0; i < 2; ++i)
    {
        VFunc func = (VFunc) * (firstVirtualFunc + i);
        func();
    }
}

void callVirtualFuncCover()
{
    DerivedCover d;
    PtrType *virtualFuncPtr = (PtrType *)(&d);
    PtrType *firstVirtualFunc = (PtrType *)*virtualFuncPtr;

    std::cout << "\n------------------------------------\n";
    std::cout << "First Virtual Function Addr: " << virtualFuncPtr << "\n";
    std::cout << "First Virtual Function Addr: " << firstVirtualFunc << "\n";

    for (int i = 0; i < 2; ++i)
    {
        VFunc func = (VFunc) * (firstVirtualFunc + i);
        func();
    }

    virtualFuncPtr = (PtrType *)(&d) + 1;
    firstVirtualFunc = (PtrType *)*virtualFuncPtr;

    std::cout << "\n------------------------------------\n";
    std::cout << "Second Virtual Function Addr: " << virtualFuncPtr << "\n";
    std::cout << "Second Virtual Function Addr: " << firstVirtualFunc << "\n";

    for (int i = 0; i < 2; ++i)
    {
        VFunc func = (VFunc) * (firstVirtualFunc + i);
        func();
    }
}

int main()
{
    callVirtualFuncNoCover();
    callVirtualFuncCover();

    return 0;
}
