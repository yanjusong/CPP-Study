#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct less_self
{
    bool operator()(const int& a, const int& b) const 
    {
        return a < b;
    }
};

static bool com_self(const int &a, const int &b)
{
    return a < b;
}

void printVec(const vector<int> &vec)
{
    for (auto x : vec) {
        cout << x << " ";
    }
    cout << endl;
}

void test_heap_api()
{
    vector<int> vi{6, 1, 2, 5, 3, 4};
    printVec(vi);

    // 默认是大顶堆
    make_heap(vi.begin(), vi.end());
    cout << "after called default make_heap:" << endl;
    printVec(vi);

    // 传入比较方法，创建小顶堆
    make_heap(vi.begin(), vi.end(), greater<int>());
    cout << "after called make_heap pass greater<int>():" << endl;
    printVec(vi);

    // 传入自定义比较方法，创建大顶堆
    cout << "after called make_heap pass costom comparable func:" << endl;
    // make_heap(vi.begin(), vi.end(), com);
    make_heap(vi.begin(), vi.end(), less_self());
    printVec(vi);

    // 在现有的堆中加入元素
    vi.push_back(200);
    // push_heap的成功要保证除了最后一个元素，is_heap为真
    push_heap(vi.begin(), vi.end());
    cout << "after called push_heap:" << endl;
    printVec(vi);

    // 删除堆顶元素，pop_heap的调用要保证已经是堆
    // 调用之后把堆顶元素移动到最后，除了最后一个元素这个序列也是堆
    pop_heap(vi.begin(), vi.end());
    cout << "after called pop_heap:" << endl;
    printVec(vi);

    // 测试是否为堆
    cout << "is heap now? " << is_heap(vi.begin(), vi.end()) << endl;
    cout << "is heap until? " << *is_heap_until(vi.begin(), vi.end()) << endl;

    vi.pop_back();
    cout << "after pop last one:" << endl;
    printVec(vi);
    cout << "is heap now? " << is_heap(vi.begin(), vi.end()) << endl;

    // 堆排序，sort_heap也必须是在一个堆上调用
    sort_heap(vi.begin(), vi.end());
    cout << "after sort_heap:" << endl;
    printVec(vi);

    cout << endl;
}

struct Student
{
  public:
    Student(int score) : score_(score) {}
    bool operator<(const Student &rhs) const
    {
        return score_ > rhs.score_;
    }

    static void printStudents(const vector<Student> &students)
    {
        for (auto x : students) {
            cout << x.score_ << " ";
        }
        cout << endl;
    }
  private:
    int score_;
};

void test_self_struct_for_heap()
{
    cout << "origin student scores: " << endl;
    vector<Student> vi{Student(80), Student(100), Student(90), Student(95), Student(85)};
    Student::printStudents(vi);

    // 这里会调用Student的operator<方法作为比较函数
    make_heap(vi.begin(), vi.end());
    cout << "after make_heap:" << endl;
    Student::printStudents(vi);
}

int main()
{
    test_heap_api();
    test_self_struct_for_heap();

    return 0;
}