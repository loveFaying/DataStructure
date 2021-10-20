#ifndef SORTED_ALGORITHM_H
#define SORTED_ALGORITHM_H

#include <iostream>
#include <cassert>
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
    }

};

#endif