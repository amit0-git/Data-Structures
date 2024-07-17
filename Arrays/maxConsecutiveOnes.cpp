#include <iostream>

using namespace std;

int main()
{

    int arr[] = {0, 1, 0, 1, 1, 0, 1, 1, 1, 1, 0, 1, 1, 1,1,1};
    int size = sizeof(arr) / sizeof(int);

    int count = 0;
    int largest = 0;
    for (int i = 0; i < size; i++)
    {

        if (arr[i] == 1)
        {
            count++;
            largest = max(count, largest);
            
        }
        else
        {
            count = 0;
        }
    }

    cout << largest;

    return 0;
}