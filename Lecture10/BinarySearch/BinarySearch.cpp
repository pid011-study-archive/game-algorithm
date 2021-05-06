#include <iostream>

int BinarySearch(int S[], int x, int len)
{
    int low = 0;
    int high = len - 1;
    int mid;

    while (low <= high)
    {
        mid = (low + high) / 2;
        if (S[mid] == x) return mid;

        if (S[mid] > x)
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return -1;
}

int main()
{
    int S[] { 1, 2, 3, 4, 5, 6, 7, 8, 9 };

    int idx = BinarySearch(S, 3, 9);

    if (idx == -1)
    {
        std::cout << "값을 찾지 못함" << std::endl;
    }
    else
    {
        std::cout << "는 " << idx << "번째에 위치함" << std::endl;
    }
}
