//subsequence or subsets is not continuous
///while subarray and substring is continous

#include <iostream>
using namespace std;



void subStr(string input ,string output){
    if (input.length()==0){
        cout <<output<<" ";
        return;
    }


    //include the first char in o/p
    subStr(input.substr(1),output+input[0]);


    //don;t include first char

    subStr(input.substr(1),output);
}


int main(){

    string a="abc";
    string b;
    subStr(a,b);
    



    return 0;
}
