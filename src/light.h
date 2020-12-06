#pragma once

#include <cmath>
#include <cstddef>
#include "Vec3.h"
#include <cstdio>
#include <vector>
#include "pixel.h"
#include "sphere.h"
// for testing
#include <iostream>
using namespace std;


using std::vector;

class Light{
public:
  float r,g,b,x,y,z;
  Light(){
  r=g=b=0;
	x=y=z=0;
  }
  Light(float r_,float g_,float b_,float x_,float y_,float z_){
  r=r_;
	g=g_;
	b=b_;
	x=x_;
	y=y_;
	z=z_;
  }
  virtual ~Light(){};
  virtual Vec3 getL(Vec3 intersectionPoint){
    return Vec3(0,0,0);
  }
  virtual float getintensity(Vec3 intersectionPoint){
    return 1;
  }
};

// struct Directionlight{
//
// 	float r; // diffuse red
// 	float g; // diffuse blue
// 	float b; // diffuse green
//   float x; // diffuse red
//   float y; // diffuse blue
//   float z; // diffuse green
//
//   Directionlight(float r_,float g_,float b_,float x_,float y_,float z_):
//   r(r_),g(g_),b(b_),x(x_),y(y_),z(z_){}
//   void Setsdirect(float r_,float g_,float b_,float x_,float y_,float z_) {
//     r=r_;g=g_;b=b_;x=x_;y=y_;z=z_;}
//     // void Set (Pixel ambient_,Pixel diffuse_, Pixel specular_,Pixel transmissive_) {
//     //   ambient=ambient_;diffuse=diffuse_; specular=specular_;transmissive=transmissive_;}
// 	// Set] }
// };
// struct Pointlight{
//
// 	float r; // diffuse red
// 	float g; // diffuse blue
// 	float b; // diffuse green
//   float x; // diffuse red
//   float y; // diffuse blue
//   float z; // diffuse green
//
//   Pointlight(float r_,float g_,float b_,float x_,float y_,float z_):
//   r(r_),g(g_),b(b_),x(x_),y(y_),z(z_){}
//   void Setpoint(float r_,float g_,float b_,float x_,float y_,float z_) {
//     r=r_;g=g_;b=b_;x=x_;y=y_;z=z_;}
//     // void Set (Pixel ambient_,Pixel diffuse_, Pixel specular_,Pixel transmissive_) {
//     //   ambient=ambient_;diffuse=diffuse_; specular=specular_;transmissive=transmissive_;}
// 	// Set] }
// };
// struct mbientlight{
//
// 	float r; // diffuse red
// 	float g; // diffuse blue
// 	float b; // diffuse green
//
//   ambientlight(float r_=0,float g_=0,float b_=0):
//   r(r_),g(g_),b(b_){}
//   void Setambient(float r_,float g_,float b_) {
//     r=r_;g=g_;b=b_;}
//     // void Set (Pixel ambient_,Pixel diffuse_, Pixel specular_,Pixel transmissive_) {
//     //   ambient=ambient_;diffuse=diffuse_; specular=specular_;transmissive=transmissive_;}
// 	// Set] }
// };
