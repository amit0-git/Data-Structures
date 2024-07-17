#include <iostream>


using namespace std;

void print(int N){
    if (N==0){
        return ;
    }

    print(N-1);

    cout <<N<<" ";
}

int main(){

    print(10);

    return 0;
}