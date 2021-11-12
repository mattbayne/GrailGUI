#include "CAD/Curve.cc"
#include "iostream"
#include "CAD/Vec3d.hh"
using namespace std;


int main() {
 // Curve test();
  Curve test;
  cout << test << endl;
  Vec3D p1(1,2,3);
  Vec3D p2(4,5,6);
  //Vec3D p3(7,8,9);
  test.add(p1);
  test.add(p2);
  //test.add(p3);
  cout << test.size() << endl;
  test.resize();
  cout << test.capacity() << endl;
  cout << test << endl;
}

//class TestCurve : public GLWin {