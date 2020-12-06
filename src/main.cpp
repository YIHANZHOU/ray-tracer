//File parsing example
#include <cstdio>
#include <iostream>
#include <fstream>
#include <string>
#include "image.h"
#include <cassert>
#include <cstdlib>
#include <cstring>
#include <string>
#include "camera.h"
#include "Vec3.h"
#include <vector>
#include "material.h"
#include "sphere.h"
#include "scene.h"
#include "spotlight.h"
#include "directionlight.h"
#include "light.h"
#include "pointlight.h"
#include <list>

using std::vector;



#define STB_IMAGE_IMPLEMENTATION //only place once in one .cpp file
#include "stb_image.h"

#define STB_IMAGE_WRITE_IMPLEMENTATION //only place once in one .cpp files
#include "stb_image_write.h"

using namespace std;

int main(){
  FILE *fp;
  long length;
  char line[1024]; //Assumes no line is longer than 1024 characters!
  int width = 640;
  int height = 480;
  float r,g,b=0;

  Camera c;
  //c.Set(Vec3(px,py,pz),Vec3(dx,dy,dz),Vec3(ux,uy,uz),ha);
  Material m;
  Sphere s;
  Scene sce=Scene();

  vector<Sphere*>spherearray;


  Vec3 spherePos;
  float  sphereRadius=0;


  string fileName = "spheres1.scn";

  // open the file containing the scene description
  fp = fopen(fileName.c_str(), "r");

  // check for errors in opening the file
  if (fp == NULL) {
    printf("Can't open file '%s'\n", fileName.c_str());
	return 0;  //Exit
  }

  // determine the file size (this is optional -- feel free to delete the 4 lines below)
  fseek(fp, 0, SEEK_END); // move position indicator to the end of the file;
  length = ftell(fp);  // return the value of the current position
  printf("File '%s' is %ld bytes long.\n\n",fileName.c_str(),length);
  fseek(fp, 0, SEEK_SET);  // move position indicator to the start of the file

  //Loop through reading each line
  while( fgets(line,1024,fp) ) { //Assumes no line is longer than 1024 characters!
    if (line[0] == '#'){
      printf("Skipping comment: %s", line);
      continue;
    }

    char command[100];
    int fieldsRead = sscanf(line,"%s ",command); //Read first word in the line (i.e., the command type)

    if (fieldsRead < 1){ //No command read
     //Blank line
     continue;
    }

    if (strcmp(command, "sphere")==0){ //If the command is a sphere command
       float x,y,z,r;
       sscanf(line,"sphere %f %f %f %f", &x, &y, &z, &r);
       printf("Sphere as position (%f,%f,%f) with radius %f\n",x,y,z,r);
       spherePos=Vec3(x,y,z);
       sphereRadius=r;
       s.Set(spherePos,sphereRadius,m);
       sce.spheres.push_back(s);
       //sce.addsphere(s);
       //sce.spheres.push_back(s);
      // sce.count=sce.count+1;
       printf("%lu\n",sce.spheres.size());

      // sce.spheres=spherearray;





       //sce.addsphere(new Sphere(spherePos,sphereRadius,m));
       }
      // Pixel ambient=m.ambient;
    //    printf("material as ambient (%f,%f,%f)and diffuse (%f,%f,%f)specular (%f,%f,%f) and transimissive (%f,%f,%f)and ns%f and ior%f \n",
    //    m.ar,m.ag,m.ab,m.dr,m.dg,m.db,
    //    m.sr,m.sg,m.sb,m.tr,m.tg,m.tb,
    //    m.ns,m.ior);
    //
    // }//camera -6 2 -4 .77 0 .64 0 1 0 35
    //material .75 .75 .75 .75 .75 .75 .3 .3 .3 32 .2 .2 .2 1.5

    else if (strcmp(command, "material")==0){
      float ar,ag,ab=0;
      float dr,dg,db=1;
      float sr,sg,sb=0;
      float ns=5;
      float ior=1;
      float tr,tg,tb=0;
      Pixel ambient,diffuse,specular,transmissive;
      sscanf(line,"material %f %f %f %f %f %f %f %f %f %f %f %f %f %f", &ar, &ag, &ab, &dr, &dg, &db, &sr, &sg, &sb, &ns, &tr, &tg, &tb, &ior);
      printf("material as ambient (%f,%f,%f)and diffuse (%f,%f,%f)sspecular (%f,%f,%f) and transimissive (%f,%f,%f) and ns%f andior%f\n",
      ar,ag,ab,dr,dg,db,sr,sg,sb,tr,tg,tb,ns,ior);
      // ambient.SetClamp(ar,ag,ab);
      // diffuse.SetClamp(dr,dg,db);
      // specular.SetClamp(sr,sg,sb);
      // transmissive.SetClamp(tr,tg,tb);
      //printf("material as specular (%f,%f,%f) and transimissive (%f,%f,%f) \n",specular.r,specular.g,specular.b,
    //  transmissive.r,transmissive.g,transmissive.b);
     // printf("material as ambient (%f,%f,%f)and diffuse (%f,%f,%f)sspecular (%f,%f,%f) and transimissive (%f,%f,%f) \n",
     // ambient.r,ambient.g,ambient.b,diffuse.r,diffuse.g,diffuse.b,specular.r,specular.g,specular.b,transmissive.r,transmissive.g,transmissive.b);
      m.Setmaterial(ar,ag,ab,dr,dg,db,sr,sg,sb,tr,tg,tb,ns,ior);
      // printf("material as ambient (%f,%f,%f)and diffuse (%f,%f,%f)specular (%f,%f,%f) and transimissive (%f,%f,%f)and ns%f and ior%f \n",
      // m.ar,m.ag,m.ab,m.dr,m.dg,m.db,
      // m.sr,m.sg,m.sb,m.tr,m.tg,m.tb,
      // m.ns,m.ior);

    }
    //camera
    else if (strcmp(command, "camera")==0){
      float px,py,pz=0;
      float dx,dy=0;
      float dz=1;
      float ux=0,uy=1,uz=0,ha=45;
       //If the command is a material command
       sscanf(line,"camera %f %f %f %f %f %f %f %f %f %f", &px, &py, &pz, &dx,&dy,&dz,&ux,&uy,&uz,&ha);
       printf("camera %f %f %f %f %f %f %f %f %f %f\n", px, py, pz, dx,dy,dz,ux,uy,uz,ha);
       c.Set(Vec3(px,py,pz),Vec3(dx,dy,dz),Vec3(ux,uy,uz),ha);
    }


    else if (strcmp(command, "background")==0){
      //If the command is a background command
       sscanf(line,"background %f %f %f", &r, &g, &b);
       sce.background_r=r*255;
       sce.background_g=g*255;
       sce.background_b=b*255;
    }
    else if (strcmp(command, "output_image")==0){ //If the command is an output_image command
       char outFile[1024];
       sscanf(line,"output_image %s", outFile);
       printf("Render to file named: %s\n", outFile);
    }
    //spot_light 0 .5 0 1 0 1 0 1 2 45 90
    else if (strcmp(command, "spot_light")==0){
      float r,g,b,px,py,pz,dx,dy,dz,angle1,angle2;
       //If the command is an output_image command
       sscanf(line,"spot_light %f %f %f %f %f %f %f %f %f %f %f", &r, &g, &b, &px,&py,&pz,&dx,&dy,&dz,&angle1,&angle2);
       printf("spot_light %f %f %f %f %f %f %f %f %f %f %f\n", r, g, b, px,py,pz,dx,dy,dz,angle1,angle2);
       sce.lights.push_back(new Spotlight(r*255, g*255, b*255, px,py,pz,dx,dy,dz,angle1,angle2));
    }
    //point_light 10 10 10 0 5 0
    else if (strcmp(command, "point_light")==0){
      float r,g,b,x,y,z;
       //If the command is an output_image command
       sscanf(line,"point_light %f %f %f %f %f %f ", &r, &g, &b, &x,&y,&z);
       printf("point_light %f %f %f %f %f %f\n", r, g, b,x,y,z);
       sce.lights.push_back(new Pointlight(r*255,g*255,b*255,x,y,z));
       //printf("x%fy%fz%f",x,y,z);
      // printf("x%fy%fz%f",lights[0]->pos.m_x,lights[0]->pos.m_y,lights[0]->pos.m_z);

    }
    else if (strcmp(command, "directional_light")==0){
      float r,g,b,x,y,z;
       //If the command is an output_image command
       sscanf(line,"directional_light %f %f %f %f %f %f ", &r, &g, &b, &x,&y,&z);
       printf("directional_light %f %f %f %f %f %f\n", r, g, b,x,y,z);
       sce.lights.push_back(new DirectionLight(r*255,g*255,b*255,x,y,z));

    }
    //ambient_light .25 .25 .25
    else if (strcmp(command, "ambient_light")==0){
      float r,g,b;
       //If the command is an output_image command
       sscanf(line,"ambient_light %f %f %f  ", &r, &g, &b);
       printf("ambient_light %f %f %f \n", r,g,b);
       sce.ambient_r=r;
       sce.ambient_g=g;
       sce.ambient_b=b;
    }



	else if (strcmp(command, "film_resolution") == 0) { //If the command is an output_image command
		sscanf(line, "film_\resolution %d%d",&width,&height);

	}
  else if (strcmp(command, "max_depth") == 0) {
    int max_depth; //If the command is an output_image command
    sscanf(line, "max_depth%d",&max_depth);
    printf("max_depth %d \n", max_depth);
    sce.max_depth=max_depth;
  }

    else {
      printf("WARNING. Do not know command: %s\n",command);
    }
  }
  Image picture = Image(width, height);

  //picture.changebackground(r*255,g*255,b*255);
  picture.ConstructrayThroughPixel(c,sce);
  //printf("sphere0 %f \n",sce.spheres[0].radius);
  picture.Write("RATRACY.JPG");
  return 0;
}
