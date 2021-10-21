### 文件介绍
- Test1.cpp  测试 SortedAlgorithm::selectionSort  SortedTestHelper::printArray  SortedTestHelper::generateRandomArray
- Test2.cpp  测试 SortedTestHelper::isSorted SortedTestHelper::testSort
- Test3.cpp  测试 SortedAlgorithm::insertionSort_1 SortedAlgorithm::insertionSort_2
/*
    Test for random array, size = 20000, random range [0, 20000]
    Selection Sort : 0.477s
    Insertion Sort 1 : 0.914s
    Insertion Sort 2 : 0.297s
*/
 

### 下面代码存在的问题
### 问题1
- 'sizeof' on array function parameter 'arr' will return size of 'int*' [-Wsizeof-array-argument]
```C++
template<typename T>     
int getArrayLength(T arr[]){         
    int length = sizeof(arr)/sizeof(T);         
    return length;     
}
```
- 数组作为参数传给函数时，是传给数组的地址，而不是传给整个的数组空间，因而sizeof(arr)这句话会报错
- 正确的用法是：不在函数内部使用sizeof

#### 问题2
- 插入排序的问题(内循环)
```C++
T temp = arr[i];
int j; // j保存元素temp应该插入的位置
for(j = i ; j > 0 ; j --){ // 注意数组越界
    if(arr[j-1] > temp)
        arr[j] = arr[j-1];
}
arr[j] = temp;
```
- 注意需要加入循环终止的条件break, 因为只有在 j>0 和 arr[j-1] > temp 才会 j-- (自己写碰见的一个小问题)
- arr[j-1] > temp 不是 arr[j] > temp
```C++
T temp = arr[i];
int j; // j保存元素temp应该插入的位置
for(j = i ; j > 0 ; j --){ // 注意数组越界
    if(arr[j-1] > temp)
        arr[j] = arr[j-1];
    else    
        break;
}
arr[j] = temp;
```