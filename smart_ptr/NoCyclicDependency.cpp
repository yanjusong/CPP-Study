#include <iostream>
#include <memory>
#include <vector>
using namespace std;

class ClassB;

class ClassA
{
  public:
    ClassA() { cout << "ClassA Constructor..." << endl; }
    ~ClassA() { cout << "ClassA Destructor..." << endl; }
    weak_ptr<ClassB> pb; // 在A中引用B
};

class ClassB
{
  public:
    ClassB() { cout << "ClassB Constructor..." << endl; }
    ~ClassB() { cout << "ClassB Destructor..." << endl; }
    weak_ptr<ClassA> pa; // 在B中引用A
};

int main()
{
    // in this situation will cause Cyclic Dependency.
    shared_ptr<ClassA> spa(new ClassA);
    shared_ptr<ClassB> spb = make_shared<ClassB>();
    spa->pb = spb;
    spb->pa = spa;

    return 0;
}