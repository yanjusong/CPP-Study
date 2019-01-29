#include <iostream>
#include <cstring>

namespace TEST1
{
struct B
{
    B()
    {
        std::cout << "In class B constructor\n";
    }
};
struct A
{
    operator B()
    {
        return B();
    }
};

void f(B b)
{
    std::cout << "In f(B)\n";
}
} // namespace TEST1

void test1()
{
    /* Conversion during argument passing */
    TEST1::f(TEST1::A());
    std::cout << "\n";
}
// +=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=

namespace TEST2
{
struct B
{
    B()
    {
        std::cout << "In class B constructor\n";
    }
};
struct A
{
    operator B &()
    {
        static B b;
        return b;
    }
};

} // namespace TEST2

void test2()
{
    /* Conversion to reference */
    TEST2::B &b = TEST2::A();
    std::cout << "\n";
}
// +=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=

namespace TEST3
{
typedef void (*fPtr)(int);

void foo(int a)
{
    std::cout << "In foo() a=" << a << "\n";
}
struct test
{
    operator fPtr() { return foo; }
};
} // namespace TEST3

void test3()
{
    /* Conversion to function pointers */
    TEST3::test t;
    t(10);
    std::cout << "\n";
}
// +=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=

namespace TEST4
{
struct test
{
    operator bool() { return true; }
};
}; // namespace TEST4

void test4()
{
    TEST4::test t;
    /* Conversion to non class types */
    if (t)
    {
        std::cout << "t is true\n";
    }
    else
    {
        std::cout << "t is false\n";
    }
    std::cout << "\n";
}
// +=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=

namespace TEST5
{
struct test
{
    template <typename T>
    operator T *()
    {
        std::cout << "in operator T *()\n";
        return 0;
    }
};
}; // namespace TEST5

void test5()
{
    /* Conversion function template */
    void *pv = TEST5::test();
    bool *pb = TEST5::test();
    std::cout << "\n";
}
// +=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=

int main()
{
    test1();
    test2();
    test3();
    test4();
    test5();

    return 0;
}