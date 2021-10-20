#include <iostream>
#include "SortedAlgorithm.h"
#include "SortedTestHelper.h"
using namespace std;

int main(){

    int arr[] = {10,11,2,3,4,5,9,8,7,6,5,4};
    int length = sizeof(arr)/sizeof(int);
    SortedAlgorithm::selectionSort(arr, length);
    SortedTestHelper::printArray(arr, length);

    int N = 10000;
    int* a = SortedTestHelper::generateRandomArray(N, 0, 500);
    SortedAlgorithm::selectionSort(a, N);
    SortedTestHelper::printArray(a, N);
    delete[] a;

    string c[4] = {"D","C","B","A"};
    length = sizeof(c)/sizeof(string);
    SortedAlgorithm::selectionSort(c, 4);
    SortedTestHelper::printArray(c, 4);

    float b[4] = {4.4,3.3,2.2,1.1};     
    SortedAlgorithm::selectionSort(b,4);     
    SortedTestHelper::printArray(b,4);



    return 0;
}