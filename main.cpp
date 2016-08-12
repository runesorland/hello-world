#include<iostream>
#include<eigen3/Eigen/Core>
#include<vector>
#include<fstream>

#include "sphere.h"

int main(int argc, char const *argv[]) {
  Eigen::Vector3d posatom1(.5,.5,.5);
  double radius1 = 1;
  Sphere atom1(posatom1, radius1);
  Sphere atom2;

  ///Sphere atom3(atom1);

  std::vector<Sphere> sphere_list;
  sphere_list.push_back(atom1);
  sphere_list.push_back(atom2);
  //sphere_list.push_back(atom3);

  ///////print to file plottable///
  ////run with gnuplot> splot "plottable" u 1:2:3:4 ps variable pt 7
  std::ofstream myfile;
  myfile.open ("plottable.plt");
  for(int i = 0; i < sphere_list.size(); i=i+1){
    myfile << sphere_list[i];
  }
  myfile.close();

  return 0;
}
