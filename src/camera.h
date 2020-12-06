#include <cmath>
#include <stdlib.h>
#ifndef CAMERA_INCLUDED
#define CAMERA_INCLUDED
#include"Vec3.h"
using std::vector;
#include <vector>

struct Camera{
  Vec3 eye,forward,up,right;
  float a;  // Constructor
  Camera (Vec3 eye_=Vec3(0,0,0), Vec3 forward_=Vec3(0,0,1), Vec3 up_=Vec3(0,1,0), float a_=45) : eye(eye_), forward(forward_), up(up_), a(a_) {}
	// Set]
  void Set (Vec3 eye_, Vec3 forward_, Vec3 up_, float a_) { eye=eye_; forward=forward_; up=up_; a=a_; }
};

#endif
