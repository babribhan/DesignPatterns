#include<iostream>
#include<string>
using namespace std;

//Represents the complex object under construction
class Plane{
        string _plane;
        string _body;
        string _engine;
        public:
        Plane(string plane_type):_plane(plane_type){}
        void setEngine(string type) { _engine = type;}
        void setBody(string body)   { _body = body;}
        string getEngine()    { return _engine;}
        string getBody()      { return _body;}
        void show(){
                cout<< "Plane type: "<<_plane <<endl
                        << "Body type: "<<_body <<endl
                        << "Engine type: "<<_engine <<endl;
        }
        ~Plane(){}
};
// Abstract Builder class
class PlaneBuilder{
        protected:
                Plane *plane;
        public:
                virtual void getPartsDone()=0;
                virtual void buildBody()=0;
                virtual void buildEngine()=0;
                Plane* getPlane(){ return plane;}
                virtual ~PlaneBuilder(){}
};
// Concrete Builder classes
class FirstBuilder : public PlaneBuilder{
        public:
                void getPartsDone() { plane = new Plane("First Plane");}
                void  buildBody() { plane->setBody("First Body");}
                void  buildEngine() { plane->setEngine("First Engine");}
                virtual ~FirstBuilder(){ delete plane;}
};
class SecondBuilder : public PlaneBuilder{
        public:
                void getPartsDone() { plane = new Plane("Second Plane");}
                void  buildBody() { plane->setBody("Second Body");}
                void  buildEngine() { plane->setEngine("Second Engine");}
                virtual ~SecondBuilder(){ delete plane;}
};
// Constructs an object using the Builder interface.
class Director{
        public:
                Plane* createPlane(PlaneBuilder *builder){
                        builder->getPartsDone();
                        builder->buildBody();
                        builder->buildEngine();
                        return builder->getPlane();
                }
};
int main(){
        Director dir;
        Plane *myplane = dir.createPlane(new SecondBuilder());
        myplane->show();
        delete myplane;
        return 0;
}
