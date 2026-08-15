#include <iostream>
#include <vector>
#include <cmath>
#include <chrono>
#include <cstdlib>

int main() {
    int n = 1000000;
    std::vector<int> int_arr(n);
    std::vector<double> dbl_arr(n);
    for (int i = 0; i < n; i++) {
        int_arr[i] = rand() % 200 - 100;
        dbl_arr[i] = (double)rand() / RAND_MAX * 200 - 100;
    }

    auto start = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < n; i++) {
        volatile int dummy_int = std::abs(int_arr[i]);
        volatile double dummy_dbl = std::abs(dbl_arr[i]);
        (void)dummy_int; (void)dummy_dbl;
    }
    auto end = std::chrono::high_resolution_clock::now();
    double time_spent = std::chrono::duration<double>(end - start).count();

    std::cout << "std::abs (int + double) | time: " << time_spent << " s\n";
    return 0;
}
