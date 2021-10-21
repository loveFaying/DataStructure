### 文件介绍
- Test1.cpp  测试 SortedAlgorithm::selectionSort  SortedTestHelper::printArray  SortedTestHelper::generateRandomArray
- Test2.cpp  测试 SortedTestHelper::isSorted SortedTestHelper::testSort
- Test3.cpp  测试 SortedAlgorithm::insertionSort_1 SortedAlgorithm::insertionSort_2
```
    Test for random array, size = 20000, random range [0, 20000]
    Selection Sort : 0.477s
    Insertion Sort 1 : 0.914s
    Insertion Sort 2 : 0.297s
```
- Test4.cpp 测试 SortedTestHelper::generateNearlyOrderedArray
```
    Test for random array, size = 20000, random range [0, 20000]
    Selection Sort : 0.496s
    Insertion Sort 1 : 0.93s
    Insertion Sort 2 : 0.305s

    Test for more ordered random array, size = 20000, random range [0, 3]
    Selection Sort : 0.49s
    Insertion Sort 1 : 0.753s
    Insertion Sort 2 : 0.226s

    Test for nearly ordered array, size = 20000, swap time = 100
    Selection Sort : 0.52s
    Insertion Sort 1 : 0.011s
    Insertion Sort 2 : 0.004s
```
- Test5.cpp 测试 SortedAlgorithm::selectionSort_1
```
    Test for random array, size = 40000, random range [0, 40000]
    Selection Sort : 1.957s
    Selection Sort 1 : 1.47s
    Insertion Sort 1 : 3.818s
    Insertion Sort 2 : 1.197s

    Test for more ordered random array, size = 40000, random range [0, 3]
    Selection Sort : 2.039s
    Selection Sort 1 : 1.622s
    Insertion Sort 1 : 2.963s
    Insertion Sort 2 : 0.989s

    Test for nearly ordered array, size = 40000, swap time = 100
    Selection Sort : 1.925s
    Selection Sort 1 : 1.642s
    Insertion Sort 1 : 0.029s
    Insertion Sort 2 : 0.011s
```
- Test6.cpp 测试  SortedAlgorithm::bubbleSort_1  SortedAlgorithm::bubbleSort_2
```
Test for random array, size = 40000, random range [0, 40000]
Selection Sort 1 : 1.266s
Insertion Sort 2 : 1.167s
Bubble Sort 1 : 7.755s
Bubble Sort 2 : 7.791s

Test for more ordered random array, size = 40000, random range [0, 3]
Selection Sort 1 : 1.362s
Insertion Sort 2 : 0.911s
Bubble Sort 1 : 6.934s
Bubble Sort 2 : 6.86s

Test for nearly ordered array, size = 40000, swap time = 100
Selection Sort 1 : 1.247s
Insertion Sort 2 : 0.007s
Bubble Sort 1 : 2.076s
Bubble Sort 2 : 1.433s

Test for ordered array, size = 10000000
Insertion Sort 2 : 0.041s
Bubble Sort 1 : 0.031s
Bubble Sort 2 : 0.03s
```
- Test7.cpp 测试 SortedAlgorithm::shellSort
```
Test for random array, size = 40000, random range [0, 40000]
Selection Sort 1 : 1.242s
Insertion Sort 2 : 1.208s
Bubble Sort 2 : 7.63s
Shell Sort : 0.009s

Test for more ordered random array, size = 40000, random range [0, 3]
Selection Sort 1 : 1.235s
Insertion Sort 2 : 0.905s
Bubble Sort 2 : 6.686s
Shell Sort : 0.004s

Test for nearly ordered array, size = 40000, swap time = 100
Selection Sort 1 : 1.237s
Insertion Sort 2 : 0.008s
Bubble Sort 2 : 1.495s
Shell Sort : 0.004s

Test for ordered array, size = 10000000
Insertion Sort 2 : 0.041s
Bubble Sort 2 : 0.03s
Shell Sort : 0.6s
```

### 下面代码存在的问题
#### 问题1
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