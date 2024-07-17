#include <iostream>
using namespace std;


bool isPalindrome(string s,int i,int j){

    if (i>j){
        return true;
    }

    if (s[i]!=s[j]){
        return false;
    }

    i++;
    j--;

    return isPalindrome(s,i,j);
}

int main(){

    string s="abbccbbaa";
    cout <<isPalindrome(s,0,s.length()-1);



    return 0;
}