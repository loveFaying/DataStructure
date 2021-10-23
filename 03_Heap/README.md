### 文件介绍
#### Test1.cpp
- 实现堆的初始模板 class MaxHeap
- 堆的特点
- 堆中的某个节点的值总是不大于其父节点的值（堆总是一个完全二叉树）
- 若把堆从1开始编号，则  节点n的左孩子为2n 右孩子为2n+1

#### Test2.cpp
- 实现shift up, 使得class MaxHeap 可以插入元素
```
20
93 88 87 54 85 70 85 51 53 51 71 22 56 58 71 3 20 37 26 50
```

#### Test3.cpp
- 实现shift down
- 从堆中取出元素（只能取出根节点所在的元素），使得原来的堆依然满足堆的性质
- 先把最后一个元素放入根节点中
- 进行shift down ， 使其保持堆的性质

### Test4.cpp   Heap.h  MaxHeap(Item arr[], int n)
- Heapify  给定一个数组，将给定的数组构建成一个堆  (data时从1索引开始的)
- 按照层序遍历排号完全二叉树之后，所有的叶子节点就是最大堆的初始值
- 所以从第一个不是叶子的节点(n/2)开始 从下往上 从右向左 依次进行shift down
```
Test for random array, size = 10000000, random range [0, 10000000]
Heap Sort 1 : 7.176s
Heap Sort 2 : 7.058s

Test for nearly ordered array, size = 5000000, swap time = 100
Heap Sort 1 : 2.708s
Heap Sort 2 : 1.731s

Test for random array, size = 5000000, random range [0,10]
Heap Sort 1 : 1.681s
Heap Sort 2 : 1.676s
```
```
Test for random array, size = 1000000, random range [0, 1000000]
Merge Sort : 0.209 s
Quick Sort : 0.259 s
Quick Sort 2 Ways : 0.166 s
Quick Sort 3 Ways : 0.281 s
Heap Sort 1 : 0.535 s
Heap Sort 2 : 0.469 s

Test for nearly ordered array, size = 1000000, swap time = 100
Merge Sort : 0.006 s
Quick Sort : 0.204 s
Quick Sort 2 Ways : 0.152 s
Quick Sort 3 Ways : 0.452 s
Heap Sort 1 : 0.483 s
Heap Sort 2 : 0.321 s

Test for random array, size = 1000000, random range [0,10]
Merge Sort : 0.136 s
Quick Sort 2 Ways : 0.109 s
Quick Sort 3 Ways : 0.043 s
Heap Sort 1 : 0.306 s
Heap Sort 2 : 0.289 s
```
### Test5.cpp 原地堆排序
- 索引改成从0开始    
- 注意：将索引改成从0开始时，最后一个非叶子节点的索引计算不是(count-1)/2
- 而是 (最后一个元素索引值-1)/2 , 最后一个元素的索引值为count-1, 所以最后一个非叶子节点的索引值时(count-1-1)/2 
- 如果使用(count-1)/2 , 找到的是一个叶子节点，堆排序算法仍然是正确的，只不过是多算了一步而已
```
Test for random array, size = 1000000, random range [0, 1000000]
Heap Sort : 0.329s
Heap Sort 1 : 0.486s
Heap Sort 2 : 0.471s

Test for nearly ordered array, size = 1000000, swap time = 100
Heap Sort : 0.179s
Heap Sort 1 : 0.469s
Heap Sort 2 : 0.309s

Test for random array, size = 1000000, random range [0,10]
Heap Sort : 0.174s
Heap Sort 1 : 0.332s
Heap Sort 2 : 0.298s
```
```
Test for random array, size = 1000000, random range [0, 1000000]
Merge Sort : 0.195 s
Quick Sort : 0.272 s
Quick Sort 2 Ways : 0.173 s
Quick Sort 3 Ways : 0.243 s
Heap Sort 1 : 0.504 s
Heap Sort 2 : 0.486 s
Heap Sort 3 : 0.332 s

Test for nearly ordered array, size = 1000000, swap time = 100
Merge Sort : 0.006 s
Quick Sort : 0.189 s
Quick Sort 2 Ways : 0.143 s
Quick Sort 3 Ways : 0.413 s
Heap Sort 1 : 0.467 s
Heap Sort 2 : 0.313 s
Heap Sort 3 : 0.173 s

Test for random array, size = 1000000, random range [0,10]
Merge Sort : 0.13 s
Quick Sort 2 Ways : 0.113 s
Quick Sort 3 Ways : 0.041 s
Heap Sort 1 : 0.307 s
Heap Sort 2 : 0.303 s
Heap Sort 3 : 0.178 s
```