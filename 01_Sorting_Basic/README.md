### 文件介绍
- Test1.cpp  测试 SortedAlgorithm::selectionSort  SortedTestHelper::printArray  SortedTestHelper::generateRandomArray
- Test2.cpp  测试 SortedTestHelper::isSorted SortedTestHelper::testSort
 

### 下面代码存在的问题
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