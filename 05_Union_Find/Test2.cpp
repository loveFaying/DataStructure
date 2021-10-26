#include "UnionFind2.h"
#include <iostream>
#include <ctime>

using namespace std;

void testUF2( int n ){

    srand( time(NULL) );
    UF2::UnionFind uf = UF2::UnionFind(n);

    time_t startTime = clock();

    for( int i = 0 ; i < n ; i ++ ){
        int a = rand()%n;
        int b = rand()%n;
        uf.unionElements(a,b);
    }
    for(int i = 0 ; i < n ; i ++ ){
        int a = rand()%n;
        int b = rand()%n;
        uf.isConnected(a,b);
    }
    time_t endTime = clock();

    cout<<"UF2, "<<2*n<<" ops, "<<double(endTime-startTime)/CLOCKS_PER_SEC<<" s"<<endl;
}

int main(){

    // 使用10000的数据规模
    int n = 10000;

    // 对于UF2来说, 其时间性能是O(n*h)的, h为并查集表达的树的最大高度
    // 这里严格来讲, h和logn没有关系, 不过大家可以简单这么理解
    // 我们后续内容会对h进行优化, 总体而言, 这个h是远小于n的
    // 所以我们实现的UF2测试结果远远好于UF1, n越大越明显:)
    testUF2(n);
    return 0;
}