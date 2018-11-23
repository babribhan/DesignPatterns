#include <iostream>
/* Abstract Component  */
class IceCream{
	public:
		virtual void make() =0;
		virtual ~IceCream(){}
};
/* Concrete Component */
class SimpleIceCream : public IceCream{
	public : 
		virtual void make(){
			std::cout<<"Simple IceCream with Milk + Sugar.";
		}
};
/* Abstract Decorator */ 
class IceCreamDecorator : public IceCream{
	private : 
		IceCream& decorator;
	public:
		IceCreamDecorator(IceCream& doc) : decorator(doc){}
		virtual void make(){
		decorator.make();
		}
};
/* Concrete Decorator */
class WithFruits : public IceCreamDecorator{
	public:
		WithFruits(IceCream& deco) : IceCreamDecorator(deco){}
		virtual void make(){
			IceCreamDecorator::make();
		std::cout<<" + Fruits."; /* After responsibility Added */
		}
};
class WithNuts : public IceCreamDecorator{
	public:
		WithNuts(IceCream& deco) : IceCreamDecorator(deco){}
		virtual void make(){
			IceCreamDecorator::make();
		std::cout<<" + Nuts.";  /* After responsibility Added */
		}
};
class WithWafers : public IceCreamDecorator{
	public:
		WithWafers(IceCream& deco) : IceCreamDecorator(deco){}
		virtual void make(){
		std::cout<<"  + Wafers layer 1 .";  /* Before responsibility Added */
		IceCreamDecorator::make();
		std::cout<<"  + Wafers layer 2.";  /* After responsibility Added */
		}
};
int main(){

	IceCream* simpleIceCream_p = new SimpleIceCream();
	simpleIceCream_p->make();  // Use existing object.
        std::cout<<std::endl;
	IceCream* fruitIceCream_p = new WithFruits(*simpleIceCream_p);
	fruitIceCream_p->make();  // Use existing object with more responsibility(Added Fruits).
        std::cout<<std::endl;
	IceCream* nutsIceCream_p = new WithNuts(*fruitIceCream_p);
	nutsIceCream_p->make();  // Use existing object with more responsibility(Added Fruits + Nuts).
        std::cout<<std::endl;
	IceCream* wafersIceCream_p = new WithWafers(*nutsIceCream_p);
	wafersIceCream_p->make();  // Use existing object with more responsibility(Added Fruits + Nuts + Wafers).
        std::cout<<std::endl;

	delete simpleIceCream_p;
	delete fruitIceCream_p;
	delete nutsIceCream_p;
	delete wafersIceCream_p;
return 0;
}
