#pragma once

#include "opengl/Shape2D.hh"

class Gear : public Shape2D{
private:
  float x, y, radius;
  uint32_t numOfTriangles;
  uint32_t numOfverticies = numOfTriangles + 2;
  float *circleVerts = new float;
  
public:
  Gear(Canvas* c, float x,float y, float rad, uint32_t numOfTriangles, const Style* s); 

  void init();
  void render();
  void drawGear();

};
