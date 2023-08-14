#pragma once

#include <vector>
#include <random>
#include <tuple>
#include <algorithm>

template <typename T>
std::tuple<std::vector<T>, std::vector<T>, std::vector<int>, std::vector<int>> train_test_split(const std::vector<T> data, const std::vector<int> labels, double test_size = 0.25, int random_state = 0) {
  std::vector<T> train_data, test_data;
  std::vector<int> train_labels, test_labels;
  std::vector<int> indices(data.size());
  for (int i = 0; i < data.size(); i++) {
    indices[i] = i;
  }
  std::shuffle(indices.begin(), indices.end(), std::mt19937(random_state));
  int test_size_int = data.size() * test_size;
  for (int i = 0; i < data.size(); i++) {
    if (i < test_size_int) {
      test_data.push_back(data[indices[i]]);
      test_labels.push_back(labels[indices[i]]);
    } else {
      train_data.push_back(data[indices[i]]);
      train_labels.push_back(labels[indices[i]]);
    }
  }
  return std::make_tuple(train_data, test_data, train_labels, test_labels);
}
