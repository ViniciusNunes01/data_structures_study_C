#include <stdio.h>

int getFirstElement(int arr[], int size)
{
    int first = arr[0]; // 2
    return first;       // 1
} // f(n) = 2 + 1 -> lim f(n) = 3 -> O(1)

int findValue(int arr[], int size, int target)
{
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == target) // 1*n
        {
            return i; // 1
        }
    }
    return -1; // 1
} // O(n)

void printPairs(int arr[], int size)
{
    for (int i = 0; i < size; i++) // n
    {
        for (int j = 0; j < size; j++) // n
        {
            printf("(%d, %d)", arr[i], arr[j]); // 1
        }
    }
} // O(n²)

int main()
{
    return 0;
}