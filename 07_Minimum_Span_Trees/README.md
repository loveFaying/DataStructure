### 文件介绍
- Test1.cpp  Edge.h  DenseGraph.h  SparseGraph.h  ReadGraph.h
- 测试有权图和有权图的读取
- 带权图的邻接表以字典的形式存储
- 最小生成树：找V个点，V-1条边，使得总的权重最小
- 切分定理：给定任意切分，横切边中权重最小的边必定属于最小生成树
- 用最小堆找最小权重
```
8 16
NULL    NULL    0.26    NULL    0.38    NULL    0.58    0.16    
NULL    NULL    0.36    0.29    NULL    0.32    NULL    0.19
0.26    0.36    NULL    0.17    NULL    NULL    0.40    0.34
NULL    0.29    0.17    NULL    NULL    NULL    0.52    NULL
0.38    NULL    NULL    NULL    NULL    0.35    0.93    0.37
NULL    0.32    NULL    NULL    0.35    NULL    NULL    0.28
0.58    NULL    0.40    0.52    0.93    NULL    NULL    NULL
0.16    0.19    0.34    NULL    0.37    0.28    NULL    NULL

8 16
vertex 0:       ( to:7,wt:0.16) ( to:4,wt:0.38) ( to:2,wt:0.26) ( to:6,wt:0.58)
vertex 1:       ( to:5,wt:0.32) ( to:7,wt:0.19) ( to:2,wt:0.36) ( to:3,wt:0.29)
vertex 2:       ( to:3,wt:0.17) ( to:0,wt:0.26) ( to:1,wt:0.36) ( to:7,wt:0.34) ( to:6,wt:0.40)
vertex 3:       ( to:2,wt:0.17) ( to:1,wt:0.29) ( to:6,wt:0.52)
vertex 4:       ( to:5,wt:0.35) ( to:7,wt:0.37) ( to:0,wt:0.38) ( to:6,wt:0.93)
vertex 5:       ( to:4,wt:0.35) ( to:7,wt:0.28) ( to:1,wt:0.32)
vertex 6:       ( to:2,wt:0.40) ( to:3,wt:0.52) ( to:0,wt:0.58) ( to:4,wt:0.93)
vertex 7:       ( to:4,wt:0.37) ( to:5,wt:0.28) ( to:0,wt:0.16) ( to:1,wt:0.19) ( to:2,wt:0.34)
```
#### Test2.cpp  LazyPrimMST.h  MinHeap.h
- Lazy Prim
```
8 16
Test Lazy Prim MST:
0-7: 0.16
7-1: 0.19
0-2: 0.26
2-3: 0.17
7-5: 0.28
5-4: 0.35
2-6: 0.4
The MST weight is: 1.81
```
#### IndexMinHeap.h  PrimMST.h Test3.cpp
- 不需要所有的邻边都进入最小堆，我们仅需要与节点相连的最短的横切边
- IndexMinHeap:维护一个与每个节点最短的横切边的数据结构
8 16
Test Lazy Prim MST:
0-7: 0.16
7-1: 0.19
0-2: 0.26
2-3: 0.17
7-5: 0.28
5-4: 0.35
2-6: 0.4
The MST weight is: 1.81

Test Prim MST:
0-7: 0.16
7-1: 0.19
0-2: 0.26
2-3: 0.17
7-5: 0.28
5-4: 0.35
2-6: 0.4
The MST weight is: 1.81

#### Test4.cpp 
- Kruskal算法   每次都找最短
- 堆排序所有的边
- Union Find判断是否构成环
```
8 16
Test Lazy Prim MST:
0-7: 0.16
7-1: 0.19
0-2: 0.26
2-3: 0.17
7-5: 0.28
5-4: 0.35
2-6: 0.4
The MST weight is: 1.81

Test Prim MST:
0-7: 0.16
7-1: 0.19
0-2: 0.26
2-3: 0.17
7-5: 0.28
5-4: 0.35
2-6: 0.4
The MST weight is: 1.81

Test Kruskal MST:
0-7: 0.16
2-3: 0.17
1-7: 0.19
0-2: 0.26
5-7: 0.28
4-5: 0.35
2-6: 0.4
The MST weight is: 1.81
```

#### Test5.cpp
- 性能对比
```
8 16
testG1.txt load successfully.
250 1273
testG2.txt load successfully.
1000 8433
testG3.txt load successfully.
10000 61731
testG4.txt load successfully.

Test Lazy Prim MST:
Test for G1: 0 s.
Test for G2: 0.001 s.
Test for G3: 0.005 s.
Test for G4: 0.05 s.

Test Prim MST:
Test for G1: 0 s.
Test for G2: 0 s.
Test for G3: 0.001 s.
Test for G4: 0.019 s.

Test Kruskal MST:
Test for G1: 0 s.
Test for G2: 0 s.
Test for G3: 0.005 s.
Test for G4: 0.044 s.
```