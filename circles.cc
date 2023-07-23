#include <iostream>
#include <cmath>

struct Point {
  double x, y;
};

void move(Point& p1, const Point& p2) {
  p1.x += p2.x;
  p1.y += p2.y;
}

struct Circle {
  Point center;
  double radius;
};

void scale(Circle& c, double sca) {
  c.radius *= sca;
}

void move(Circle& c, const Point& p) {
  move(c.center, p);
}

bool is_inside(const Point& p, const Circle& c) {
  double dx = p.x - c.center.x;
  double dy = p.y - c.center.y;
  return dx * dx + dy * dy < c.radius * c.radius;
}