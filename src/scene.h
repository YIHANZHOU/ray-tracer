#pragma once

#include "sphere.h"
#include "light.h"
#include "Vec3.h"
#include <cstdio>
#include <vector>
#include <cstring>
#include "pixel.h"
#include <iostream>
using namespace std;
using std::vector;
struct Intersct
{
    // Data
    float hit;
    int index;
    // Constructor
};
class Scene{
public:
  vector<Sphere>spheres;
  vector<Light*>lights;
   //int count=0;
   float ambient_r;
   float ambient_g;
   float ambient_b;
   float background_r;
   float background_g;
   float background_b;
   int max_depth;
   Scene(float ar=0,float ag=0,float ab=0,float br=0,float bg=0,float bb=0):ambient_r(ar),ambient_g(ag),ambient_b(ab),background_r(br),background_g(bg),background_b(bb){};
  Pixel raySphereIntersectcolor(Vec3 eye,Vec3 raydir,int index,float t);
  Pixel EvaluateRayTree(Vec3 eye,Vec3 raydir);
  Intersct raySphereIntersect(Vec3 eye,Vec3 raydir);
  int isshadow(Vec3 intersectionPoint,Light l);
  Vec3 reflect(Vec3 intersectionPoint,Light l,int index);
  Vec3 refract(Vec3 intersectionPoint,Light l,int index);

  //vector<light*>light;
};
