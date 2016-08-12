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
    static int i = 0;
    if (i++ == 0) {
    output<< "set output \"sphere_plot.ps\"" << std::endl
          << "set parametric" << std::endl
          << "set angle radian" << std::endl
          << "set urange [0:2*pi]" << std::endl
          << "set vrange [0:2*pi]" << std::endl
          << "set isosample 40,40" << std::endl
          << "set ticslevel 0"  << std::endl
          << "set size 1.0,1.0" << std::endl << "splot ";
      }
      else{
        output << ",";
      }
      output<< sph.radius << "*cos(u)*cos(v) +"<<sph.center(0)
            << "," << sph.radius <<"*sin(u)*cos(v)+" << sph.center(1)
            << "," << sph.radius <<"*sin(v)+" << sph.center(2);



    return output;
  }
};
#endif
