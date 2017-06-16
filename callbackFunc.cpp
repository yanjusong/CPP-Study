#include <iostream>
using namespace std;

//callback func 
void calledFunc(char *str)
{
    cout << "回调函数被调用" << endl;
    cout << str << endl;
}

//func that to call callback func by parameter
void callFunc(void (*pFunc)(char *))
{
    char buf[] = "调用参数为址的函数";
    pFunc(buf);
}

typedef void (*PF)(char *);

int main(int argc, char const *argv[])
{
    PF p = calledFunc;
    callFunc(p);

    return 0;
}