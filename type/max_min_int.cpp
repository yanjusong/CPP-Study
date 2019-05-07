#include <iostream>
#include <climits>
using namespace std;

int main()
{
    cout << "INT_MAX:" << INT_MAX << endl;
    cout << "INT_MIN:" << INT_MIN << endl;

    int maxNum = 0x7fffffff;
    int minNum1 = -maxNum - 1;
    int minNim2 = 0x80000000;
    cout << "maxNum=" << maxNum << endl;
    cout << "minNum1=" << minNum1 << endl;
    cout << "minNim2=" << minNim2 << endl;

    unsigned int uMaxNum = 0xffffffff;
    unsigned int uMinNum = 0;
    cout << "uMaxNum=" << uMaxNum << endl;
    cout << "uMinNum=" << uMinNum << endl;

    // unsigned int v = uMinNum - 1;
    // cout << "v=" << v << endl;
    // 错误：无限循环
    // for (unsigned char i = 10; i >= 0; --i) 
    // {
    //     cout << (int)i << " ";
    // }

    return 0;
}