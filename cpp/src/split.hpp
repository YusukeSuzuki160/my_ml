#pragma once

#include <vector>
#include <random>

template <typename T>
std::vector<T> train_test_split(const std::vector<T>& data, double test_size = 0.2, int random_state = 0) {
    std::vector<T> train, test;
    std::mt19937 gen(random_state);
    std::bernoulli_distribution dist(1.0 - test_size);
    for (const auto& x : data) {
        if (dist(gen)) {
            train.push_back(x);
        } else {
            test.push_back(x);
        }
    }
    return {train, test};
}
