### 文件介绍
#### Test1.cpp  DenseGraph.h Dijkstra.h  Edge.h  IndexMinHeap.h ReadGraph.h  SparseGraph.h
- Dijkstra
```
5 8
Test Dijkstra:

Shortest Path to 0 : 0
0 -> 0
----------
Shortest Path to 1 : 3
0 -> 2 -> 1
----------
Shortest Path to 2 : 2
0 -> 2
----------
Shortest Path to 3 : 5
0 -> 2 -> 3
----------
Shortest Path to 4 : 4
0 -> 2 -> 1 -> 4
----------
```
#### Test2.cpp  BellmanFord.h
- Bellman Ford
```
5 8
Test Bellman-Ford:

Shortest Path to 1 : 5
0 -> 1
----------
Shortest Path to 2 : 1
0 -> 1 -> 2
----------
Shortest Path to 3 : 3
0 -> 1 -> 2 -> 4 -> 3
----------
Shortest Path to 4 : 6
0 -> 1 -> 2 -> 4
----------
```