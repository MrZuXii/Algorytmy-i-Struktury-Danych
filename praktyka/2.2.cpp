#include <iostream>
#include <vector>

using namespace std;

int binarySearch(vector<int> items, int x) {
    const int n = size(items);
    int left = 0, right = n - 1, mid;

    while (left <= right) {
        mid = (right + left) / 2;
        if (items[mid] == x)
            return mid;
        else if (items[mid] > x)
            right = mid - 1;
        else
            left = mid + 1;
    }
    return -1;
}

int binarySearchRecursive(const vector<int>& items, int x, int left = 0,
                          int right = -1) {
    if (right == -1) {
        right = size(items) - 1;
    }

    if (left > right) return -1;
    int mid = (left + right) / 2;
    if (items[mid] == x)
        return mid;
    else if (items[mid] > x)
        return binarySearchRecursive(items, x, left, mid - 1);
    else
        return binarySearchRecursive(items, x, mid + 1, right);
}

int main() {
    vector<int> items = {2, 4, 6, 8, 10, 12, 14, 16, 18, 20};
    cout << "binarySearch(items, 14) → " << binarySearch(items, 14) << endl;
    cout << "binarySearch(items, 5) → " << binarySearch(items, 5) << endl;

    cout << "binarySearchRecursive(items, 14) → "
         << binarySearchRecursive(items, 14) << endl;
    cout << "binarySearchRecursive(items, 5) → "
         << binarySearchRecursive(items, 5) << endl;
    return 0;
}
