#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <float.h>
#include"Vec3.h"
#include"material.h"
#include <vector>
#ifndef SPHERE_INCLUDED
#define SPHERE_INCLUDED
using std::vector;

struct Sphere{
	Vec3 position;
	float radius;
	Material m;
    Sphere (Vec3 position_=Vec3(0,0,0),float radius_=0,Material m_=Material()):position(position_),radius(radius_),m(m_){}
	float raySphereIntersect(Vec3 eye,Vec3 raydir);
	void Set (Vec3  position_, float radius_, Material m_) { position=position_; radius=radius_; m=m_; }
	// Set

};
#endif
