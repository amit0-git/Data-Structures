#include <iostream>
#include <set>

using namespace std;

int main()
{

    int arr[] = {1, 1, 1, 2, 2, 3, 3, 4, 4, 5, 5, 6, 7, 8};
    int size = sizeof(arr) / sizeof(int);


    set<int> s;

    for (int i = 0; i < size;i++){

        s.insert(arr[i]);

    }


    for (auto i=s.begin();i!=s.end();i++){
        cout<<*i<<" ";
    }

        return 0;
}