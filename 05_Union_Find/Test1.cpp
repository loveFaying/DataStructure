#include "UnionFind1.h"
#include <iostream>
#include <ctime>

using namespace std;

// 测试第一版本的并查集, 测试元素个数为n
void testUF1( int n ){

    srand( time(NULL) );
    UF1::UnionFind uf = UF1::UnionFind(n);

    time_t startTime = clock();

    // 进行n次操作, 每次随机选择两个元素进行合并操作
    for( int i = 0 ; i < n ; i ++ ){
        int a = rand()%n;
        int b = rand()%n;
        uf.unionElements(a,b);
    }
    // 再进行n次操作, 每次随机选择两个元素, 查询他们是否同属一个集合
    for(int i = 0 ; i < n ; i ++ ){
        int a = rand()%n;
        int b = rand()%n;
        uf.isConnected(a,b);
    }
    time_t endTime = clock();

    // 打印输出对这2n个操作的耗时
    cout<<"UF1, "<<2*n<<" ops, "<<double(endTime-startTime) / CLOCKS_PER_SEC << " s"<<endl;
}

int main(){

    // 使用10000的数据规模
    int n = 10000;

    // 虽然isConnected只需要O(1)的时间, 但由于union操作需要O(n)的时间
    // 总体测试过程的算法复杂度是O(n^2)的
    testUF1(n);

    return 0;
}