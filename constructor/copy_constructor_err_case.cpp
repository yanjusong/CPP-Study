#include <iostream>
using namespace std;

class Matrix
{
  public:
    Matrix(int w, int h) : w_(w), h_(h)
    {
        data_ = new int[w_ * h_];
    }

    ~Matrix()
    {
        delete[] data_;
    }

  private:
    int w_;
    int h_;
    int *data_;
};

void test1()
{
    Matrix mtx1(3, 3);
    Matrix mtx2(mtx1);
}

// -------------------------------------------------
class Persion
{
  public:
    Persion()
    {
        cout << "in Persion default constructor." << endl;
    }

    Persion(const Persion &)
    {
        cout << "in Persion copy constructor." << endl;
    }
};

class Student : public Persion
{
  public:
    Student() : Persion()
    {
        cout << "in Student default constructor." << endl;
    }

    // 注意：如果复制构造函数不显式调用父类的复制构造函数
    // 那么会默认调用父类的默认构造函数，这有可能产生错误
    Student(const Student &rhs) : Persion(rhs)
    {
        cout << "in Student copy constructor." << endl;
    }
};

void test2()
{
    Student s1;
    Student s2(s1);
}

// 这两个test实例展示了为何要禁用赋值构造函数，也即会继承noncopyable
// 1. 容易忽略浅拷贝的问题
// 2. 忘记调用父类的复制构造函数

int main()
{
    // this case will cause double free.
    // test1();

    test2();

    return 0;
}