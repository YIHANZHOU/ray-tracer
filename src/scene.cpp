
#include "sphere.h"
#include "Vec3.h"
#include <cstdio>
#include <vector>
#include <cstring>
#include "light.h"
#include "scene.h"
#include <cmath>
#include <algorithm>
#include "pixel.h"
#include "spotlight.h"
#include "pointlight.h"
#include "directionlight.h"



// for testing
#include <iostream>
using namespace std;
using std::vector;
using std::max;

Intersct Scene::raySphereIntersect(Vec3 eye,Vec3 raydir){
  float t=-1;
  int index=0;
  for (int i=0;i<spheres.size();i++)
  {
     float min=spheres[i].raySphereIntersect(eye,raydir);
     if(min<0){
       continue;
     }
     else if(min>0>t){
       t=min;
       index=i;
     }
     else if(t>min>0){
       t=min;
       index=i;
     }
}
   Intersct s;
   s.hit=t;
   s.index=index;
    return s;
}

// int Scene::Intersect(Vec3 eye,Vec3 raydir){
//   float t=-1;
//   int index=0;
//   for (int i=0;i<spheres.size();i++)
//   {
//      float min=spheres[i].raySphereIntersect(eye,raydir);
//      if(min<0){
//        continue;
//      }
//      else if(min>0>t){
//        t=min;
//        index=i;
//      }
//      else if(t>min>0){
//        t=min;
//        index=i;
//      }
//     }
//     return index;
//     }



Pixel Scene::EvaluateRayTree(Vec3 eye,Vec3 raydir){
  Intersct hit_t=raySphereIntersect(eye,raydir);
 // printf("hit_t%f",hit_t.hit);
 // printf("hit_t%d",hit_t.index);

  if(hit_t.hit>0){
    return  raySphereIntersectcolor(eye,raydir,hit_t.index,hit_t.hit);
  }
  else{
    Pixel p;
    p.SetClamp(background_r,background_g,background_b);
    return p;
  }

}


Pixel Scene::raySphereIntersectcolor(Vec3 eye,Vec3 raydir,int index,float t){
   //printf("index%d", lights.size());
   Pixel temp2;
   Material m=spheres[index].m;//
   float r,g,b;
   r=m.ar*255*ambient_r;
   g=m.ag*255*ambient_g;
   b=m.ab*255*ambient_b;
   //printf("ambient r%f g%f b%g",ambient_r,ambient_g,ambient_g);
   Vec3 intersectionPoint=eye+raydir*t;
  // printf("intersectionPoint x%f y%f z%g",intersectionPoint.m_x, intersectionPoint.m_y, intersectionPoint.m_z);

   temp2.SetClamp(double(r),double(g),double(b));

   for (int i=0;i<lights.size();i++){
    if(isshadow(intersectionPoint,*lights[i])<0){
       //from intersection point to the light direction
	   Vec3 L = Vec3(lights[i]->x, lights[i]->y, lights[i]->z) - intersectionPoint;
	   L.normalize();
       Vec3 N=intersectionPoint-spheres[index].position;
       N.normalize();
       Vec3 V=raydir*(-1);
       Vec3 H=L+V;
       H.normalize();
       float r2,g2,b2;
       float intensity=lights[i]->getintensity(intersectionPoint);
       r2=lights[i]->r*intensity;
       g2=lights[i]->g*intensity;
       b2=lights[i]->b*intensity;  
	   //printf("ambient r%f g%f b%g", r2, g2, b2);

       float max = std::max(dot(N, L), 0.0f);
      // printf("r2%fg2%fb2%fmax%f",m.dr,m.dg,m.db,max);
       r=r+r2*m.dr*max;
       g=g+g2*m.dg*max;
       b=b+b2*m.db*max;
       //printf("r%fg%fb%f",r,g,b);
     }}

   temp2.SetClamp(double(r),double(g),double(b));

  //printf("temp2%hhu",temp2.r);
  return temp2;

}


int Scene::isshadow(Vec3 intersectionPoint,Light l)
{
  int shadow=-1;
  Vec3 pos=Vec3(l.x,l.y,l.z);
  //Vec3 pos=Vec3(0,5,0);
  Vec3 L=pos-intersectionPoint;
  

  L.normalize();
  float lightDistance = (Vec3(l.x, l.y, l.z) - intersectionPoint).length();
  for (int i=0;i<spheres.size();i++){
    float hit=spheres[i].raySphereIntersect(intersectionPoint+L*0.01,L);
    if(hit>=0.001 && hit<lightDistance){
      //printf("hit%f",hit);
      shadow=shadow+2;
	  break;
    }
  }
    return shadow;

}
/*the refract array*/
Vec3 Scene::refract(Vec3 intersectionPoint,Light l,int index)
{
  Vec3 N=intersectionPoint-spheres[index].radius;
  Vec3 L=l.getL(intersectionPoint);

    return N;

}
Vec3 Scene::reflect(Vec3 intersectionPoint,Light l,int index)
{
  Vec3 N=intersectionPoint-spheres[index].radius;
  Vec3 L=l.getL(intersectionPoint);

    return N;

}
