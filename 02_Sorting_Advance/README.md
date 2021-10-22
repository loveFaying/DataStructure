### 文件介绍
#### Test1.cpp  
- 测试 SortedAlgorithm::mergeSort1  需要额外开辟数组空间的 递归归并排序
#### Test1.cpp
- 测试 SortedAlgorithm::mergeSort2   需要额外开辟数组空间的 递归归并排序
- 优化mergeSort1:  arr[mid] <= arr[mid+1] 则不进行merge    小规模数组使用插入排序
```
Test for random array, size = 5000000, random range [0, 5000000]
Merge Sort 1 : 1.922s
Merge Sort 2 : 1.451s

Test for nearly ordered array, size = 5000000, swap time = 10
Merge Sort 1 : 1.258s
Merge Sort 2 : 0.026s
```
### Test2.cpp
- 自底向上实现非递归归并排序 + 优化(同上)
- 测试 SortedAlgorithm::mergeSortBU1  SortedAlgorithm::mergeSortBU2
```
Test for random array, size = 50000000, random range [0, 50000000]
Merge Sort 1 : 20.583s
Merge Sort 2 : 16.409s
Merge Sort BU 1 : 20.849s
Merge Sort BU 2 : 15.755s

Test for nearly ordered array, size = 50000000, swap time = 10
Merge Sort 1 : 14.151s
Merge Sort 2 : 0.253s
Merge Sort BU 1 : 14.077s
Merge Sort BU 2 : 0.278s
```
#### Test3.cpp
- 测试 SortedAlgorithm::quickSort1 SortedAlgorithm::quickSort2 
```
Test for random array, size = 10000000, random range [0, 10000000]
Merge Sort 2 : 2.827s
Merge Sort BU 2 : 2.726s
Quick Sort 1 : 6.759s
Quick Sort 2 : 6.979s

Test for nearly ordered array, size = 50000, swap time = 100
Merge Sort 2 : 0.003s
Merge Sort BU 2 : 0.005s
Quick Sort 1 : 0.529s
Quick Sort 2 : 0.007s

Test for random array, size = 50000, random range [0,10]
Merge Sort 2 : 0.012s
Merge Sort BU 2 : 0.008s
Quick Sort 1 : 0.342s
Quick Sort 2 : 0.333s
```
#### Test4.cpp
- 两路快排 为什么不能加等号，加了等号存在划分不平衡的问题，实验如下：
```
int arr[] = {1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0};
int length = sizeof(arr)/sizeof(int);
int* arr2 = SortedTestHelper::copyArray(arr,length);


cout << _partition1(arr, 0, length-1) << endl; // 16   加等号
SortedTestHelper::printArray(arr, length);

cout << _partition2(arr2, 0, length-1) << endl; // 8   不加等号
SortedTestHelper::printArray(arr2, length);

delete[] arr2;
/*
16
0 1 1 1 1 1 1 1 1 0 0 0 0 0 0 0 1
8
0 0 0 0 0 0 0 0 1 1 1 1 1 1 1 1 1
*/
```
代码分析：
(1)加等号   直接进入while()  i++ 一直到 i=17,  j = 16 没有变化 , 最后swap()一次，最后一个数值变成1
(2)不加等号  i和j都不会进入while(), 一直进行 swap(arr[i],arr[j]); i++; j--;

- 对于包含有大量重复数据的数组, 三路快排有巨大的优势
- 对于一般性的随机数组和近乎有序的数组, 三路快排的效率虽然不是最优的, 但是是在非常可以接受的范围里
```
Test for random array, size = 10000000, random range [0, 10000000]
Merge Sort 2 : 2.816s
Quick Sort 2 : 6.713s
Quick Sort 3 : 1.819s
Quick Sort 3 Ways : 2.292s

Test for nearly ordered array, size = 50000, swap time = 100
Merge Sort 2 : 0.003s
Quick Sort 2 : 0.007s
Quick Sort 3 : 0.003s
Quick Sort 3 Ways : 0.009s

Test for random array, size = 50000, random range [0,10]
Merge Sort 2 : 0.007s
Quick Sort 2 : 0.323s
Quick Sort 3 : 0.004s
Quick Sort 3 Ways : 0.002s
```