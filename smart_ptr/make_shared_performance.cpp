#include <iostream>
#include <memory>
#include <string>

using namespace std;

int main()
{

    /**
     * 1. 执行申请`数据体`(string) 的内存申请
     * 2. 执行`控制块`的内存申请
     */
    shared_ptr<string> ptr1(new string("Hello"));

    /**
     * `数据体`和`控制块`的内存一块申请
     */
    shared_ptr<string> ptr2 = make_shared<string>("Hello");

    cout << *ptr1 << endl;
    cout << *ptr2 << endl;

    return 0;
}