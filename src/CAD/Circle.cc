#define _USE_MATH_DEFINES
#include "CAD/Circle.hh"
#include <cmath>

using namespace std;
//normalize never did anything (value was not stored)
void Circle::compute(){
  n = points[1].normalized();
  u = points[0].cross(n);
  //u.normalized();
  v = u.cross(n);
  //v.normalized();

}

Vec3D Circle::getPoint(double step){
  double t = M_PI * 2 * step;
  this->compute();
  return points[0]+(u*(radius*cos(t)))+(v*(radius*sin(t)));
}

Vec3D Circle::getTangent(double step){
  double t = M_PI * 2* step;
  return u*(-radius*sin(t))+(v*(radius*cos(t)));
}

//make a test file with cases for circle
