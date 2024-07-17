//remove X from the char array or string using recursion

#include <iostream>

using namespace std;


void removeX(char a[]){
    if (a[0]=='\0'){
        return;
    }

    if (a[0]!='x'){
        //if the first element of the array is not 'x'
        //then move 1 pos up
        removeX(a+1);
    }
    else{
        //if first element is x
        //then remove x and move whole array 1 pos up
        int i=1;
        for (;a[i]!='\0';i++){
            a[i-1]=a[i];

        }

        // also move the last terminating character  \0
        a[i-1]=a[i];
        //call for the next element i.e first element after array resize
        removeX(a);
    }
}



int main(){


    char a[]={'x','x','a','m','i','t','x','\0'};
    removeX(a);
    cout <<a;




    return 0;
}