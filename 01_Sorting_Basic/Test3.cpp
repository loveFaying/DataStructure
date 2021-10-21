#include <iostream>
#include "SortedAlgorithm.h"
#include "SortedTestHelper.h"
using namespace std;

int main(){

    // test SortedTestHelper::copyArray
    int length = 10;
    int* arr = SortedTestHelper::generateRandomArray(length, 0, length);
    SortedTestHelper::printArray(arr, length);
    int* arr_t = SortedTestHelper::copyArray(arr, length);
    SortedTestHelper::printArray(arr_t, length);
    delete[] arr;
    delete[] arr_t;

    char c[] = {'D','C','B','A', '2', 'd' , 'a', 'E'};
    char* arr_c = SortedTestHelper::copyArray(c, sizeof(c)/sizeof(char));
    SortedTestHelper::printArray(arr_c, sizeof(c)/sizeof(char));
    delete[] arr_c; 

    // test SelectionSort  InsertionSort_1  InsertionSort_2 
    
    int N = 20000;
    int* arr1 = SortedTestHelper::generateRandomArray(N, 0, N);
    int* arr2 = SortedTestHelper::copyArray(arr1, N);
    int* arr3 = SortedTestHelper::copyArray(arr2, N);

    cout<<"Test for random array, size = "<< N <<", random range [0, "<< N <<"]"<<endl;
    SortedTestHelper::testSort("Selection Sort", SortedAlgorithm::selectionSort, arr1, N);
    SortedTestHelper::testSort("Insertion Sort 1", SortedAlgorithm::insertionSort_1, arr2, N);
    SortedTestHelper::testSort("Insertion Sort 2", SortedAlgorithm::insertionSort_2, arr3, N);


    delete[] arr1;
    delete[] arr2;
    delete[] arr3;
    
    return 0;
}