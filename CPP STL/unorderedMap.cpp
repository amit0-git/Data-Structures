#include <iostream>
#include <unordered_map>
using namespace std;

int  main(){


    unordered_map<int ,int> hash;


    for(int i=0;i<10;i++){
        hash[i]=i*i+1;
    }
    

    for (auto x:hash){
        cout<<x.first<<" "<<x.second<<"\n";
    }






    return 0;
}