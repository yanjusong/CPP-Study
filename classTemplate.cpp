#include <iostream>
#include <string>
using namespace std;

template<class T>
class A {
private:
    T m_value;
public:
    A(T value):m_value(value) {}

    // 显示私有成员数据
    void showValue()
    {
        cout << this->m_value << endl;
    }
};

int main(int argc, char const *argv[])
{
    A<int> a(1);
    a.showValue();

    A<double> b(1.99);
    b.showValue();

    A<char> c('z');
    c.showValue();

    A<const char *> d("hello world");
    d.showValue();

    return 0;
}

/*
 * 假设类A在头文件中声明，那么A对应的成员函数在cpp文件中的定义样式如下
 * 1.构造函数
 * template<class T>
 * A<T>::A(T value):m_value(value) {}
 *
 * 2.showValue函数
 * template<class T>
 * A<T>::showValue() {
 *     cout << this->m_value << endl;
 * }
 *
 */