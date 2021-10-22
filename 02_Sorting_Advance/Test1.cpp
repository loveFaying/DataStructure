#include <iostream>
#include <algorithm>
#include "SortedAlgorithm.h"
#include "SortedTestHelper.h"
// #include "../01_Sorting_Basic/SortedAlgorithm.h"
using namespace std;

int main(){

    int n = 5000000;

    // 测试1 一般性测试
    cout<<"Test for random array, size = "<<n<<", random range [0, "<<n<<"]"<<endl;
    int* arr1 = SortedTestHelper::generateRandomArray(n,0,n);
    int* arr2 = SortedTestHelper::copyArray(arr1, n);

    SortedTestHelper::testSort("Merge Sort 1", SortedAlgorithm::mergeSort1, arr1, n);
    SortedTestHelper::testSort("Merge Sort 2", SortedAlgorithm::mergeSort2, arr2, n);

    delete[] arr1;
    delete[] arr2;

    cout<<endl;


    // 测试2 测试近乎有序的数组
    int swapTimes = 10;
    assert( swapTimes >= 0 );

    cout<<"Test for nearly ordered array, size = "<<n<<", swap time = "<<swapTimes<<endl;
    arr1 = SortedTestHelper::generateNearlyOrderedArray(n, swapTimes);
    arr2 = SortedTestHelper::copyArray(arr1, n);

    SortedTestHelper::testSort("Merge Sort 1", SortedAlgorithm::mergeSort1, arr1, n);
    SortedTestHelper::testSort("Merge Sort 2", SortedAlgorithm::mergeSort2, arr2, n);

    delete[] arr1;
    delete[] arr2;

    return 0;
}

