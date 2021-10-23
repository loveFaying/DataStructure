#ifndef HEAPIFY_HEAP_H
#define HEAPIFY_HEAP_H

#include <algorithm>
#include <cassert>

template<typename Item>
class MaxHeap{

private:
    Item *data;
    int count;
    int capacity;

    void shiftUp(int k){
        while( k > 1 && data[k/2] < data[k] ){
            std::swap( data[k/2], data[k] );
            k /= 2;
        }
    }

    void shiftDown(int k){
        while( 2*k <= count ){
            int j = 2*k;
            if( j+1 <= count && data[j+1] > data[j] ) j ++;
            if( data[k] >= data[j] ) break;
            std::swap( data[k] , data[j] );
            k = j;
        }
    }

public:

    // 构造函数, 构造一个空堆, 可容纳capacity个元素
    MaxHeap(int capacity){
        data = new Item[capacity+1];
        count = 0;
        this->capacity = capacity;
    }

    // 构造函数, 通过一个给定数组创建一个最大堆
    // 该构造堆的过程, 时间复杂度为O(n)
    // Heapify 操作
    MaxHeap(Item arr[], int n){
        data = new Item[n+1];
        capacity = n;

        for( int i = 0 ; i < n ; i ++ )
            data[i+1] = arr[i];
        count = n;

        // data从1开始
        for( int i = count/2 ; i >= 1 ; i -- )
            shiftDown(i);
    }

    ~MaxHeap(){
        delete[] data;
    }

    // 返回堆中的元素个数
    int size(){
        return count;
    }

    // 返回一个布尔值, 表示堆中是否为空
    bool isEmpty(){
        return count == 0;
    }

    // 像最大堆中插入一个新的元素 item
    void insert(Item item){
        assert( count + 1 <= capacity );
        data[count+1] = item;
        shiftUp(count+1);
        count ++;
    }

    // 从最大堆中取出堆顶元素, 即堆中所存储的最大数据
    Item extractMax(){
        assert( count > 0 );
        Item ret = data[1];
        std::swap( data[1] , data[count] );
        count --;
        shiftDown(1);
        return ret;
    }

    // 获取最大堆中的堆顶元素
    Item getMax(){
        assert( count > 0 );
        return data[1];
    }
};

// heapSort1, 将所有的元素依次添加到堆中, 在将所有元素从堆中依次取出来, 即完成了排序  
//创建堆的时间复杂度：O(nlogn)    取出的时间复杂度：O(nlogn)
template<typename T>
void heapSort1(T arr[], int n){

    MaxHeap<T> maxheap = MaxHeap<T>(n);
    for( int i = 0 ; i < n ; i ++ )
        maxheap.insert(arr[i]);

    for( int i = n-1 ; i >= 0 ; i-- )
        arr[i] = maxheap.extractMax();

}

// heapSort2, 借助我们的heapify过程创建堆
// 创建堆的过程时间复杂度为O(n), 将所有元素依次从堆中取出来, 实践复杂度为O(nlogn)
// 堆排序的总体时间复杂度依然是O(nlogn), 但是比上述heapSort1性能更优, 因为创建堆的性能更优
template<typename T>
void heapSort2(T arr[], int n){

    MaxHeap<T> maxheap = MaxHeap<T>(arr,n);
    for( int i = n-1 ; i >= 0 ; i-- )
        arr[i] = maxheap.extractMax();

}

#endif //INC_05_HEAPIFY_HEAP_H
