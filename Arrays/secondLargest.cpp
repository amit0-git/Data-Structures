#include <iostream>
#include <bits/stdc++.h>
using namespace std;


#define for(i,s,e) for(int i=s;i<e;i++)

int main()
{

    int arr[] = {9, 8, 7, 6,0,2,3,3};
    int size=sizeof(arr)/sizeof(int);
    int largest=arr[0];
    int slargest=INT_MIN;

    for(i,0,size){

        if (arr[i]>largest){
            slargest=largest;
            largest=arr[i];
            
        }

        else if (arr[i]<largest && arr[i]>slargest){
            slargest=arr[i];
        }

        
    }


    cout<<"Largest: "<<largest<<"\n";
    cout<<"Second Largest: "<<slargest<<"\n";


    

    return 0;
}