### 文件介绍
### 文件描述
#### Test1.cpp
- 二分查找法（递归与非递归实现方式）
```
Binary Search (Without Recursion): 0.255 s
Binary Search (Recursion): 0.293 s
```
#### Test2.cpp
- 二分查找法（floor 与 ceil 的实现方式）
```
the floor index of 0 is -1.
the ceil index of 0 is 0.The value is 1.

the floor index of 1 is 0.The value is 1.
the ceil index of 1 is 2.The value is 1.

the floor index of 2 is 3.The value is 2.
the ceil index of 2 is 7.The value is 2.

the floor index of 3 is 7.The value is 2.
the ceil index of 3 is 8.The value is 4.

the floor index of 4 is 8.The value is 4.
the ceil index of 4 is 9.The value is 4.

the floor index of 5 is 10.The value is 5.
the ceil index of 5 is 12.The value is 5.

the floor index of 6 is 13.The value is 6.
the ceil index of 6 is 15.The value is 6.

the floor index of 7 is 15.The value is 6.
the ceil index of 7 is 16.

the floor index of 8 is 15.The value is 6.
the ceil index of 8 is 16.
```
#### Test3.cpp 
- 二分搜索树 基本模板
- 二分搜索树是一个二叉树   class BST
- 每一个节点的值大于其左孩子，小于其右孩子
- 二分搜索树不一定是完全二叉树
#### Test4.cpp 
- 向 class BST 中添加insert函数
- 如果出现key相同的情况，则用新得key-value 代替 旧的key-value
#### Test5.cpp
- 添加 contain 和 search 函数
#### Test6.cpp
- 中序遍历可以让二分搜索树从小到大输出key
- 后序遍历可以释放整个二分搜索树的空间
- 借助栈实现层序遍历
- preOrder() 、inOrder() 、 postOrder() 、 levelOrder()、 destroy()
```
4 57 56 96 98 60 33 98 99 32 
size: 9

preOrder:
4
57
56
33
32
96
60
98
99

inOrder:
4
32
33
56
57
60
96
98
99

postOrder:
32
33
56
60
99
98
96
57
4

levelOrder:
4
57
56
96
33
60
98
32
99
```
#### Test7.cpp
- 寻找二分搜索树中最小的key和最大的key  minimun  maximum
- 从二分搜索树中删除最小key和最大key所在的节点  removeMin   removeMax
#### Test8.cpp
- remove 删除任意节点
- 删除操作：
- 如果删除的节点是叶子：直接删除就好了
- 如果删除的节点只有左孩子或者右孩子：直接删除，并把下面的子树往上移
- 如果删除的节点(d)既有左孩子还有右孩子(Hubbard Deletion)
1. 找到d的后继节点s( min(d->right) s是d右子树中的最小值 )
2. 让s的右孩子变成d的右子树 s->right = delMin(d->right)
3. 让s的左孩子变成d的左子树 s->left = d->left
4. 删除d节点 
### BST.h  SequenceST.h
- 二分搜索树 和 顺序表
```
There are totally 11528 words in communist.txt

'unite' : 2        // 我们按照文本原有顺序插入进二分搜索树
BST , time: 0.006 s.

'unite' : 2       // 我们按照文本原有顺序插入顺序查找表
SST , time: 0.148 s.

'unite' : 2      // 我们将原文本排序后插入二分搜索树, 查看其效率
BST2 , time: 0.628 s.
```
#### Test9.cpp BinarySearch.h  LinearSearch.h
- firstGreaterOrEqual
- firstGreaterThan
- lastLessOrEqual
- lastLessThan
#### Test10.cpp
- floor: 寻找key的floor值
- ceil: 寻找key的ceil值
#### Test11.cpp
- successor:找到key的后继
- predecessor:找到key的前驱
#### Test12.cpp
- 非递归中序遍历
#### Test13.cpp
- 非递归后序遍历
#### Test14.cpp
- 非递归前序遍历
#### Test15.cpp
- Binary Tree Morris Traversal (inorder and preorder)
- Source : https://leetcode.com/problems/binary-tree-inorder-traversal/solution/
- Source : https://leetcode.com/problems/binary-tree-preorder-traversal/description/
#### Test16.cpp
- Binary Tree Morris Traversal (postorder)
- Source : https://leetcode.com/problems/binary-tree-postorder-traversal/description/
