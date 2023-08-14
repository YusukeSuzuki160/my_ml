#include "point.hpp"
#include "dataset.hpp"
#include "split.hpp"
#include <vector>
#include <iostream>
#include <algorithm>

class KNN {
  public:
    int k;
    std::vector<Point<double>> points;
    std::vector<int> labels;
    KNN(int k, std::vector<Point<double>> points, std::vector<int> labels) {
      this->k = k;
      this->points = points;
      this->labels = labels;
    }
    std::vector<int> sort_indices(std::vector<double> v) {
      std::vector<int> indices(v.size());
      for (int i = 0; i < v.size(); i++) {
        indices[i] = i;
      }
      std::sort(indices.begin(), indices.end(), [&v](int i1, int i2) {return v[i1] < v[i2];});
      return indices;
    }
    int predict(Point<double> p) {
      std::vector<double> distances;
      for (int i = 0; i < points.size(); i++) {
        distances.push_back(Point<double>::distance(p, points[i]));
      }
      std::vector<int> indices = sort_indices(distances);
      std::vector<int> k_indices(indices.begin(), indices.begin() + k);
      std::vector<int> k_labels;
      for (int i = 0; i < k_indices.size(); i++) {
        k_labels.push_back(labels[k_indices[i]]);
      }
      int max_label = 0;
      int max_count = 0;
      for (int i = 0; i < k_labels.size(); i++) {
        int count = 0;
        for (int j = 0; j < k_labels.size(); j++) {
          if (k_labels[i] == k_labels[j]) {
            count++;
          }
        }
        if (count > max_count) {
          max_count = count;
          max_label = k_labels[i];
        }
      }
      return max_label;
    } 
    double score(std::vector<Point<double>> test_points, std::vector<int> test_labels) {
      int correct = 0;
      for (int i = 0; i < test_points.size(); i++) {
        if (predict(test_points[i]) == test_labels[i]) {
          correct++;
        }
      }
      return (double) correct / test_points.size();
    }
};

int main() {
  std::vector<Point<double>> points = make_wave(100);
  std::vector<int> labels = make_labels(100, 2);
  std::vector<Point<double>> train_points, test_points;
  std::vector<int> train_labels, test_labels;
  std::tie(train_points, test_points, train_labels, test_labels) = train_test_split(points, labels);
  KNN knn(3, train_points, train_labels);
  std::cout << knn.score(test_points, test_labels) << std::endl;
}
