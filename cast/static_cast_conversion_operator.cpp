#include <iostream>
#include <string>
using namespace std;

class Int
{
    int x;

  public:
    Int(int x_in = 0)
        : x{x_in}
    {
        cout << "Conversion Constructor called" << endl;
    }
    operator string()
    {
        cout << "Conversion Operator called" << endl;
        return to_string(x);
    }
};

int main()
{
    Int obj(3); /* called Constructor */
    string str = obj; /* called Conversion */
    obj = 20; /* 20 called Constructor to make as Int obj implicitly */
    string str2 = static_cast<string>(obj); /* called Conversion */
    obj = static_cast<Int>(30);  /* called Constructor */

    return 0;
}
