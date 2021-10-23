#include <iostream>
#include <algorithm>
#include "Heap.h"
#include "../02_Sorting_Advance/SortedTestHelper.h"

using namespace std;

// 原始的shiftDown过程
template<typename T>
void __shiftDown(T arr[], int n, int k){

    while( 2*k+1 < n ){    // 索引从0开始
        int j = 2*k+1;
        if( j+1 < n && arr[j+1] > arr[j] )
            j += 1;

        if( arr[k] >= arr[j] )break;

        swap( arr[k] , arr[j] );
        k = j;
    }
}

// 优化的shiftDown过程, 使用赋值的方式取代不断的swap,
// 该优化思想和之前对插入排序进行优化的思路是一致的
template<typename T>
void __shiftDown2(T arr[], int n, int k){

    T e = arr[k];
    while( 2*k+1 < n ){
        int j = 2*k+1;
        if( j+1 < n && arr[j+1] > arr[j] )
            j += 1;

        if( e >= arr[j] ) break;

        arr[k] = arr[j];
        k = j;
    }

    arr[k] = e;
}


// 不使用一个额外的最大堆, 直接在原数组上进行原地的堆排序
template<typename T>
void heapSort(T arr[], int n){

    // 注意，此时我们的堆是从0开始索引的
    // 从(最后一个元素的索引-1)/2开始
    // 最后一个元素的索引 = n-1
    for( int i = (n-1-1)/2 ; i >= 0 ; i -- )
        __shiftDown2(arr, n, i);

    for( int i = n-1; i > 0 ; i-- ){
        swap( arr[0] , arr[i] );
        __shiftDown2(arr, i, 0);
    }
}

int main() {

    int n = 1000000;

    // 测试1 一般性测试
    cout<<"Test for random array, size = "<<n<<", random range [0, "<<n<<"]"<<endl;
    int* arr1 = SortedTestHelper::generateRandomArray(n,0,n);
    int* arr2 = SortedTestHelper::copyArray(arr1, n);
    int* arr3 = SortedTestHelper::copyArray(arr1, n);


    SortedTestHelper::testSort("Heap Sort", heapSort, arr1, n);
    SortedTestHelper::testSort("Heap Sort 1", heapSort1, arr2, n);
    SortedTestHelper::testSort("Heap Sort 2", heapSort2, arr3, n);

    delete[] arr1;
    delete[] arr2;
    delete[] arr3;

    cout<<endl;


    // 测试2 测试近乎有序的数组
    int swapTimes = 100;
    cout<<"Test for nearly ordered array, size = "<<n<<", swap time = "<<swapTimes<<endl;
    arr1 = SortedTestHelper::generateNearlyOrderedArray(n,swapTimes);
    arr2 = SortedTestHelper::copyArray(arr1, n);
    arr3 = SortedTestHelper::copyArray(arr1, n);

    SortedTestHelper::testSort("Heap Sort", heapSort, arr1, n);
    SortedTestHelper::testSort("Heap Sort 1", heapSort1, arr2, n);
    SortedTestHelper::testSort("Heap Sort 2", heapSort2, arr3, n);

    delete[] arr1;
    delete[] arr2;
    delete[] arr3;

    cout<<endl;


    // 测试3 测试存在包含大量相同元素的数组
    cout<<"Test for random array, size = "<<n<<", random range [0,10]"<<endl;
    arr1 = SortedTestHelper::generateRandomArray(n,0,10);
    arr2 = SortedTestHelper::copyArray(arr1, n);
    arr3 = SortedTestHelper::copyArray(arr1, n);

    SortedTestHelper::testSort("Heap Sort", heapSort, arr1, n);
    SortedTestHelper::testSort("Heap Sort 1", heapSort1, arr2, n);
    SortedTestHelper::testSort("Heap Sort 2", heapSort2, arr3, n);

    delete[] arr1;
    delete[] arr2;
    delete[] arr3;



    return 0;
}