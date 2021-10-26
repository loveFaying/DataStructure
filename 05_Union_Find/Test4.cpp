#include <iostream>
#include "UnionFind4.h"
#include <ctime>

using namespace std;

// 测试第四版本的并查集, 测试元素个数为n
void testUF4( int n ){

    srand( time(NULL) );
    UF4::UnionFind uf = UF4::UnionFind(n);

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

    cout<<"UF4, "<<2*n<<" ops, "<<double(endTime-startTime)/CLOCKS_PER_SEC<<" s"<<endl;
}

int main(){

    int n = 10000;
    testUF4(n);

    return 0;
}