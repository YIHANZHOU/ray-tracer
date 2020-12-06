#pragma once
#include "pixel.h"
#include  <vector>
#include "Vec3.h"
#include "light.h"

using std::vector;
class DirectionLight:public Light{
public:
  Vec3 dir;
  DirectionLight(float r_, float g_, float b_,float x_, float y_, float z_):Light(r_,g_,b_,x_,y_,z_){
    dir=Vec3(x_,y_,z_);
    dir.normalize();
  }
  ~DirectionLight(){};
   Vec3 getL(Vec3 intersectionPoint){
     return dir*(-1);
   };
   float getintensity(Vec3 intersectionPoint){
     return 1;
   }

};
