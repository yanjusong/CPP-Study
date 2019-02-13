#include <iostream>
#include <vector>

class MyString
{
  private:
    char *data_;
    size_t len_;
    void _init_data(const char *s)
    {
        data_ = new char[len_ + 1];
        memcpy(data_, s, len_);
        data_[len_] = '\0';
    }

  public:
    MyString()
    {
        data_ = NULL;
        len_ = 0;
    }

    MyString(const char *p)
    {
        len_ = strlen(p);
        _init_data(p);
    }

    MyString(const MyString &str)
    {
        len_ = str.len_;
        _init_data(str.data_);
        std::cout << "Copy Constructor is called! source: " << str.data_ << std::endl;
    }

    MyString &operator=(const MyString &str)
    {
        if (this != &str)
        {
            if (data_)
                delete data_;

            len_ = str.len_;
            _init_data(str.data_);
        }
        std::cout << "Copy Assignment is called! source: " << str.data_ << std::endl;
        return *this;
    }

    MyString(MyString &&str)
    {
        std::cout << "Move Constructor is called! source: " << str.data_ << std::endl;
        len_ = str.len_;
        data_ = str.data_;
        str.len_ = 0;
        str.data_ = NULL;
    }

    MyString &operator=(MyString &&str)
    {
        std::cout << "Move Assignment is called! source: " << str.data_ << std::endl;
        if (this != &str)
        {
            len_ = str.len_;
            data_ = str.data_;
            str.len_ = 0;
            str.data_ = NULL;
        }
        return *this;
    }

    virtual ~MyString()
    {
        if (data_)
            free(data_);
    }
};

int main()
{
    MyString a;
    a = MyString("Hello");
    std::vector<MyString> vec;
    vec.push_back(MyString("World"));

    return 0;
}