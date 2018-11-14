#include <iostream>
#include "vehicle"
using std::cout;
using std::endl;
Vehicle::Vehicle(){

}
Vehicle::~Vehicle(){

}
CivilCar::CivilCar(){
  cout<<"CivilCar CTOR called"<<endl;
}
CivilCar::~CivilCar(){
  cout<<"CivilCar DTOR called"<<endl;
}
void CivilCar::doRun(){
  cout<< "CivilCar is started"<<endl;
}
Motorcycle::Motorcycle(){
  cout<<"Motorcycle CTOR called"<<endl;
}
Motorcycle::~Motorcycle(){
  cout<<"Motorcycle DTOR called"<<endl;
}
void Motorcycle::doRun(){
  cout<< "Motorcycle is started"<<endl;
}
