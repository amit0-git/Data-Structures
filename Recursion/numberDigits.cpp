// reursive program to find the number of digits in the numbers

#include <iostream>

using namespace std;

int numDigits(int num)
{
    if (num == 0)
    {
        return 0;
    }

    return numDigits(num / 10) + 1;
}


int main()
{
    

    cout <<numDigits(12345);

    return 0;
}