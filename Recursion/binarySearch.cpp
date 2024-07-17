/* Recursive program for binary search */

#include <iostream>


using namespace std;


bool binarySearch(int *arr,int s,int e,int key){
    if (s>e){
        return false;
    }

    int mid=s+(e-s)/2;

    if (arr[mid]==key){
        return true;
    }

    if (arr[mid]>key){
        return binarySearch(arr,s,mid-1,key);
    }

    else{
        return binarySearch(arr,mid+1,e,key);
    }


}
int main(){


    //sorted array
    int arr[]={2,4,6,8,10,20,23,27,67,89};


    cout <<binarySearch(arr,0,9,27);



    return 0;
}