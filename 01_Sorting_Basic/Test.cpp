#include<iostream>
using namespace std;

template<typename T>
void SelectionSort(T arr[], int length){

    for(int i = 0 ; i < length ; i ++){

        int minIndex = i;
        // 寻找[i, n)区间里的最小值
        for(int j = i+1 ; j < length ; j ++){
            if(arr[minIndex] > arr[j]){
                minIndex = j;
            }
        }
        if(minIndex != i)
            swap(arr[minIndex], arr[i]);
    }
}

int main(){

    int arr[] = {10,11,2,3,4,5,9,8,7,6,5,4};
    int length = sizeof(arr)/sizeof(int);
    SelectionSort(arr, length);
    for(int i = 0 ; i < length ; i ++)
        cout << arr[i] << " ";
    cout << endl;

    string c[4] = {"D","C","B","A"};
    SelectionSort(c,4);
    for( int i = 0 ; i < 4 ; i ++ )
        cout<<c[i]<<" ";
    cout<<endl;

    return 0;
}