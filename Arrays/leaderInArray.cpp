/*
Given an array A of positive integers. Your task is to find the leaders in the array. An element of array is leader if it is greater than or equal to all the elements to its right side. The rightmost element is always a leader. 
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> leaders(int a[], int n){

    vector<int> ans;
    ans.push_back(a[n-1]);
    int max=a[n-1];
    
    //store the last element and traverse from the back 
    for (int i=n-2;i>-1;i--){
        if (a[i]>=max){
            max=a[i];
            ans.push_back(a[i]);
        }
    }

    //now revrese the array for geting the ans  in the correct order

    reverse(ans.begin(),ans.end());

    return ans;

}


int main(){

    int arr[]={16,17,4,3,5,2};
    vector<int> ans=leaders(arr,6);

    for (int i=0;i<ans.size();i++){
        cout <<ans[i]<<" ";
    }





    return 0;
}