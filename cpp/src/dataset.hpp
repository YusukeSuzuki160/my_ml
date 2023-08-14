#pragma once
#include <vector>
#include "point.hpp"

std::vector<Point<double>> make_wave(int n_samples);
std::vector<int> make_labels(int n_samples, int n_classes);

