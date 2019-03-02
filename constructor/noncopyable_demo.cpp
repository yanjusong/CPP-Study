#include <iostream>
#include <string>
using namespace std;

class noncopyable
{
  public:
    noncopyable() = default;
    ~noncopyable() = default;

  protected:
    noncopyable(const noncopyable &) {}
    noncopyable &operator==(const noncopyable &) { return *this; }
};

class Student : noncopyable
{
  public:
    Student(const string &name) : name_(name)
    {
    }

    void printName()
    {
        cout << "my name is " << name_ << endl;
    }

  private:
    string name_;
};

int main()
{
    Student s1("Tom");
    s1.printName();

    // error, copy constructor is private.
    // Student s2(s1);
    // s2.printName();

    return 0;
}