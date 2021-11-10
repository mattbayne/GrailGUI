#include "CAD/Circle.hh"
#include <cmath>

using namespace std;

void Circle::compute(){
  n = points[1].normalized();
  u = points[0].cross(n);
  u.normalized();
  v = u.cross(n);
  v.normalized();
}

std::vector getPoint(double step){
  double t = M_PI * 2 * step;
  this.compute();
  return points[0].added(u.mult(radius*cos(t))).added(v.mult(radius*sin(t)));
}

void Circle::getTangent(double step){
  double t = PI * 2* step;
  return u.mult(-radius*sin(t)).added(v.mult(radius*cos(t)));
}

//make a test file with cases for circle
