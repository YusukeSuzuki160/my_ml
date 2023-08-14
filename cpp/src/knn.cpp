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
};

int main() {
  std::vector<Point<double>> points;
  std::vector<int> labels;
  points.push_back(Point<double>(1.0, 1.0));
  points.push_back(Point<double>(2.0, 2.0));
  points.push_back(Point<double>(3.0, 3.0));
  points.push_back(Point<double>(4.0, 4.0));
  points.push_back(Point<double>(5.0, 5.0));
  labels.push_back(1);
  labels.push_back(1);
  labels.push_back(1);
  labels.push_back(2);
  labels.push_back(2);
  KNN knn(3, points, labels);
  Point<double> p(1.5, 1.5);
  std::cout << knn.predict(p) << std::endl;
  return 0;
}
