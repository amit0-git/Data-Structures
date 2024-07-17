#include <iostream>
using namespace std;



void heapify(int a[],int &n,int i){
    int large=i;
    int l=2*i;
    int r=2*i+1;

    if(l<=n && a[l]>a[large]){
        large=l;

    }

    if(r<=n && a[r]>a[large]){
        large=r;
    }

    //chk whether the large was changed

    if(large!=i){
        swap(a[i],a[large]);

        //call the heapify function for the below elements
        heapify(a,n,large);
    }
}


void insert(int arr[],int data,int &n){
    arr[n]=data;
    n=n+1;
    for (int i = n / 2 ; i > 0; i--)
    {
      heapify(arr, n, i);
    }

}
int main(){
    int arr[10];
    int n=0;
    insert(arr,20,n);
    insert(arr,30,n);
    insert(arr,40,n);


    for (int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }



    return 0;
}