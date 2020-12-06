#pragma once
#include "pixel.h"
#include  <vector>
#include "Vec3.h"
#include "light.h"

using std::vector;
class Pointlight:public Light{
public:
  Vec3 pos;
  Pointlight(float r_, float g_, float b_,float x_, float y_, float z_):Light(r_,g_,b_,x_,y_,z_){};
   ~Pointlight(){};
  Vec3 getL(Vec3 intersectionPoint){
    Vec3 temp=pos-intersectionPoint;
    temp.normalize();
   return temp;
  }
  float getintensity(Vec3 intersectionPoint){
  Vec3 pos = Vec3(x, y, z);
  Vec3 temp=pos-intersectionPoint;
  return 1/dot(temp,temp);
    
  }
  Vec3 getpos(){
  Vec3 temp=Vec3(x,y,z);
  return temp;
}
};

