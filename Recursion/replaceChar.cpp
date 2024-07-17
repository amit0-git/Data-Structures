//fn to replace character in the string


#include <iostream>

using namespace std;

void replaceChar(char arr[]){
    //replace b with x
    if (arr[0]=='\0'){
        return;
    }

    if (arr[0]=='b'){
        arr[0]='x';
    }

    replaceChar(arr+1);

}

int main(){
    char arr[]="baccbammcbbbb";
    replaceChar(arr);
    cout <<arr;
    



    return 0;
}