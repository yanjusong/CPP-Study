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

class Child : public Parent
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

int main()
{
    Child c;
    PtrType *virtualFuncPtr = (PtrType *)(&c);
    PtrType *firstVirtualFunc = (PtrType *)*virtualFuncPtr;

    std::cout << "Virtual Function Addr: " << virtualFuncPtr << "\n";
    std::cout << "First Virtual Function Addr: " << firstVirtualFunc << "\n";

    for (int i = 0; i < 3; ++i)
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

    memberPtr = virtualFuncPtr + 4;
    std::cout << "\tChild::iChild-> " << *memberPtr << "\n";

    memberPtr = virtualFuncPtr + 5;
    std::cout << "\tChild::cChild-> " << *((char *)memberPtr) << "\n";

    memberPtr = virtualFuncPtr + 6;
    std::cout << "\tChild::iCommon-> " << *memberPtr << "\n";

    // 以下没有二意性
    std::cout << c.iCommon << "\n";
    Parent *p = &c;
    std::cout << p->iCommon << "\n";

    return 0;
}