#include <iostream>
#include "UnionFind3.h"
#include <ctime>

using namespace std;

// 测试第三版本的并查集, 测试元素个数为n
void testUF3( int n ){

    srand( time(NULL) );
    UF3::UnionFind uf = UF3::UnionFind(n);

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

    cout<<"UF3, "<<2*n<<" ops, "<<double(endTime-startTime)/CLOCKS_PER_SEC<<" s"<<endl;
}

// 对比UF1, UF2和UF3的时间性能
int main() {

    // 使用10000的数据规模
    int n = 10000;

    // 对于UF3来说, 其时间性能依然是O(n*h)的, h为并查集表达的树的最大高度
    // 但由于UF3能更高概率的保证树的平衡, 所以性能更优
    testUF3(n);

    return 0;
}