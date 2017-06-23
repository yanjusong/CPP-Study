#include <iostream>
#include <queue>
#include <string>
using namespace std;

class A
{
private:
    string m_name;
    unsigned int m_age;
public:
    A(string name, unsigned int age):m_name(name), m_age(age) {}
    bool operator<(const A &rhs) const
    {
        // 根据年龄由小到大
        return m_age > rhs.m_age;
    }

    friend ostream& operator<<(ostream& os, const A &rhs);
};

bool cmpFunc(const A *lhs, const A *rhs)
{
    return *lhs < *rhs;
}
typedef bool (*cmpF)(const A*, const A*);

ostream& operator<<(ostream& os, const A &rhs)
{
    os << "姓名：" << rhs.m_name << "\t" << "年龄：" << rhs.m_age << "\t";  
    return os;
}

struct cmp{
    bool operator() (const A &a, const A &b) const 
    {
        // 年龄由大到小
        return !(a < b);
    }
};

int main(int argc, char const *argv[])
{
    priority_queue<int> heapInt;
    heapInt.push(1);
    heapInt.push(7);
    heapInt.push(4);
    heapInt.push(5);
    heapInt.push(100);
    heapInt.push(34);
    heapInt.push(21);

    while(!heapInt.empty()) {
        cout << heapInt.top() << " ";
        heapInt.pop();
    }
    cout << endl;

    // 对于自定义结构体的priority_queue
    // 1. 比较函数为A的友元函数 operator<
    cout << "比较函数为A的友元函数 operator< :" << endl;
    priority_queue<A, vector<A> > heapA;
    A a1("张三", 30);
    A a2("李四", 40);
    A a3("红孩儿", 8);
    heapA.push(a1);
    heapA.push(a2);
    heapA.push(a3);
    while(!heapA.empty()) {
        cout << heapA.top() << endl;
        heapA.pop();
    }

    // 2. 比较函数为全局函数cmpFunc
    cout << "\n比较函数为全局函数cmpFunc:" << endl;
    priority_queue<A*, vector<A*>, cmpF> heapB(cmpFunc);
    heapB.push(&a1);
    heapB.push(&a2);
    heapB.push(&a3);
    while(!heapB.empty()) {
        cout << *(heapB.top()) << endl;
        heapB.pop();
    }

    // 3. 比较函数为仿函数
    cout << "\n比较函数为仿函数:" << endl;
    priority_queue<A, vector<A>, cmp> heapC;
    heapC.push(a1);
    heapC.push(a2);
    heapC.push(a3);
    while(!heapC.empty()) {
        cout << heapC.top() << endl;
        heapC.pop();
    }

    return 0;
}