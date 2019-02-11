#include <iostream>

typedef void (*VFunc)();

#if __SIZEOF_POINTER__ == 4
typedef int PtrType;
#elif __SIZEOF_POINTER__ == 8
typedef long long PtrType;
#endif

class B
{
  public:
    B() : iB(-99), cB('A')
    {
    }
    virtual void f()
    {
        std::cout << "B::f()\n";
    }

    virtual void bf()
    {
        std::cout << "B::bf()\n";
    }

  public:
    PtrType iB;
    char cB;
};

class B1 : virtual public B
{
  public:
    B1() : B(), iB1(100), cB1('B')
    {
    }
    virtual void f()
    {
        std::cout << "B1::f()\n";
    }

    virtual void bf1()
    {
        std::cout << "B1::bf1()\n";
    }

    virtual void bg1()
    {
        std::cout << "B1::bg1()\n";
    }

  public:
    PtrType iB1;
    char cB1;
};

class B2 : virtual public B
{
  public:
    B2() : B(), iB2(1000), cB2('C')
    {
    }
    virtual void f()
    {
        std::cout << "B2::f()\n";
    }

    virtual void bf2()
    {
        std::cout << "B2::bf2()\n";
    }

    virtual void bg2()
    {
        std::cout << "B2::bg2()\n";
    }

  public:
    PtrType iB2;
    char cB2;
};

class D : public B1, public B2
{
  public:
    D() : B1(), B2(), iD(9999), cD('D')
    {
    }

    virtual void f()
    {
        std::cout << "D::f()\n";
    }

    virtual void bf1()
    {
        std::cout << "D::bf1()\n";
    }

    virtual void bf2()
    {
        std::cout << "D::bf2()\n";
    }

    virtual void df()
    {
        std::cout << "D::df()\n";
    }

  private:
    PtrType iD;
    char cD;
};

// D 内存布局
// [0] vptr   /*第一个虚表指针还包含子类重载的、新建的和第一个继承对象所有的虚函数，所以包含D::bf2()*/
//      D::f()
//      D::bf1()
//      B1::bg1()
//      D::bf2()
//      D::df()
// [1] B1::iB1
// [2] B1::cB1
// [3] vptr
//      D::f()
//      D::bf2()
//      B2::bg2()
// [4] B2::iB2
// [5] B2::cB2
// [6] D::iD
// [7] D::cD
// [8] vptr
// [9] D::f()
// [10] B::bf()
// [11] B::iB
// [12] B::cB

int main()
{
    D d;
    PtrType *virtualFuncPtr = (PtrType *)(&d);
    PtrType *firstVirtualFunc = (PtrType *)*virtualFuncPtr;

    std::cout << "Virtual Function Addr: " << virtualFuncPtr << "\n";
    std::cout << "First Virtual Function Addr: " << firstVirtualFunc << "\n";

    for (int i = 0; i < 5; ++i)
    {
        VFunc func = (VFunc) * (firstVirtualFunc + i);
        func();
    }

    PtrType *memberPtr = virtualFuncPtr + 1;
    std::cout << "member Addr: " << memberPtr << "\n";

    memberPtr = virtualFuncPtr + 1;
    std::cout << "\tB1::iB1-> " << *memberPtr << "\n";

    memberPtr = virtualFuncPtr + 2;
    std::cout << "\tB1::cB1-> " << *((char *)memberPtr) << "\n";

    // ---------------------------------------------------------------------------------- //
    virtualFuncPtr = virtualFuncPtr + 3;
    PtrType *secondVirtualFunc = (PtrType *)*virtualFuncPtr;

    std::cout << "Virtual Function Addr: " << virtualFuncPtr << "\n";
    std::cout << "Second Virtual Function Addr: " << secondVirtualFunc << "\n";

    for (int i = 0; i < 3; ++i)
    {
        VFunc func = (VFunc) * (secondVirtualFunc + i);
        func();
    }

    memberPtr = virtualFuncPtr + 1;
    std::cout << "member Addr: " << memberPtr << "\n";
    std::cout << "\tB2::iB2-> " << *memberPtr << "\n";

    memberPtr = virtualFuncPtr + 2;
    std::cout << "\tB2::cB2-> " << *((char *)memberPtr) << "\n";

    memberPtr = virtualFuncPtr + 3;
    std::cout << "\tD::iD-> " << *memberPtr << "\n";

    memberPtr = virtualFuncPtr + 4;
    std::cout << "\tD::cD-> " << *((char *)memberPtr) << "\n";

    // ---------------------------------------------------------------------------------- //
    virtualFuncPtr = virtualFuncPtr + 5;
    PtrType *baseVirtualFunc = (PtrType *)*virtualFuncPtr;

    std::cout << "Virtual Function Addr: " << virtualFuncPtr << "\n";
    std::cout << "Second Virtual Function Addr: " << baseVirtualFunc << "\n";

    for (int i = 0; i < 2; ++i)
    {
        VFunc func = (VFunc) * (baseVirtualFunc + i);
        func();
    }
    memberPtr = virtualFuncPtr + 1;
    std::cout << "\tB::iB-> " << *memberPtr << "\n";

    memberPtr = virtualFuncPtr + 2;
    std::cout << "\tB::cB-> " << *((char *)memberPtr) << "\n";

    return 0;
}