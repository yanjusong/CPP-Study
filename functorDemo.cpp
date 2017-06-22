#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

/*
 * 仿函数：
 * 仿函数不是真正的函数，是通过在类中重载()操作符，
 * 实例化类的对象之后调用重载的()而实现，在表示上和调用函数极为类似
 */

class getInteger {
public:
    getInteger() 
    {
        srand((int)(time(NULL)));
    }

    int operator()(int domain)
    {
        return rand() % domain;
    }
};

int main(int argc, char const *argv[])
{
    getInteger randomNumber;

    for(int i = 0; i < 10; ++i) {
        cout << randomNumber(100) << endl;
    }

    return 0;
}