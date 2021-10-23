#include <iostream>
#include <algorithm>
#include <string>
#include <ctime>
#include <cmath>
#include <cassert>

using namespace std;

template<typename T>
class MaxHeap{
private:
    T *data;  // 从1号位置开始存储
    int count;
    int capacity;

    void shiftUp(int k){
        // 注意边界，要保证data[k/2]存在
        while(k > 1 && data[k/2] < data[k]){ 
            swap( data[k/2], data[k] );
            k /= 2;
        }
    }


public:
    // 构造函数, 构造一个空堆, 可容纳capacity个元素
    MaxHeap(int capacity){
        data = new T[capacity+1];
        count = 0;
        this->capacity = capacity;
    }

    ~MaxHeap(){
        delete[] data;
    }

    //返回堆中元素的个数
    int size(){
        return count;
    }

    //返回一个布尔值，表示堆中是否为空
    bool isEmpty(){
        return count == 0;
    }

    // 像最大堆中插入一个新的元素 item
    void insert(T item){
        assert( count + 1 <= capacity );
        data[count+1] = item;
        count ++;
        shiftUp(count);
    }

    void printHeapData(){
        assert(count > 0);
        for(int i = 1 ; i <= count ; i ++)
            cout << data[i] << " ";
        cout << endl;
    }
};

int main(){

    MaxHeap<int> maxheap = MaxHeap<int>(100);
    
    srand(time(NULL));
    for(int i = 0 ; i < 20 ; i ++)
        maxheap.insert(rand()%100);
    cout << maxheap.size() << endl;
    maxheap.printHeapData();

    return 0;
}