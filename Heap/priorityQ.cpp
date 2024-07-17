//priority queue STL in CPP
//priority queue is a MAX Heap

#include <queue>
#include <iostream>
using namespace std;

int main(){
 
 priority_queue<int> pq;


 pq.push(20);
 pq.push(30);
 pq.push(40);
 pq.push(90);
 pq.push(10);
 pq.push(80);
 int count=0;
 while(!pq.empty()){
    if (count==1){
        cout<<pq.top()<<endl;
    }

 pq.pop();
 count++;
 }
 






    return 0;
}