#include <iostream>
using namespace std;


int digit(int num){
    //base case 
    if (num==0){
        return 0;
    }
    


    //define the recursive fn

    return num%10+digit(num/10);
}



int main(){


    cout <<digit(21);




    return 0;
}