#include <iostream>
#include <algorithm>
#include "SortedAlgorithm.h"
#include "SortedTestHelper.h"
// #include "../01_Sorting_Basic/SortedAlgorithm.h"
using namespace std;

int main(){

    int n = 10000000;

    // 测试1 一般性测试
    cout<<"Test for random array, size = "<<n<<", random range [0, "<<n<<"]"<<endl;
    int* arr1 = SortedTestHelper::generateRandomArray(n,0,n);
    int* arr2 = SortedTestHelper::copyArray(arr1, n);
    int* arr3 = SortedTestHelper::copyArray(arr2, n);
    int* arr4 = SortedTestHelper::copyArray(arr3, n);

    SortedTestHelper::testSort("Merge Sort 2", SortedAlgorithm::mergeSort2, arr1, n);
    SortedTestHelper::testSort("Quick Sort 2", SortedAlgorithm::quickSort2, arr3, n);
    SortedTestHelper::testSort("Quick Sort 3", SortedAlgorithm::quickSort3, arr4, n);
    SortedTestHelper::testSort("Quick Sort 3 Ways", SortedAlgorithm::quickSort3Ways, arr2, n);

    delete[] arr1;
    delete[] arr2;
    delete[] arr3;
    delete[] arr4;

    cout<<endl;


    // 测试2 测试近乎有序的数组
    // 未优化的快速排序退化成了O(n^2)
    int swapTimes = 100;
    n = 50000;
    assert( swapTimes >= 0 );

    cout<<"Test for nearly ordered array, size = "<<n<<", swap time = "<<swapTimes<<endl;
    arr1 = SortedTestHelper::generateNearlyOrderedArray(n, swapTimes);
    arr2 = SortedTestHelper::copyArray(arr1, n);
    arr3 = SortedTestHelper::copyArray(arr2, n);
    arr4 = SortedTestHelper::copyArray(arr3, n);

    SortedTestHelper::testSort("Merge Sort 2", SortedAlgorithm::mergeSort2, arr1, n);
    SortedTestHelper::testSort("Quick Sort 2", SortedAlgorithm::quickSort2, arr3, n);
    SortedTestHelper::testSort("Quick Sort 3", SortedAlgorithm::quickSort3, arr4, n);
    SortedTestHelper::testSort("Quick Sort 3 Ways", SortedAlgorithm::quickSort3Ways, arr2, n);

    delete[] arr1;
    delete[] arr2;
    delete[] arr3;
    delete[] arr4;

    cout << endl;

    // 测试3 测试存在包含大量相同元素的数组
    // 对于含有大量相同元素的数组, 快速排序算法再次退化成了O(n^2)级别的算法
    cout<<"Test for random array, size = "<<n<<", random range [0,10]"<<endl;
    arr1 = SortedTestHelper::generateRandomArray(n, 0, 10);
    arr2 = SortedTestHelper::copyArray(arr1, n);
    arr3 = SortedTestHelper::copyArray(arr2, n);
    arr4 = SortedTestHelper::copyArray(arr3, n);

    SortedTestHelper::testSort("Merge Sort 2", SortedAlgorithm::mergeSort2, arr1, n);
    SortedTestHelper::testSort("Quick Sort 2", SortedAlgorithm::quickSort2, arr3, n);
    SortedTestHelper::testSort("Quick Sort 3", SortedAlgorithm::quickSort3, arr4, n);
    SortedTestHelper::testSort("Quick Sort 3 Ways", SortedAlgorithm::quickSort3Ways, arr2, n);

    delete[] arr1;
    delete[] arr2;
    delete[] arr3;
    delete[] arr4;

    return 0;
}

