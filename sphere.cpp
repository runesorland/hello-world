#include<iostream>
#include<eigen3/Eigen/Core>
#include<vector>
#include<fstream>
//#include<plot.hpp>


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

//default constructor
Sphere::Sphere(){
  center = Eigen::Vector3d(0,0,0);
  radius  = 10;
}
//"input" constructor
Sphere::Sphere  (const Eigen::Vector3d &a  , double b){
  center  = a;
  radius  = b;
}
//copy constructor
Sphere::Sphere (const Sphere & sph){
  center = sph.center;
  radius = sph.radius;
}


int main(int argc, char const *argv[]) {
  Eigen::Vector3d posatom1(1,2.2,1);
  double radius1 = 12.1;
  Sphere atom1(posatom1, radius1);
  Sphere atom2;

  Sphere atom3(atom1);

  std::vector<Sphere> sphere_list;
  sphere_list.push_back(atom1);
  sphere_list.push_back(atom2);
  sphere_list.push_back(atom3);

  ///////print to file plottable///
  ////run with gnuplot> splot "plottable" u 1:2:3:4 ps variable pt 7
  std::ofstream myfile;
  myfile.open ("plottable");
  for(int i = 0; i < sphere_list.size(); i=i+1){
    myfile << sphere_list[i] << std::endl;
  }
  myfile.close();

  return 0;
}
