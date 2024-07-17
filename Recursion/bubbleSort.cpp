#include <iostream>

using namespace std;



void bubbleSort(int *arr,int n){

    if (n==0|| n==1){
        return;
    }

    //solve only 1 case rest will be solved by recursion

    for (int i=0;i<n-1;i++){
        if(arr[i]>arr[i+1]){
            swap(arr[i],arr[i+1]);
        }
    }
    //recursive case

    bubbleSort(arr,n-1);
}


int main(){

    int arr[]={45,34,23,45,4,34,33,35};
    int size=8;
    bubbleSort(arr,size);

    for (int i=0;i<size;i++){
        cout <<arr[i]<<" ";
    }



    return 0;
}