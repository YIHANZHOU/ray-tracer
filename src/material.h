#include <cmath>
#include <stdlib.h>
#ifndef MATERIAL_INCLUDED
#define MATERIAL_INCLUDED
#include "Vec3.h"
#include "pixel.h"
#include <vector>

using std::vector;

struct Material{

	float ar; // diffuse red
	float ab; // diffuse blue
	float ag; // diffuse green
  float dr; // diffuse red
  float db; // diffuse blue
  float dg; // diffuse green
  float sr; // specular red
  float sb; // specular blue
  float sg;
  float tr; // specular red
  float tb; // specular blue
  float tg;
  float ns;
  float ior;
  // specular green

   // Constructor                                                                         Pixel ambient_=Pixel(0,0,0),Pixel diffuse_=Pixel(1,1,1), Pixel specular_ =Pixel(0,0,0),Pixel transmissive_=Pixel(0,0,0), float ns=5,float ior=1
  // Material (Pixel ambient_=Pixel(0,0,0), Pixel diffuse_=Pixel(1,1,1), Pixel specular_ =Pixel(0,0,0),Pixel transmissive_=Pixel(0,0,0), float ns_=5,float ior_=1) :
  // ambient(ambient_), diffuse(diffuse_), specular(specular_), transmissive(transmissive_),ns(ns_),ior(ior_) {}
	// Set]
  Material(float ar_=0,float ag_=0,float ab_=0,float dr_=1,float dg_=1,float db_=1,float sr_=0,float sg_=0,float sb_=0,float tr_=0,float tg_=0,float tb_=0,float ns_=5,float ior_=1):
  ar(ar_),ag(ag_),ab(ab_),dr(dr_),dg(dg_),db(db_),sr(sr_),sg(sg_),sb(sb_),tr(tr_),tg(tg_),tb(tb_),ns(ns_),ior(ior_){}
  void Setmaterial(float ar_,float ag_,float ab_,float dr_,float dg_,float db_,float sr_,float sg_,float sb_,float tr_,float tg_,float tb_,float ns_,float ior_) {
    ar=ar_;ag=ag_;ab=ab_;dr=dr_;dg=dg_;db=db_;sr=sr_;sg=sg_;sb=sb_;tr=tr_;tg=tg_;tb=tb_;ns=ns_;ior=ior_;}
    // void Set (Pixel ambient_,Pixel diffuse_, Pixel specular_,Pixel transmissive_) {
    //   ambient=ambient_;diffuse=diffuse_; specular=specular_;transmissive=transmissive_;}
	// Set] }
};

#endif
