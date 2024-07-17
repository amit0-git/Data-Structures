/*You have been given a number of stairs. Initially, you are at the 0th stair, and you need to reach the Nth stair. Each time you can either climb one step or two steps. You are supposed to return the number of distinct ways in which you can climb from the 0th step to Nth step.*/
#include <iostream>
using namespace std;




int countDistinctWays(int nStairs) {
    //base case
    if (nStairs<0){
        return 0;
    }

    //if the person is on the 0th stair then return 1

    if (nStairs==0){
        return 1;
    }

    return countDistinctWays(nStairs-1)+countDistinctWays(nStairs-2);
}
int main(){
    int s;
    cout <<"Nth Stair: ";
    cin>>s;
    cout <<countDistinctWays(s);




    return 0;
}