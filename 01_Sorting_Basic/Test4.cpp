#include <iostream>
#include "SortedAlgorithm.h"
#include "SortedTestHelper.h"
using namespace std;

int main(){
    // 测试近乎有序的数组
    int n = 20000;

    // 测试1 一般测试
    cout<<"Test for random array, size = "<<n<<", random range [0, "<<n<<"]"<<endl;
    int* arr1 = SortedTestHelper::generateRandomArray(n,0,n);
    int* arr2 = SortedTestHelper::copyArray(arr1, n);
    int* arr3 = SortedTestHelper::copyArray(arr2, n);

    SortedTestHelper::testSort("Selection Sort", SortedAlgorithm::selectionSort, arr1, n);
    SortedTestHelper::testSort("Insertion Sort 1", SortedAlgorithm::insertionSort_1, arr2, n);
    SortedTestHelper::testSort("Insertion Sort 2", SortedAlgorithm::insertionSort_2, arr3, n);

    delete[] arr1;
    delete[] arr2;
    delete[] arr3;

    cout<<endl;

    // 测试2 有序性更强的测试
    cout<<"Test for more ordered random array, size = "<<n<<", random range [0, 3]"<<endl;
    arr1 = SortedTestHelper::generateRandomArray(n,0,3);
    arr2 = SortedTestHelper::copyArray(arr1, n);
    arr3 = SortedTestHelper::copyArray(arr2, n);

    SortedTestHelper::testSort("Selection Sort", SortedAlgorithm::selectionSort, arr1, n);
    SortedTestHelper::testSort("Insertion Sort 1", SortedAlgorithm::insertionSort_1, arr2, n);
    SortedTestHelper::testSort("Insertion Sort 2", SortedAlgorithm::insertionSort_2, arr3, n);

    delete[] arr1;
    delete[] arr2;
    delete[] arr3;

    cout << endl;

    // 测试3 测试近乎有序的数组
    int swapTimes = 100;
    cout<<"Test for nearly ordered array, size = "<<n<<", swap time = "<<swapTimes<<endl;
    arr1 = SortedTestHelper::generateNearlyOrderedArray(n, swapTimes);
    arr2 = SortedTestHelper::copyArray(arr1, n);
    arr3 = SortedTestHelper::copyArray(arr2, n);

    SortedTestHelper::testSort("Selection Sort", SortedAlgorithm::selectionSort, arr1, n);
    SortedTestHelper::testSort("Insertion Sort 1", SortedAlgorithm::insertionSort_1, arr2, n);
    SortedTestHelper::testSort("Insertion Sort 2", SortedAlgorithm::insertionSort_2, arr3, n);

    delete[] arr1;
    delete[] arr2;
    delete[] arr3;

    return 0;
}