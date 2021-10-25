#include <iostream>
#include <cassert>
#include <ctime>

using namespace std;

// 二分查找法,在有序数组arr中,查找target
// 如果找到target,返回相应的索引index
// 如果没有找到target,返回-1
template<typename T>
int binarySearch(T arr[], int n, T target){

    // 在arr[l...r]之中查找target
    int l = 0, r = n-1; // 注意循环不变量的定义
    while( l <= r ){

        //int mid = (l + r)/2;
        // 防止极端情况下的整形溢出，使用下面的逻辑求出mid
        int mid = l + (r-l)/2;

        if( arr[mid] == target )
            return mid;

        if( arr[mid] > target )
            r = mid - 1;
        else
            l = mid + 1;
    }

    return -1;
}

// 用递归的方式写二分查找法
template<typename T>
int __binarySearch2(T arr[], int l, int r, T target){

    if( l > r )
        return -1;

    //int mid = (l+r)/2;
    // 防止极端情况下的整形溢出，使用下面的逻辑求出mid
    int mid = l + (r-l)/2;

    if( arr[mid] == target )
        return mid;
    else if( arr[mid] > target )
        return __binarySearch2(arr, l, mid-1, target);
    else
        return __binarySearch2(arr, mid+1, r, target);
}

template<typename T>
int binarySearch2(T arr[], int n, T target){

    return __binarySearch2( arr , 0 , n-1, target);
}

int main(){
    int n = 100;
    int* arr = new int[n];
    for(int i = 0 ; i < n ; i ++)
        arr[i] = i+10;
    
    int v = binarySearch(arr, n, 55);
    cout << v << endl;

    v = binarySearch2(arr, n , 100);
    cout << v << endl;


    return 0;
}