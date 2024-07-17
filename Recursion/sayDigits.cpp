#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

void sayDigit(int n, string arr[])
{
    if (n == 0)
    {
        return;
    }

    int n1 = n % 10;
    n = n / 10;

    sayDigit(n, arr);
    cout << arr[n1] << " ";
}

int main()
{
    int n;
 
    int i = 0;
    int j = n - 1;
    cin >> n;
    int *arr = new int[n];
   

   for (int i=0;i<n;i++){
        cin>>arr[i];
   }

    i=0;
    
    // while (i < j)
    // {
    //     int tmp=arr[i];
    //     arr[i]=arr[j];
    //     arr[j]=tmp;
    //     i++;
    //     j--;
    // }

    reverse(arr, arr + n);

    for (i = 0; i < n; i++)
    {
        cout << arr[i] << " ";

        
    }

    delete[] arr;

    return 0;
}
