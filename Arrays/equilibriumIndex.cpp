/*
Equilibrium index of an array is an index such that the sum of elements at lower indexes is equal to the sum of elements at higher indexes.
Given an array, your task is to find the index of first Equilibrium point in the array.
*/

#include <iostream>


using namespace std;

int equilibriumIndex(int *arr,int n){

    //first store the sum of the whole array
    int sum=0;
    int leftSum=0;

    for (int i=0;i<n;i++){
        sum+=arr[i];

    }

    //now traverse the array and subtract elements of  the array from the total sum
    //add the elements to the leftSum 
    //if the leftSum and the sum becomes equal  return

    for (int i=0;i<n;i++){

        sum-=arr[i];

        //chk whether left and sum  are equal

        if (leftSum==sum){
            return i;
        }

        leftSum+=arr[i];
    }



    return -1;
}

int main(){


    int arr[7]={1,2,3,-1,6,0,0};
    int index=equilibriumIndex(arr,7);



    cout <<index;




    return 0;
}