#include <iostream>
#include <random>
#include <chrono>

int main() {
    std::mt19937 rng(42);
    std::uniform_int_distribution<int> dist(-1000, 1000);
    int n = 1000000;

    auto start = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < n; i++) {
        int a = dist(rng);
        int b = dist(rng);
        volatile int min = std::min(a, b);
        volatile int max = std::max(a, b);
        (void)min; (void)max;
    }
    auto end = std::chrono::high_resolution_clock::now();
    double time_spent = std::chrono::duration<double>(end - start).count();

    std::cout << "std::min/max (int) | time: " << time_spent << " s\n";
    return 0;
}
