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
    Parent() : iParent(-99), cParent('A')
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

  private:
    PtrType iParent;
    char cParent;
};

class Child : public Parent
{
  public:
    Child() : Parent(), iChild(100), cChild('B')
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

  private:
    PtrType iChild;
    char cChild;
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
    std::cout << "\tparent::iParent-> " << *memberPtr << "\n";

    memberPtr = virtualFuncPtr + 2;
    std::cout << "\tparent::cParent-> " << *((char *)memberPtr) << "\n";

    memberPtr = virtualFuncPtr + 3;
    std::cout << "\tchild::iChild-> " << *memberPtr << "\n";

    memberPtr = virtualFuncPtr + 4;
    std::cout << "\tchild::cChild-> " << *((char *)memberPtr) << "\n";

    return 0;
}