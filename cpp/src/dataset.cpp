#include "dataset.hpp"
#include <iostream>
#include <random>
#include <vector>
#include <cmath>
#include "point.hpp"

std::vector<Point<double>> make_wave(int n_samples=100) {
  std::random_device rd;
  std::mt19937 gen(rd());
  std::uniform_real_distribution<> dis(-3, 3);
  std::normal_distribution<> dis_norm(0, 1);

  std::vector<Point<double>> wavedata;

  for (int i = 0; i < n_samples; i++) {
    double x_val = dis(gen);
    double y_no_noise = std::sin(4 * x_val) + x_val;
    double y_val = (y_no_noise + dis_norm(gen)) / 2;
    wavedata.push_back(Point(x_val, y_val));
  }
  return wavedata;
}

