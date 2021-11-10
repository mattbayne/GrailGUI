#pragma once
#include "opengl/GrailGUI.hh"
#include "src/CAD/Curve.hh"
#include "src/CAD/Vec3d.hh"

//using namespace std;

/**
Represent -- 
**/
class Circle extends Curve {
  private:
    double radius;
    Vec3D v, u, n; //rename these, and vector or vec3d?
    //when do they set the center of the circle points[0] or the normal vector? points[1]
    //n = unit vector perpendicular to the plane
    //u = orthogonal vector to the normal or unit vector from center to point on circumference?
    //v = center point in 3d space?
    //https://math.stackexchange.com/questions/2724389/how-do-i-find-a-circle-from-a-center-point-and-a-point-defining-a-normal-through

    public:
      Circle(double radius) {
        this.radius = radius;
      }
    
    double getRadius() const {return radius;}
    void compute();
    Vec3D getPoint(double step);
    Vec3D getTangent(double step);

}