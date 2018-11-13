#include<iostream>
using namespace std;
// Abstract Product classes
class Window{
  public: 
    virtual void make_window() = 0;
};
class ScrollBar{
  public: 
    virtual void make_scrollbar() = 0;
};
// Abstract Factory class
class WidgetFactory{
  public:
    virtual ScrollBar* createScrollBar()=0;
    virtual Window* createWindow()=0;
    virtual ~WidgetFactory(){}
};
class Application{
  public: 
    void createDesktop(WidgetFactory* wf){
      wf->createWindow()->make_window();
      wf->createScrollBar()->make_scrollbar();
    }
};
// Concrete Product classes
class LightWindow : public Window{
  public: 
    void make_window(){
      std::cout<<"Light windows is created"<<std::endl;
    }
};
class DarkWindow : public Window{
  public: 
    void make_window(){
      std::cout<<"Dark windows is created"<<std::endl;
    }
};
class LightScrollbar : public ScrollBar{
  public: 
    void make_scrollbar(){
      std::cout<<"Light scrollbar is created"<<std::endl;
    }
};
class DarkScrollbar : public ScrollBar{
  public: 
    void make_scrollbar(){
      std::cout<<"Dark scrollbar is created"<<std::endl;
    }
};
// Concrete Factory classes
class LightWidgetFactory : public WidgetFactory{
  public:
    ScrollBar* createScrollBar(){
      return new LightScrollbar();
    }
    Window* createWindow(){
      return new LightWindow();
    }
    virtual ~LightWidgetFactory(){}
};
class DarkWidgetFactory : public WidgetFactory{
  public:
    ScrollBar* createScrollBar(){
      return new DarkScrollbar();
    }
    Window* createWindow(){
      return new DarkWindow();
    }
    virtual ~DarkWidgetFactory(){}
};
int main(){
  Application app;
  WidgetFactory *wgf = new DarkWidgetFactory();
  app.createDesktop(wgf);
  return 0;
}
