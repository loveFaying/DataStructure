### 文件介绍
#### Test1.cpp  UnionFind1.h 
- 第一版UnionFind的实现（使用数组）
```
UF1, 20000 ops, 0.233 s
```
#### Test2.cpp UnionFind2.h
- 第二版UnionFind的实现（使用一个数组构建一棵指向父节点的树）
```
UF2, 20000 ops, 0.071 s
```
#### Test3.cpp UnionFind3.h
- 将元素少的root指向元素大的root
- sz[i]:以i为根的集合中元素的个数
```
UF3, 20000 ops, 0.003 s
```
#### Test4.cpp UnionFind4.h
- 基于树高度的优化
- rank[i] : 根节点为i的树的高度
```
UF4, 20000 ops, 0.001 s
```
#### Test5.cpp UnionFind5.h
- 使用路径压缩的优化
```
UF5, 20000 ops, 0.001 s
```
#### UnionFind6.h
- 路径压缩使用递归的方式
```
UF3 with 5000000 unionElements ops, 5000000 isConnected ops, 0.615 s
UF4 with 5000000 unionElements ops, 5000000 isConnected ops, 0.686 s
UF5 with 5000000 unionElements ops, 5000000 isConnected ops, 0.307 s
UF6 with 5000000 unionElements ops, 5000000 isConnected ops, 0.366 s
```
#### Test6.cpp
- 查看路径压缩递归与非递归的不同
```
UF implements Path Compression by recursion:
0 0 0 2 2

UF implements Path Compression without recursion:
0 0 0 0 0
```