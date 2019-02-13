#include <iostream>

template <typename T>
void process_value(T &i)
{
    std::cout << "LValue processed: " << i << std::endl;
}

template <typename T>
void process_value(T &&i)
{
    std::cout << "RValue processed: " << i << std::endl;
}

template <typename T>
void forward_value(const T &val)
{
    process_value(val);
}

template <typename T>
void forward_value(T &val)
{
    process_value(val);
}

template <typename T> 
void _forward_value(T&& val) 
{
    process_value(val);
}

int main()
{
    int a = 0;
    const int &b = 1;
    forward_value(a); // int&
    forward_value(b); // const int&
    forward_value(2); // int&

    _forward_value(a); // int&
    _forward_value(b); // const int&
    _forward_value(2); // int&

    return 0;
}