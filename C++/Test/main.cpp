#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

void input(int*& arr, int& n, int& k)
{
    std::cin >> n >> k;
    arr = new int[n];

    for (int i = 0; i < n; ++i)
    {
        std::cin >> arr[i];
    }
}

int findMax(int* arr, int pos, int k)
{
    int max = pos;

    for (int i = pos + 1; i < pos + k; ++i)
    {
        if (arr[i] > arr[max])
        {
            max = i;
        }
    }

    return max;
}

int main()
{
    int* arr;
    int n;
    int k;
    input(arr, n, k);

    int max = findMax(arr, 0, k);
    std::cout << arr[max] << ' ';

    for (int i = 1; i < n - k + 1; ++i)
    {
        if (max < i)
        {
            max = findMax(arr, i, k);
        }
        else if (arr[max] < arr[i + k - 1])
        {
            max = i + k - 1;
        }

        std::cout << arr[max] << ' ';
    }
    return 0;
}
