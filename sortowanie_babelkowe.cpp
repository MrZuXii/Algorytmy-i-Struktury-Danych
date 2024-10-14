#include <iostream>

using namespace std;

void bubble_sort(int arr[], int n)
{
    for (int i = 0; i < n -1; i++)
    {
        for (int j = 1; j < n - i; j++)
            if (arr[j - 1] > arr[j])
                swap(arr[j - 1], arr[j]);
    }
}

void show_array(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}



int main()
{
    int arr[] = {
        23, 47, 85, 12, 56, 92, 18, 67, 34, 5,
        79, 3, 94, 16, 71, 28, 45, 88, 62, 11,
        54, 39, 87, 33, 8, 27, 4, 70, 77, 60,
        22, 98, 74, 90, 25, 10, 19, 64, 83, 7,
        36, 42, 99, 50, 68, 41, 35, 2, 57, 80,
        29, 75, 91, 1, 20, 38, 72, 61, 15, 69,
        6, 81, 30, 49, 17, 44, 76, 100, 13, 14,
        59, 93, 84, 37, 9, 24, 65, 48, 66, 88};

    int rozmiar_tablicy = sizeof(arr) / sizeof(arr[0]);

    bubble_sort(arr, rozmiar_tablicy);
    show_array(arr, rozmiar_tablicy);

    return 0;
};