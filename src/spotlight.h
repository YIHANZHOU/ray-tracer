#pragma once
#include <cmath>
#include <stdlib.h>
#include "Vec3.h"
#include "pixel.h"
#include "light.h"
#include <vector>
#include "scene.h"

using std::vector;
class Spotlight:public Light{
public:
  Spotlight(float r_, float g_, float b_,float px, float py, float pz,float dx,float dy,float dz,float angle1,float angle2);
  ~Spotlight();
  float dir_x;
  float dir_y;
  float dir_z;
  Vec3 pos;
  Vec3 dir;
  float angle1;
  float angle2;
  float getintensity(Vec3 intersectionPoint);
  Vec3 getL(Vec3 intersectionPoint);

};






// struct spotlight{
//
// 	float r; // diffuse red
// 	float g; // diffuse blue
// 	float b; // diffuse green
//   float px; // diffuse red
//   float py; // diffuse blue
//   float pz; // diffuse green
//   float dx; // specular red
//   float dy; // specular blue
//   float dz;
//   float angle1; // specular red
//   float angle2; // specular blue
//
//   Material(float r_,float g_,float b_,float px_,float py_,float pz_,float dx_,float dy_,float dz_,float angle1_,float angle2_):
//   r(r_),g(g_),b(b_),px(px_),py(py_),pz(pz_),dx(dx_),dy(dy_),dz(dz_),angle1(angle1_),angle2(angle2_){}
//   void Setspotlight(float r_,float g_,float b_,float px_,float py_,float pz_,float dx_,float dy_,float dz_,float angle1_,float angle2_) {
//     r=r_;g=g_;b=b_;px=px_;py=py_;pz=pz_;dx=dx_;dy=dy_;dz=dz_;angle1=angle_;angle2=angle2}
//     // void Set (Pixel ambient_,Pixel diffuse_, Pixel specular_,Pixel transmissive_) {
//     //   ambient=ambient_;diffuse=diffuse_; specular=specular_;transmissive=transmissive_;}
// 	// Set] }
// };
