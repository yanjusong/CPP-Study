#include <iostream>
#include <climits>
using namespace std;

int main()
{
    cout << "maximum int:" << INT_MAX << endl;
    cout << "minimum int:" << INT_MIN << endl;

    int maxNum = 0x7fffffff;
    int minNum = -maxNum - 1;
    cout << "maxNum=" << maxNum << endl;
    cout << "minNum=" << minNum << endl;

    unsigned int uMaxNum = 0xffffffff;
    unsigned int uMinNum = 0;
    cout << "uMaxNum=" << uMaxNum << endl;
    cout << "uMinNum=" << uMinNum << endl;

    // 错误：无限循环了
    for (unsigned char i = 10; i >= 0; --i) 
    {
        cout << (int)i << " ";
    }

    return 0;
}