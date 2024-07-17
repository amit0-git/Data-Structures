#include <iostream>


using namespace std;


bool linearSearch(int arr[],int size,int key){
    if (size==0){

        //if the array becomes empty and no element is found
        return false;
    }

//solve only one test case rest will be solved by recursion

    if (arr[0]==key){

        //if the key is found
        return true;
    }

    return linearSearch(arr+1,size-1,key);
}

int main(){


    int arr[5]={12,34,56,23,54};
    cout <<linearSearch(arr,5,56);



    return 0;
}