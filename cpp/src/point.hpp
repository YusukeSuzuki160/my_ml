#pragma once

template <typename T>
class Point {
  public:
    Point(T x, T y) : _x(x), _y(y) {}
    T x() const { return _x; };
    T y() const { return _y; };
    void print() const { std::cout << "(" << _x << ", " << _y << ")" << std::endl; }
  double distance(const Point<T>& p1, const Point<T>& p2) const {
    return sqrt(pow(p1.x() - p2.x(), 2) + pow(p1.y() - p2.y(), 2));
  }
  private:
    T _x;
    T _y;
};
