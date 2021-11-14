#include "CAD/Circle.hh"
#include "iostream"
#include "CAD/Vec3d.hh"
using namespace std;


int main() {
 // Circle test();
  Circle test(5);
  Vec3D v1(1,2,3);
  Vec3D v2(3,4,5);
  Vec3D v3(5,6,7);

  test.add(v1);  
  // test.add(v2);
 // test.add(v3);

  //cout << test << endl;
  cout << test.getRadius() << endl;
  //cout << test.compute() << endl;
  cout << test.getPoint(0.02) << endl;
    cout << test.getTangent(0.02) << endl;

}

//class TestCircle : public GLWin {