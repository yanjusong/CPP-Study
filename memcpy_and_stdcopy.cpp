#include <iostream>
#include <vector>
#include <string>
#include <ctime>

#define MAX_VEC_SIZE 80000000

void stdcopy_test(const std::vector<int> &vec)
{
    std::vector<int> dstvec;
    dstvec.resize(vec.size());
    std::copy(vec.begin(), vec.end(), dstvec.begin());
}

void memcpy_test(const std::vector<int> &vec)
{
    std::vector<int> dstvec;
    dstvec.resize(vec.size());
    memcpy(&dstvec[0], &vec[0], vec.size());
}

typedef void (*CopyFunc)(const std::vector<int> &);

void test(CopyFunc func, const std::vector<int> &vec, const std::string &desc)
{
    std::clock_t start, end;

    start = std::clock();
    func(vec);
    end = std::clock();

    std::cout << desc << " ==> cost: " << (double)(end - start) << "ms\n";
}

int main()
{
    std::vector<int> vec;
    vec.resize(MAX_VEC_SIZE);

    for (int i = 0; i < MAX_VEC_SIZE; ++i)
    {
        vec.push_back(i);
    }

    test(stdcopy_test, vec, "std::copy");
    test(memcpy_test, vec, "memcpy");

    return 0;
}