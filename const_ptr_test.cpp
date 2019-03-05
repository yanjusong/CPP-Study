#include <iostream>
using namespace std;

int main()
{
    int value = 99;
    int value_ = 100;

    const int *p1 = &value;
    int* const p2 = &value;

    cout << "*p1=" << *p1 << endl;
    cout << "*p2=" << *p2 << endl;

    // *p1 = 100;   /* 错误：不能修改p1指向对象的值 */
    p1 = &value_;   /* 正确：可以修改p1指向的对象 */

    *p2 = 100;       /* 正确：可以修改p2指向的对象的值 */
    // p2 = &value_; /* 错误：不能修改p2指向的对象 */

    return 0;
}