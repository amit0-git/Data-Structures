#include <iostream>



using namespace std;

int length(const int *num){
    int ans=0;
    int num1=*num;

    while(num1!=0){
        ans++;
        num1=num1/10;

    }


    return ans;

};



int isPalindrome(int x) {

        //-ve number case
        if (x<0){
            return false;
        }
        
        int num=x;
        int ans=0;
        int rem;

        while (x!=0){
            rem=x%10;
            ans=ans*10+rem;

            x=x/10;
        }


        return ans;
};



int main(){

    int num=1234;
    int len=length(&num);
    int lastMod=10;

    for (int i=0;i<len/2;i++){
        cout<<num%10<<" ";
        num=num/10;
    }




cout<<"Palindrome: "<<isPalindrome(121);





    return 0;
}