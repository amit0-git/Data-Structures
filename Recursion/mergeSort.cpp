#include <iostream>

using namespace std;


void merge(int *arr,int s,int e){
    int mid=(s+e)/2;

    int len1=mid-s+1;
    int len2=e-mid;

    //make tmp arrays and copy the data of the two sorted arrays
    int *first=new int[len1];
    int *second=new int[len2];

    //copy the values

    int k=s; //first sorted array starts with 
    
    for (int i=0;i<len1;i++){
        first[i]=arr[k++];
    }

    k=mid+1; //second sorted array starts with mid+1
    for (int i=0;i<len2;i++){
        second[i]=arr[k++];
    }

    //merge two sorted arrays

    int index1=0;
    int index2=0;
    k=s;

    while (index1<len1  && index2<len2){
        if(first[index1]<second[index2]){
            arr[k++]=first[index1++];
        }

        else{
            arr[k++]=second[index2++];
        }
    }

    //chk whether arrays are left

    while (index1<len1)
    {
       arr[k++]=first[index1++];
    }

    while (index2<len2)
    {
       arr[k++]=second[index2++];
    }



    delete []first;
    delete []second;
}




void mergeSort(int *arr,int s,int e){

    //base case arr with 0 or 1 element is sorted

    if (s>=e){
        return;
    }

    int mid=(s+e)/2;

    //left part sort

    mergeSort(arr,s,mid);
    //right part sort
    mergeSort(arr,mid+1,e);

    //merge the sorted arrays

    merge(arr,s,e);
}

int main(){


    int arr[9]={9,8,7,6,5,4,3,2,1};
    mergeSort(arr,0,8);


    for (int i=0;i<9;i++){
        cout <<arr[i]<<" ";
    }




    return 0;
}