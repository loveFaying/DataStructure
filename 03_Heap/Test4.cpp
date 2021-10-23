#include <iostream>
#include <algorithm>
#include "Heap.h"
#include "../02_Sorting_Advance/SortedTestHelper.h"

using namespace std;

int main(){

    int n = 10000000;

    // 测试1 一般性测试
    cout<<"Test for random array, size = "<<n<<", random range [0, "<<n<<"]"<<endl;
    int* arr1 = SortedTestHelper::generateRandomArray(n,0,n);
    int* arr2 = SortedTestHelper::copyArray(arr1, n);

    SortedTestHelper::testSort("Heap Sort 1", heapSort1, arr1, n);
    SortedTestHelper::testSort("Heap Sort 2", heapSort2, arr2, n);

    delete[] arr1;
    delete[] arr2;

    cout<<endl;


    // 测试2 测试近乎有序的数组
    int swapTimes = 100;
    n = 5000000;
    assert( swapTimes >= 0 );

    cout<<"Test for nearly ordered array, size = "<<n<<", swap time = "<<swapTimes<<endl;
    arr1 = SortedTestHelper::generateNearlyOrderedArray(n, swapTimes);
    arr2 = SortedTestHelper::copyArray(arr1, n);

    SortedTestHelper::testSort("Heap Sort 1", heapSort1, arr1, n);
    SortedTestHelper::testSort("Heap Sort 2", heapSort2, arr2, n);

    delete[] arr1;
    delete[] arr2;

    cout << endl;

    // 测试3 测试存在包含大量相同元素的数组
    cout<<"Test for random array, size = "<<n<<", random range [0,10]"<<endl;
    arr1 = SortedTestHelper::generateRandomArray(n, 0, 10);
    arr2 = SortedTestHelper::copyArray(arr1, n);

    SortedTestHelper::testSort("Heap Sort 1", heapSort1, arr1, n);
    SortedTestHelper::testSort("Heap Sort 2", heapSort2, arr2, n);

    delete[] arr1;
    delete[] arr2;

    return 0;
}