#include<iostream>
#include<ctime>
#include"UnionFind5.h"

using namespace std;

// 测试第五版本的并查集, 测试元素个数为n
void testUF5( int n ){

    srand( time(NULL) );
    UF5::UnionFind uf = UF5::UnionFind(n);

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

    cout<<"UF5, "<<2*n<<" ops, "<<double(endTime-startTime)/CLOCKS_PER_SEC<<" s"<<endl;
}

int main(){
    int n = 10000;
    testUF5(n);
    return 0;
}