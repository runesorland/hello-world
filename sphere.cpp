#include<iostream>
#include<eigen3/Eigen/Core>
#include<vector>
#include<fstream>

#include"sphere.h"

//default constructor
Sphere::Sphere(){
  center = Eigen::Vector3d(0,0,0);
  radius  = 10;
}
//"input" constructor
Sphere::Sphere(const Eigen::Vector3d &c  , double r){
  center  = c;
  radius  = r;
}
//copy constructor
Sphere::Sphere (const Sphere & sph){
  center = sph.center;
  radius = sph.radius;
}
