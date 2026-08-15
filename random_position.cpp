#include <iostream>
#include <random>
#include <chrono>

struct Position { double x, y; };

int main() {
    std::mt19937 rng(42);
    std::uniform_real_distribution<double> dist(-1000.0, 1000.0);
    int n = 1000000;

    auto start = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < n; i++) {
        Position pos;
        pos.x = dist(rng);
        pos.y = dist(rng);
        volatile double dummy_x = pos.x;
        volatile double dummy_y = pos.y;
        (void)dummy_x; (void)dummy_y;
    }
    auto end = std::chrono::high_resolution_clock::now();
    double time_spent = std::chrono::duration<double>(end - start).count();

    std::cout << "random position (C++) | time: " << time_spent << " s\n";
    return 0;
}