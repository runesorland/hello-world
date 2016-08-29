#include<iostream>
#include<eigen3/Eigen/Core>
#include<vector>
#include<fstream>

#include "sphere.h"

int main(int argc, char const *argv[]) {
  Eigen::Vector3d posatom1(.5,.5,0);
  double radius1 = 1;
  Sphere atom1(posatom1, radius1);
  Eigen::Vector3d posatom2(.5,-.5,0);
  double radius2 = 1;
  Sphere atom2(posatom2,radius2);
  Eigen::Vector3d posatom3(-.5,-.5,0);
  double radius3 = 1;
  Sphere atom3(posatom3,radius3);
  Eigen::Vector3d posatom4(-.5,.5,0);
  double radius4 = 1;
  Sphere atom4(posatom4,radius4);


//  Sphere atomS;

  ///Sphere atom3(atom1);

  std::vector<Sphere> sphere_list;
  //sphere_list.push_back(atomS);
  sphere_list.push_back(atom1);
  sphere_list.push_back(atom2);
  sphere_list.push_back(atom3);
  sphere_list.push_back(atom4);


  ///////print to file plottable///
  std::ofstream myfile;
  myfile.open ("plottable.plt");
  for(int i = 0; i < sphere_list.size(); i=i+1){
    myfile << sphere_list[i];
  }
  myfile.close();


  return 0;
}
