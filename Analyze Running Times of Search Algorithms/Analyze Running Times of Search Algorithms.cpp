#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <chrono>

using namespace std;
using namespace std::chrono;

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
    const int N = 1000000;
    double SumRBS = 0, SumIBS = 0, SumSeqS = 0;

    for (int i = 0; i < 10; ++i) {
        vector<int> data;
        srand(time(0) + i); 
        for (int j = 0; j < N; ++j) {
            data.push_back(rand() % 100000 + 1);
        }
        sort(data.begin(), data.end());

        int target = data[rand() % N]; 

        auto start = high_resolution_clock::now();
        recursiveBinarySearch(data, 0, data.size() - 1, target);
        auto end = high_resolution_clock::now();
        SumRBS += duration<double, micro>(end - start).count();

        start = high_resolution_clock::now();
        iterativeBinarySearch(data, target);
        end = high_resolution_clock::now();
        SumIBS += duration<double, micro>(end - start).count();

        start = high_resolution_clock::now();
        sequentialSearch(data, target);
        end = high_resolution_clock::now();
        SumSeqS += duration<double, micro>(end - start).count();
    }

    cout << "Average Running Time for Recursive Binary Search in microseconds is " << SumRBS / 10 << endl;
    cout << "Average Running Time for Iterative Binary Search in microseconds is " << SumIBS / 10 << endl;
    cout << "Average Running Time for Sequential Search in microseconds is " << SumSeqS / 10 << endl;

    return 0;
}
