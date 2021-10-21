#ifndef SORTED_ALGORITHM_H
#define SORTED_ALGORITHM_H

#include <iostream>
#include <cassert>
#include <ctime>
#include <algorithm>

namespace SortedAlgorithm{
    template<typename T>
    void selectionSort(T arr[], int length){

        for(int i = 0 ; i < length ; i ++){

            int minIndex = i;
            // 寻找[i, n)区间里的最小值
            for(int j = i+1 ; j < length ; j ++){
                if(arr[minIndex] > arr[j]){
                    minIndex = j;
                }
            }
            if(minIndex != i)
                std::swap(arr[minIndex], arr[i]);
        }
        return ;
    }

    // 每一轮 基于多次swap的插入排序
    template<typename T>
    void insertionSort_1(T arr[], int length){

        for( int i = 1 ; i < length ; i ++ ) {

            // 寻找元素arr[i]合适的插入位置
            // 写法1
            // for( int j = i ; j > 0 ; j-- )
            //     if( arr[j] < arr[j-1] )
            //         std::swap( arr[j] , arr[j-1] );
            //     else
            //         break;

            // 写法2
            for( int j = i ; j > 0 && arr[j] < arr[j-1] ; j -- )
                std::swap( arr[j] , arr[j-1] );
            }
            return;
        }
    
    // 每一轮 不做swap的插入排序
    template<typename T>
    void insertionSort_2(T arr[], int length){
        for(int i = 1 ; i < length ; i ++){

            // 寻找元素arr[i]合适的插入位置
            T temp = arr[i];
            int j; // j保存元素temp应该插入的位置
            for(j = i ; j > 0 ; j --){ // 注意数组越界
                if(arr[j-1] > temp)
                    arr[j] = arr[j-1];
                else    
                    break;
            }
            arr[j] = temp;

            // 写法2
            // T temp = arr[i];
            // int j; // j保存元素e应该插入的位置
            // for (j = i; j > 0 && arr[j-1] > temp; j--)
            //     arr[j] = arr[j-1];
            // arr[j] = temp;
        }
        return ;

    } 


};

#endif