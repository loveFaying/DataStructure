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

    template<typename T>
    void selectionSort_1(T arr[], int length){
        // 在每一轮中, 可以同时找到当前未处理元素的最大值和最小值
        int left = 0 , right = length-1;
        while (left < right)
        {
            int minIndex = left;
            int maxIndex = right;

            // 在每一轮查找时, 要保证arr[minIndex] <= arr[maxIndex]
            if(arr[minIndex] > arr[maxIndex])
                std::swap(arr[minIndex], arr[maxIndex]);
            
            for(int i = left+1 ; i < right ; i ++){
                if(arr[i] < arr[minIndex])
                    minIndex = i;
                else if(arr[i] > arr[maxIndex])
                    maxIndex = i;
            }


            std::swap(arr[minIndex], arr[left]);
            std::swap(arr[maxIndex], arr[right]);

            left ++;
            right --;
        }
        return ;
    }


    template<typename T>
    void bubbleSort_1(T arr[] , int length){

        bool isSwapped; // 记录本轮是否发生了交换
        do{
            isSwapped = false;

            for(int i = 1 ; i < length; i ++){
                if(arr[i] < arr[i-1]){
                    std::swap(arr[i], arr[i-1]);
                    isSwapped = true;
                }
            }
            // 优化1 每一趟把最大的元素放在了最后，
            // 所以最后一个元素我们可以不用考虑
            length --;

        }while(isSwapped);

        return ;
    }

    template<typename T>
    void bubbleSort_2(T arr[] , int length){
        int endSwapIndex;

        do{
            endSwapIndex = 0;
            for(int i = 1 ; i < length ; i ++){
                if(arr[i] < arr[i-1]){
                    std::swap(arr[i], arr[i-1]);
                    endSwapIndex = i;
                }
            }
            // 记录最后一次的交换位置,在此之后的元素在下一轮扫描中均不考虑
            length = endSwapIndex;

        }while(endSwapIndex > 0);

        return ;
    }

    template<typename T>
    void shellSort(T arr[], int length){

        // 计算 increment sequence: 1, 4, 13, 40, 121, 364, 1093...
        int h = 1;
        while( h < length/3 )
            h = 3 * h + 1;

        while( h >= 1 ){

            // h-sort the array
            for( int i = h ; i < length ; i ++ ){

                // 对 arr[i], arr[i-h], arr[i-2*h], arr[i-3*h]... 使用插入排序
                T e = arr[i];
                int j;
                for( j = i ; j >= h && e < arr[j-h] ; j -= h )
                    arr[j] = arr[j-h];
                arr[j] = e;
            }

            h /= 3;
        }
    }

};

#endif