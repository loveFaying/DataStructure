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

};

#endif