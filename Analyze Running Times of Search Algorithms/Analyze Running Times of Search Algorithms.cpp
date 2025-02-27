#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int recursiveBinarySearch(const vector<int>& vec, int left, int right, int target) {
    if (left > right) return -1;
    int mid = left + (right - left) / 2;
    if (vec[mid] == target) return mid;
    else if (vec[mid] > target) return recursiveBinarySearch(vec, left, mid - 1, target);
    else return recursiveBinarySearch(vec, mid + 1, right, target);
}

int iterativeBinarySearch(const vector<int>& vec, int target) {
    int left = 0, right = vec.size() - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (vec[mid] == target) return mid;
        else if (vec[mid] < target) left = mid + 1;
        else right = mid - 1;
    }
    return -1;
}

int sequentialSearch(const vector<int>& vec, int target) {
    for (size_t i = 0; i < vec.size(); ++i) {
        if (vec[i] == target) return i;
    }
    return -1;
}

int main() {
    vector<int> data = { 34, 7, 23, 32, 5, 62, 32, 13 };
    sort(data.begin(), data.end());

    int target1 = 23; 
    int target2 = 99; 

    int index = recursiveBinarySearch(data, 0, data.size() - 1, target1);
    cout << "Recursive Binary Search: " << target1 << " found at location " << index << endl;
    index = recursiveBinarySearch(data, 0, data.size() - 1, target2);
    cout << "Recursive Binary Search: " << target2 << " was not found, return value is " << index << endl;

    index = iterativeBinarySearch(data, target1);
    cout << "Iterative Binary Search: " << target1 << " found at location " << index << endl;
    index = iterativeBinarySearch(data, target2);
    cout << "Iterative Binary Search: " << target2 << " was not found, return value is " << index << endl;

    index = sequentialSearch(data, target1);
    cout << "Sequential Search: " << target1 << " found at location " << index << endl;
    index = sequentialSearch(data, target2);
    cout << "Sequential Search: " << target2 << " was not found, return value is " << index << endl;

    return 0;
}
