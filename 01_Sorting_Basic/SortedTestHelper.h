#ifndef SORTED_TEST_HELPER_H
#define SORTED_TEST_HELPER_H

#include <iostream>
#include <ctime>
#include <cassert>

namespace SortedTestHelper{

    // 打印数组内容
    template<typename T>
    void printArray(T arr[], int length){

        for(int i = 0 ; i < length ; i ++){
            std::cout << arr[i] << " ";
        }
        std::cout << std::endl;
    }

    // 生成有n个元素 整型 随机数组，每个元素的随机范围为[rangeL, rangeR]
    int* generateRandomArray(int n, int rangeL, int rangeR){
        assert(rangeL <= rangeR);

        int* arr = new int[n];

        srand(time(NULL));
        for(int i = 0 ; i < n ; i ++){
            arr[i] = rand()%(rangeR - rangeL + 1) + rangeL;
        }
        return arr;
    }

    // 测试数组是否有序
    template<typename T>
    bool isSorted(T arr[], int length){
        for(int i = 0 ; i < length-1 ; i ++)
            if(arr[i] > arr[i+1])   // 注意数组越界  i < length-1
                return false;
        return true;
    }

    // 测试sort排序算法排序arr数组所得到结果的正确性和算法运行时间
    template<typename T>
    void testSort(const std::string& sortName, void (*sort)(T[], int), T arr[], int length){

        clock_t startTime = clock();
        sort(arr, length);
        clock_t endTime = clock();

        assert(isSorted(arr, length)); // 保证arr是有序的
        std::cout << sortName << " : " << (double)(endTime - startTime) / CLOCKS_PER_SEC << "s" << std::endl;

        return ;
    }

    // 拷贝数组a中的所有元素到一个新的数组, 并返回新的数组
    template<typename T>
    T* copyArray(T a[], int length){

        T* arr = new T[length];
        for(int i = 0 ; i < length ; i ++)
            arr[i] = a[i];
        return arr;
    }

    // 生成一个近乎有序的 整型 数组(先生成[0...n-1]的完全有序的数组，然后再进行swapTimes对交换)
    int* generateNearlyOrderedArray(int n, int swapTimes){

        int *arr = new int[n];
        for(int i = 0 ; i < n ; i ++)
            arr[i] = i;
        
        srand(time(NULL));
        for(int i = 0 ; i < swapTimes ; i ++){
            int posx = rand()%n;
            int posy = rand()%n;
            std::swap(arr[posx], arr[posy]);
        }

        return arr;
    }

};

#endif