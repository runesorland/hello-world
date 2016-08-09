#include<iostream>
#include<eigen3/Eigen/Core>
#include<vector>


class Sphere{
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

    //input friend, virker ikkje!
    /*
    friend std::istream & operator>>( std::istream  &input, Sphere & sph )
      {
      input >> sph.radius >> sph.center;
      return input;
      }
    */
    friend std::ostream & operator<<( std::ostream & output, const Sphere & sph)
      {
      output << "Radius: " << sph.radius << std::endl << "center: " << std::endl << sph.center;
      return output;
      }
};

//default constructor
Sphere::Sphere(){
  center = Eigen::Vector3d(0,0,0);
  radius  = 0;
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

  //////////////////printing////////////////////
  std::cout << "size of sphere_list:" << sphere_list.size() << std::endl;
  for   (int i = 0; i < sphere_list.size(); i=i+1){
    std::cout << "atom:"  << i+1 << std::endl << sphere_list[i] << std::endl;

}
  return 0;
}
