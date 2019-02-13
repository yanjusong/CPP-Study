#include <iostream>
#include <string>

class NoExplicitClass
{
  public:
    NoExplicitClass(const std::string &data) : data_(data)
    {
    }

    int compareTo(const NoExplicitClass &rhs)
    {
        return strcmp(data_.c_str(), rhs.data_.c_str());
    }

  private:
    std::string data_;
};

class ExplicitClass
{
  public:
    explicit ExplicitClass(const std::string &data) : data_(data)
    {
    }

    int compareTo(const ExplicitClass &rhs)
    {
        return strcmp(data_.c_str(), rhs.data_.c_str());
    }

  private:
    std::string data_;
};

int main()
{
    std::string str = "Hello";
    NoExplicitClass nobj("Hello");
    std::cout << nobj.compareTo(str) << "\n";

    ExplicitClass eobj("Hello");

    // error: the implicit copy constructor not viable
    // std::cout << eobj.compareTo(str) << "\n"; 

    return 0;
}