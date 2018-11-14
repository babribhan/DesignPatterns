#include<iostream>
#include "vehicle"
#include "factory"
using std::cout;
using std::endl;
int main(){
Vehicle* p = Factory::createInstance(1);
if (p)
p->doRun();
int result = Factory::destroyInstance(p);
cout<<"Destroying p : "<<result<<endl;
return 0;
}
