#include <iostream>
#include "SortedAlgorithm.h"
#include "SortedTestHelper.h"
using namespace std;

int main(){

    int length = 20;
    int* a = SortedTestHelper::generateRandomArray(length, 0, 100);
    SortedAlgorithm::selectionSort(a, length);
    SortedTestHelper::printArray(a, length);
    if(SortedTestHelper::isSorted(a, length))
        cout << "order array"<< endl;
    else
        cout << "unorder array" << endl;
    delete[] a;


    length = 100000;
    int* arr = SortedTestHelper::generateRandomArray(length, 0, length);
    SortedTestHelper::testSort("selectionSort", SortedAlgorithm::selectionSort, arr, length);
    delete[] arr;

    return 0;
}