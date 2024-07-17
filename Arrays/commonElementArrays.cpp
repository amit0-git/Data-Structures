/*Find the common element from the multiple arrays
This can be done using two pointer or three pointer approach


For such problems if the array is unsorted than sort the array
*/

#include <iostream>
using namespace std;


void intersection(int *arr1,int *arr2,int *interAns,int m,int n,int &k){

    int i=0,j=0;
    while(i<m && j<n){
        if (arr1[i]<arr2[j]){
            //i th element cant be common
            //increment it

            i++;
        }

        else if (arr1[i]>arr2[j]){

            //j th element cant be common
            //increment it

            j++;

        }

        else{
            //if both the elements are equal

            interAns[k]=arr1[i];
            i++,j++,k++;
        }
    }

}
int main(){

    int arr1[5]={2,3,4,5,6};
    int arr2[7]={4,6,8,9,10,12,34};
    int arr3[3]={4,9,34};
    
    int interAns[3];
    int k=0;
    int l=0;


    intersection(arr1,arr2,interAns,5,7,k);
    

    intersection(interAns,arr3,interAns,k,3,l);

  
    for (int i=0;i<l;i++){
        cout <<interAns[i]<<" ";
    }






    return 0;
}