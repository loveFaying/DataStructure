#include <iostream>
#include <vector>
#include <ctime>
#include <string>
#include "Path.h"
#include "DenseGraph.h"
#include "SparseGraph.h"
#include "RandomGraph.h"
#include "Components.h"
#include "ReadGraph.h"
#include "ShortestPath.h"

using namespace std;

// 读取testG1和testG2, 求其连通性
void test1(){
    // TestG1.txt
    string filename1 = "testG1.txt";
    SparseGraph g1 = SparseGraph(13, false);
    ReadGraph<SparseGraph> readGraph1(g1, filename1);
    Component<SparseGraph> component1(g1);
    cout<<"TestG1.txt, Component Count: "<<component1.count()<<endl;

    cout<<endl;

    // TestG2.txt
    string filename2 = "testG2.txt";
    SparseGraph g2 = SparseGraph(7, false);
    ReadGraph<SparseGraph> readGraph2(g2, filename2);
    Component<SparseGraph> component2(g2);
    cout<<"TestG2.txt, Component Count: "<<component2.count()<<endl;
}

void test2(){
    // 测试深度优先遍历和广度优先遍历的寻路算法
    string filename = "testG2.txt";
    SparseGraph g = SparseGraph(7, false);
    ReadGraph<SparseGraph> readGraph(g, filename);
    g.show();
    cout<<endl;

    Path<SparseGraph> dfs(g,0);
    cout<<"DFS : ";
    dfs.showPath(6);

    ShortestPath<SparseGraph> bfs(g,0);
    cout<<"BFS : ";
    bfs.showPath(6);
}

// 随机生成一个图, 求其连通性
int main() {

    // Test Random Graph Component
    int V = 100;
    int E = V*(V-1)/2/10;
    bool directed = false;

    SparseGraph g1 = SparseGraph(V, directed);
    RandomGraph<SparseGraph>(g1, V, E);

    Component<SparseGraph> component1(g1);
    cout<<"Test Random Graph, Component Count: "<<component1.count()<<endl;

    return 0;
}