#include <iostream>
#include <vector>
#include <numeric>
#include <chrono>

int main() {
    std::vector<long> arr(1000000);
    for (int i = 0; i < 1000000; i++) arr[i] = i;

    auto start = std::chrono::high_resolution_clock::now();
    long sum = std::accumulate(arr.begin(), arr.end(), 0L);
    auto end = std::chrono::high_resolution_clock::now();
    double time_spent = std::chrono::duration<double>(end - start).count();

    std::cout << "std::accumulate (long) | sum: " << sum << " | time: " << time_spent << " s\n";
    return 0;
}
