### 文件介绍
####  SparseGraph.h  DenseGraph.h
- 邻接表 SparseGraph.h
- 邻接矩阵 DenseGraph.h
#### class adjIterator    Test1.cpp
- 加入邻边迭代器   class adjIterator
#### ReadGraph.h Test2.cpp
- 从文件中读取图信息
#### Components.h  Test3.cpp
- 求连通分量
#### Path.h  Test4.cpp
- 求一条路径
```
vertex 0:       1       2       5       6
vertex 1:       0
vertex 2:       0
vertex 3:       4       5
vertex 4:       3       5       6
vertex 5:       0       3       4
vertex 6:       0       4

Path from 0 to 6 :
0 -> 5 -> 3 -> 4 -> 6
```
#### ShortestPath.h  Test5.cpp
- 最短路径 和 BFS
```
vertex 0:       1       2       5       6       
vertex 1:       0
vertex 2:       0
vertex 3:       4       5
vertex 4:       3       5       6
vertex 5:       0       3       4
vertex 6:       0       4
DFS : 0 -> 5 -> 3 -> 4 -> 6
BFS : 0 -> 6

vertex 0:       5       1       2       6
vertex 1:       0
vertex 2:       0
vertex 3:       4       5
vertex 4:       3       6       5
vertex 5:       0       4       3
vertex 6:       4       0
vertex 7:       8
vertex 8:       7
vertex 9:       12      10      11
vertex 10:      9
vertex 11:      12      9
vertex 12:      9       11
DFS : 0 -> 5 -> 4 -> 3
BFS : 0 -> 5 -> 3
```
#### RandomGraph.h
- 随机添加边
- Test6.cpp