#include <iostream>
using namespace std;

void printArray(int p[4])
{
    for (int i = 0; i < 4; ++i) 
    {
        cout << p[i] << " ";
    }

    cout << endl;
}

int main()
{
    cout << "\ncase 1: " << endl;
    {
        int nums[] = {1, 2, 3, 4};
        int len = sizeof(nums) / sizeof(int);
        int *p[len]; /* p是个指针数组，也即p指向数组，数组的每个元素都是int *指针 */

        for (int i = 0; i < len; ++i)
        {
            p[i] = &nums[i];
        }
        for (int i = 0; i < len; ++i)
        {
            cout << *(p[i]) << " ";
        }
        cout << endl;
    }


    cout << "\ncase 2: " << endl;
    {
        int nums[3][4];
        int (*p)[4]; /* p是个数组指针，他指向的元素是个数组，步长为数组的大小 */
        for (int i = 0; i < 3; ++i) 
        {
            for (int j = 0; j < 4; ++j) {
                nums[i][j] = i * 10 + j;
            }
        }

        p = nums;
        for (int i = 0; i < 3; ++i) 
        {
            for (int j = 0; j < 4; ++j)
            {
                cout << p[0][j] << " ";
            }
            cout << endl;
            ++p;
        }

        cout << "sizeof(p)=" << sizeof(p) << endl;
        cout << p << endl;
        cout << ++p << endl; /* p的步长为4个int元素长度，也即16 */
        int *p1 = NULL;
        cout << p1 << endl;
        cout << ++p1 << endl;
        cout << sizeof(int *) << endl; /* 指针为8字节 */
        cout << sizeof(int) << endl;   /* int为4字节 */
    }

    cout << "\ncase 3: " << endl;
    {
        int nums[] = {1, 2, 3, 4};
        printArray(nums);

        int nums1[] = {1, 2, 3, 4, 5};
        printArray(nums1);

        int nums2[] = {100, 200, 300};
        printArray(nums2); // out of bound

        int *nums3 = new int[4];
        for (int i = 0; i < 4; ++i)
            nums3[i] = i;
        printArray(nums3);
        delete [] nums3;
    }

    return 0;
}