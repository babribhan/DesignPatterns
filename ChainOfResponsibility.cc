#include <iostream>
#include <string>
using namespace std;
class Numbers{
  public:
    Numbers(int newNumber1, int newNumber2,string calcWanted):number1(newNumber1),
    number2(newNumber2),calculationWanted(calcWanted){}
    int getNumber1() const { return number1;}
    int getNumber2() const { return number2;}
    string getCalcWanted() const { return calculationWanted;}
  private:
    int number1,number2;
    string calculationWanted;
};
class Chain{
  public:
    virtual void setNextChain(Chain* nextChain){}
    virtual void calculate(Numbers request){}
    virtual ~Chain(){}
};
class AddNumbers : public Chain{
  public:
    void setNextChain(Chain* nextChain){
      nextInChain = nextChain;
    }
    void calculate(Numbers request){
      if ( request.getCalcWanted() == "add" ) {
        cout<<request.getNumber1() << " + " << request.getNumber2() << " = " << request.getNumber1()+request.getNumber2()<<endl;
      }
      else {
        nextInChain->calculate(request);
      }
    }
    ~AddNumbers(){ 
      if (nextInChain)
        delete nextInChain;
    }
  private:
    Chain* nextInChain;
};

class SubtractNumbers : public Chain{
  public:
    void setNextChain(Chain* nextChain){
      nextInChain = nextChain;
    }
    void calculate(Numbers request){
      if ( request.getCalcWanted() == "sub" ) {
        cout<<request.getNumber1() << " - " << request.getNumber2() << " = " << request.getNumber1()-request.getNumber2()<<endl;
      }
      else {
        nextInChain->calculate(request);
      }
    }
    ~SubtractNumbers(){ 
      if (nextInChain)
        delete nextInChain;
    }
  private:
    Chain* nextInChain;
};
class MultiplyNumbers : public Chain{
  public:
    void setNextChain(Chain* nextChain){
      nextInChain = nextChain;
    }
    void calculate(Numbers request){
      if ( request.getCalcWanted() == "mult" ) {
        cout<<request.getNumber1() << " * " << request.getNumber2() << " = " << request.getNumber1()*request.getNumber2()<<endl;
      } else {
        nextInChain->calculate(request);
      }
    }
    ~MultiplyNumbers(){ 
      if (nextInChain)
        delete nextInChain;
    }
  private:
    Chain* nextInChain;
};
class DivideNumbers : public Chain{
  public:
    void setNextChain(Chain* nextChain){
      nextInChain = nextChain;
    }
    void calculate(Numbers request){
      if ( request.getCalcWanted() == "div" ) {
        cout<<request.getNumber1() << " / " << request.getNumber2() << " = " << request.getNumber1()/request.getNumber2()<<endl;
      }
      else {
        cout<<"Only works for add, sub, mult and div."<<endl;
      }
    }
    ~DivideNumbers(){
      if (nextInChain)
        delete nextInChain;
    }
  private:
    Chain* nextInChain;
};
int main(){
  Chain* chainCal1 = new AddNumbers();
  Chain* chainCal2 = new SubtractNumbers();
  Chain* chainCal3 = new MultiplyNumbers();
  Chain* chainCal4 = new DivideNumbers();

  /* Create a Chain of handlers */
  chainCal1->setNextChain(chainCal2);
  chainCal2->setNextChain(chainCal3);
  chainCal3->setNextChain(chainCal4);

  Numbers request(2,5,"div");
  chainCal1->calculate(request);
  return 0;
}
