//for recursion deifne the recursion in the functions term  


#include <iostream>
#include <bitset>
using namespace std;

//function for factorial
long long int factorial(int n){
    //base case

    if(n==0)
    return 1;

    

    return n*factorial(n-1);
    
}

//fn to find power of number


int power(int base,int pow){

    if (pow==0){
        return 1;
    }

    return base*power(base,pow-1);
}

//fn to check whether array is sorted using recursion
bool isSorted(int arr[],int size){

    //base: if the array has one or no element then it is sorted

    if (size<=1){
        return true;
    }


    if(arr[0]<=arr[1]){
        return isSorted(arr+1,size-1);
    }

    else{
        return false;
    }
}

//fn for fibonacci series

int fibonacci(int num){
    //base case

    if (num<=1){
        return num;
    }

    return fibonacci(num-1)+fibonacci(num-2);
}



//fn to find the sum of the array


int getSum(int arr[],int size){


    if (size==0){
        return 0;
    }
    if (size==1){
        return arr[0];
    }

    return arr[0]+getSum(arr+1,size-1);
}


int main(){
    

    int arr[3]={5,12,13};
    cout <<getSum(arr,3);

    cout <<endl<<factorial(21);



    return 0;
}