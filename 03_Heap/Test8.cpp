#include <iostream>
#include <algorithm>
#include "MinHeap.h"
#include "../02_Sorting_Advance/SortedTestHelper.h"

using namespace std;

// 将所有的元素依次添加到最小堆中, 再在将所有元素从堆中依次取出来, 完成排序
// 使用这样的一个最小堆排序, 来检验我们的最小堆的正确性
template<typename T>
void heapSortUsingMinHeap(T arr[], int n){

    MinHeap<T> minheap = MinHeap<T>(n);
    for( int i = 0 ; i < n ; i ++ )
        minheap.insert(arr[i]);

    for( int i = 0 ; i < n ; i ++ )
        arr[i] = minheap.extractMin();

}

int main() {

    int n = 1000000;

    int* arr = SortedTestHelper::generateRandomArray(n, 0, n);
    SortedTestHelper::testSort("Heap Sort Using Min-Heap", heapSortUsingMinHeap, arr, n);

    return 0;
}