#include <iostream>
#include <vector>

using namespace std;

int interpolationSearch(vector<int> items, int x) {
    const int n = items.size();
    int left = 0, right = n - 1;

    while (left <= right && x >= items[left] && x <= items[right]) {
        int mid = left + (static_cast<double>(x - items[left]) /
                          (items[right] - items[left])) *
                             (right - left);

        if (items[mid] == x) return mid;
        if (items[mid] < x)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return -1;
}

int main() {
    vector<int> items = {2, 4, 6, 8, 10, 12, 14, 16, 18, 20};
    cout << "interpolationSearch(items, 14) → "
         << interpolationSearch(items, 14) << endl;
    cout << "interpolationSearch(items, 5) → " << interpolationSearch(items, 5)
         << endl;
    return 0;
}