#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <chrono>

int main() {
    std::vector<int> array(1000);
    for (int i = 0; i < 1000; i++) array[i] = i;
    std::mt19937 rng(42);
    int sample_sizes[] = {10000, 100000, 1000000};

    for (int s = 0; s < 3; s++) {
        int count = sample_sizes[s];
        auto start = std::chrono::high_resolution_clock::now();
        for (int i = 0; i < count; i++) {
            int result = 0;
            std::sample(array.begin(), array.end(), &result, 1, rng);
            volatile int dummy = result;
            (void)dummy;
        }
        auto end = std::chrono::high_resolution_clock::now();
        double time_spent = std::chrono::duration<double>(end - start).count();
        std::cout << "std::sample | samples: " << count << " | time: " << time_spent << " s\n";
    }
    return 0;
}
