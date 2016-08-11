#ifndef SPHERE_H_
#define SPHERE_H_
#include<iostream>
#include<eigen3/Eigen/Core>
#include<vector>
#include<fstream>
class Sphere{
  private:
    Eigen::Vector3d center;
    double radius;
  public:
    Sphere  ();
    Sphere  (const Eigen::Vector3d &a , double b) ; // const og & når du har lært det!!!!
    Sphere (const Sphere & sph ); //copy constructor,,,,les deg opp!!!
    //Sphere& operator=(const Sphere &sph);//se nermere på, overloading.
  Eigen::Vector3d get_center() const {
    return center;
  }
  double get_radius () const {
    return radius;
  }
  //making the output plottable for gnuplot
  friend std::ostream & operator<<( std::ostream & output, const Sphere & sph){
    output  <<  sph.center(0) << " " << sph.center(1) << " " << sph.center(2) << " " <<  sph.radius ;
    return output;
  }
};
#endif
