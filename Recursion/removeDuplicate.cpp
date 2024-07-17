// recursive fn to remove the duplicates
#include <iostream>

using namespace std;



void removeDuplicate(char arr[]){
    if (arr[0]=='\0' || arr[1]=='\0'){
        //if the string contains no or 1 element then it contains unique element
        return;
    }

    if (arr[0]==arr[1]){

        for (int i=0;arr[i]!='\0';i++){
            ///if the first and the 2nd elements are equal then shift the elemens tot the left
            //then recurse the fn for the rest

            arr[i]=arr[i+1];

        }
        removeDuplicate(arr);
    }

    else{
        removeDuplicate(arr+1);
    }
   


}
int main(){

    char arr[]="aaaammmmmiiiiiiiitttttt";
    cout <<"Before :"<<arr<<endl;
    removeDuplicate(arr);
    cout <<"After: "<<arr;



    return 0;
}