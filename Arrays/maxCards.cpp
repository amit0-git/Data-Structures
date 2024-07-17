// Pick N cards from the array whose sum is maximun
// Only pick from the front and rear

#include <iostream>
using namespace std;
int main()
{

    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int n = sizeof(arr) / sizeof(int);

    int k = 4;
    int maxSum=0;

    for (int i = 0; i < k+1; i++)
    {
        int leftSum=0;
        int rightSum=0;


        int last = n - i % n;
      

        for (int left = 0; left < k - i; left++)
        {
            leftSum=leftSum+arr[left];
        }
      
        for (int right = last; right < n; right++)
        {
            rightSum=rightSum+arr[right];
        }

        maxSum=max(maxSum,leftSum+rightSum);


       
    }



    cout<<"Max Sum: "<<maxSum;

    return 0;
}