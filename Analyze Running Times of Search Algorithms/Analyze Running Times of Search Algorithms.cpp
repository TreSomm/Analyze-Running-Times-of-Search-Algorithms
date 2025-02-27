#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <ctime>

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
    srand(time(0));
    vector<int> data;
    for (int i = 0; i < 10; ++i) {
        data.push_back(rand() % 100 + 1);
    }
    sort(data.begin(), data.end());

    int target = data[rand() % data.size()]; 

    cout << "Vector contents: ";
    for (int num : data) {
        cout << num << " ";
    }
    cout << endl;

    int index = recursiveBinarySearch(data, 0, data.size() - 1, target);
    if (index >= 0)
        cout << "Recursive Binary Search: " << target << " found at location " << index << endl;
    else
        cout << "Recursive Binary Search: " << target << " was not found" << endl;

    index = iterativeBinarySearch(data, target);
    if (index >= 0)
        cout << "Iterative Binary Search: " << target << " found at location " << index << endl;
    else
        cout << "Iterative Binary Search: " << target << " was not found" << endl;

    index = sequentialSearch(data, target);
    if (index >= 0)
        cout << "Sequential Search: " << target << " found at location " << index << endl;
    else
        cout << "Sequential Search: " << target << " was not found" << endl;

    return 0;
}
