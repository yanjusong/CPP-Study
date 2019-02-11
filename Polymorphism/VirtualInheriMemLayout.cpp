#include <iostream>

typedef void (*VFunc)();

#if __SIZEOF_POINTER__ == 4
typedef int PtrType;
#elif __SIZEOF_POINTER__ == 8
typedef long long PtrType;
#endif

class Parent
{
  public:
    Parent() : iParent(-99), cParent('A'), iCommon(-999)
    {
    }
    virtual void f()
    {
        std::cout << "Parent::f()\n";
    }

    virtual void parent_f()
    {
        std::cout << "Parent::parent_f()\n";
    }

  public:
    PtrType iParent;
    char cParent;
    PtrType iCommon;
};

class Child : virtual public Parent
{
  public:
    Child() : Parent(), iChild(100), cChild('B'), iCommon(1000)
    {
    }
    virtual void f()
    {
        std::cout << "Child::f()\n";
    }

    virtual void child_f()
    {
        std::cout << "Child::child_f()\n";
    }

  public:
    PtrType iChild;
    char cChild;
    PtrType iCommon;
};

// Child 内存布局
// [0] vptr
//      Child::f()
//      Child::child_f()
// [1] Parent::iParent
// [2] Parent::cParent
// [3] Parent::iCommon
// [4] vptr
//      Child::f()
//      Parent::parent_f()
// [5] Child::iChild
// [6] Child::cChild
// [7] Child::iCommon

int main()
{
    Child c;
    PtrType *virtualFuncPtr = (PtrType *)(&c);
    PtrType *firstVirtualFunc = (PtrType *)*virtualFuncPtr;

    std::cout << "Virtual Function Addr: " << virtualFuncPtr << "\n";
    std::cout << "First Virtual Function Addr: " << firstVirtualFunc << "\n";

    for (int i = 0; i < 2; ++i)
    {
        VFunc func = (VFunc) * (firstVirtualFunc + i);
        func();
    }

    // print members.
    PtrType *memberPtr = virtualFuncPtr + 1;
    std::cout << "member Addr: " << memberPtr << "\n";
    std::cout << "\tParent::iParent-> " << *memberPtr << "\n";

    memberPtr = virtualFuncPtr + 2;
    std::cout << "\tParent::cParent-> " << *((char *)memberPtr) << "\n";

    memberPtr = virtualFuncPtr + 3;
    std::cout << "\tParent::iCommon-> " << *memberPtr << "\n";

    // ---------------------------------------------------------------------------------- //
    virtualFuncPtr = virtualFuncPtr + 4;
    PtrType *secondVirtualFunc = (PtrType *)*virtualFuncPtr;

    std::cout << "Virtual Function Addr: " << virtualFuncPtr << "\n";
    std::cout << "First Virtual Function Addr: " << secondVirtualFunc << "\n";

    for (int i = 0; i < 2; ++i)
    {
        VFunc func = (VFunc) * (secondVirtualFunc + i);
        func();
    }

    memberPtr = virtualFuncPtr + 1;
    std::cout << "\tChild::iChild-> " << *memberPtr << "\n";

    memberPtr = virtualFuncPtr + 2;
    std::cout << "\tChild::cChild-> " << *((char *)memberPtr) << "\n";

    memberPtr = virtualFuncPtr + 3;
    std::cout << "\tChild::iCommon-> " << *memberPtr << "\n";

    // 以下没有二意性
    std::cout << c.iCommon << "\n";
    Parent *p = &c;
    std::cout << p->iCommon << "\n";

    return 0;
}