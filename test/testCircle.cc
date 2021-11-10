#include "CAD/Circle.cc"
#include "iostream"
#include "CAD/Vec3d.hh"
using namespace std;


int main() {
 // Circle test();
  Curve test = new Circle(5);
  cout << test << endl;
  cout << test.getRadius() << endl;
  cout << test.compute() << endl;
  cout << test.getPoint() << endl;
    cout << test.getTangent() << endl;

}

//class TestCircle : public GLWin {