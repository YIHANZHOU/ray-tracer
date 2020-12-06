#include "sphere.h"
#include <stdint.h>
#include "Vec3.h"
#include<vector>
using std::vector;


float Sphere::raySphereIntersect(Vec3 eye,Vec3 raydir){
	Vec3 spherePos=this->position;
	float sphereRadius=this->radius;
	Vec3 p=eye-spherePos;
	raydir.normalize();
	double determint=dot(p,raydir)*dot(p,raydir)-(dot(p,p)-sphereRadius*sphereRadius);
	if (determint>0){
	  float x1=-sqrt(determint)-dot(p,raydir);
		float x2=+sqrt(determint)-dot(p,raydir);
		if(x1>=0 && x2>=0){
			return x1;
		}
		else if(x2>=0 && x1<0){
			return x2;
		}
}
return -1;
}