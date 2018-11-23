#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
static int trace_depth=0;
using namespace std;
/* Primitive object interface.*/
class Employee {
        public:
                Employee(const char* name ,const char* profile,int salary):_name(name),_profile(profile),_salary(salary){}
                virtual ~Employee(){};
                virtual void print () {
                        std::cout << std::string(2*trace_depth, ' ') << "NAME   : "<<get_name() << std::endl;
                        std::cout << std::string(2*trace_depth, ' ') << "PROFILE: "<<get_profile() << std::endl;
                        std::cout << std::string(2*trace_depth, ' ') << "SALARY : $"<<get_salary() << std::endl;
                }
                virtual void Add(Employee*)=0;
                virtual void Remove(Employee*)=0 ;
                virtual const char* get_name() const {return _name;}
                virtual const char* get_profile() const {return _profile;}
                virtual int get_salary() const { return _salary;}
        private:
                Employee();
                const char* _name;
                int _salary;
                const char* _profile;
};
/* Primitive object. */
class Developer : public Employee {
        public:
                Developer(const char* name,const char* profile,int salary) : Employee(name,profile,salary){};
                virtual ~Developer(){}
                void Add(Employee*) {}
                void Remove(Employee*) {}
};
class Tester : public Employee {
        public:
                Tester(const char* name,const char* profile,int salary) : Employee(name,profile,salary){};
                virtual ~Tester(){}
                void Add(Employee*) {}
                void Remove(Employee*) {}
};
class L1Support : public Employee {
        public:
                L1Support(const char* name,const char* profile,int salary) : Employee(name,profile,salary){};
                virtual ~L1Support(){}
                void Add(Employee*) {}
                void Remove(Employee*) {}
};
/* Composite object. */
class Manager : public Employee {
        public:
                Manager(const char* name,const char* profile,int salary) : Employee(name,profile,salary){};
                virtual ~Manager(){
                        for ( auto it = _employees.begin(); it != _employees.end(); it++ )
                                delete (*it);
                }
                void print(){
                        std::cout<< "manages following members : "<<std::endl;
                        Employee::print();
                        trace_depth++ ;
                        for ( auto it = _employees.begin(); it != _employees.end(); it++ )
                                (*it)->print();
                        trace_depth-- ;

                }
                void Add(Employee* emp){
                        _employees.push_back(emp);
                }
                void Remove(Employee* emp){
                        auto it = std::find(_employees.begin(),_employees.end(),emp);
                        if ( it != _employees.end() ) _employees.erase(it);
                }
        private:
                vector<Employee*> _employees;
};
/* Client interface */
int main(){
     trace_depth++ ;
     std::cout<< "Composite Design pattern demo."<<std::endl;
        Developer *dev1 = new Developer("DEVELOPER1","DEV1_CPP",200);
        Developer *dev2 = new Developer("DEVELOPER2","DEV2_JAVA",100);
        Developer *dev3 = new Developer("DEVELOPER3","DEV3_PYTHON",150);
        Tester  *t1 = new Tester("TESTER1","Robot with Python",170);
        Tester  *t2 = new Tester("TESTER2","Java tester",160);
        L1Support *l1 = new L1Support("L1SUPPORT1","Customer support operations",190);
        Manager *mngr = new Manager("MANAGER1","Management",500);
        mngr->Add(dev1);
        mngr->Add(dev2);
        mngr->Add(t1);
        mngr->Add(l1);

        /* Client can access both primitive and composite objects uniformally.*/
        mngr->print();
        mngr->Remove(dev1);
        mngr->print();
        dev1->print();
        t1->print();
        delete dev1;
        delete dev2;
        delete dev3;
        delete t1;
        delete t2;
        delete l1;
        trace_depth--;
        return 0;
        
}
