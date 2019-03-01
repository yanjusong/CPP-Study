#include <iostream>
#include <memory>
#include <vector>
#include <string>

using namespace std;

/*
 * @brief：
 *      这个示例说明了原始指针(raw pointer)用来初始化shared_ptr只能一次
 *      类内部的this也是raw pointer，使用this初始化shared_ptr也很容易回暖出现问题，
 *      因此引入了enable_shared_from_this就是解决这个问题。
 */
void duplicate_free_case()
{
    int *p = new int(100);

    shared_ptr<int> ptr1(p);
    cout << "ptr1 value:" << *ptr1 << ", use count:" << ptr1.use_count() << endl;
    shared_ptr<int> ptr2(p);
    cout << "ptr2 value:" << *ptr2 << ", use count:" << ptr2.use_count() << endl;

    // ptr1和ptr2有各自的控制块，ptr1析构是释放p指向的内存，ptr2析构时重复释放
}

#define ERROR_CASE 0

#if ERROR_CASE
class Student
{
  public:
    Student(const string &name) : name_(name) {}
    void addToGroup(vector<shared_ptr<Student> > &group)
    {
        group.push_back(shared_ptr<Student>(this)); // ERROR
    }

  private:
    string name_;
};
#else
class Student : public std::enable_shared_from_this<Student>
{
  public:
    Student(const string &name) : name_(name) 
    {
        // 注意：不能在构造函数中使用shared_from_this
        //      正如不能在构造函数中进行类似于regedit(this)的活动
    }
    void addToGroup(vector<shared_ptr<Student> > &group)
    {
        group.push_back(shared_from_this());
    }

  private:
    string name_;
};

#endif

void test_addToGroup()
{
    vector<shared_ptr<Student> > group;

    auto goodStudent = make_shared<Student>("good");
    goodStudent->addToGroup(group);

    auto badStudent = make_shared<Student>("bad");
    badStudent->addToGroup(group);

    cout << "good student pointer use count:" << goodStudent.use_count() << endl;
    cout << "bad student pointer use count:" << badStudent.use_count() << endl;
    cout << "group member size:" << group.size() << endl;
}

int main()
{
    test_addToGroup();
    return 0;
}