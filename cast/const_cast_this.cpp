#include <iostream>
using namespace std;

class student
{
  private:
    int roll;

  public:
    // constructor
    student(int r) : roll(r) {}

    // A const function that changes roll with the help of const_cast
    void fun() const
    {
        (const_cast<student *>(this))->roll = 5;
    }

    int getRoll() { return roll; }
};

int main(void)
{
    student s(3);
    cout << "Old roll number: " << s.getRoll() << endl;

    s.fun();

    cout << "New roll number: " << s.getRoll() << endl;

    return 0;
}
