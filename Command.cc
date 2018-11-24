#include <iostream>
#include <string>
// receivers
class Cow {
  public:
    void moo() {
      std::cout << "Cow says moo!" << std::endl;
    }
};
class Dog {
  std::string name;
  public:
  Dog(const std::string& name) : name(name) {}

  void makeSound() {
    std::cout << name + " barks!" << std::endl;
  }
};
class Car {
  bool engineOn;
  public:
  Car() : engineOn(false) {};

  void turnCarOn() {
    engineOn = true;
  }
  void revEngine() {
    if (engineOn) {
      std::cout << "Vroom, vroom, vroom!" << std::endl;
    }
    else {
      std::cout << "Silence!" << std::endl;
    }
  }
};
// commands
class Command {
  public:
    virtual void execute() = 0;
    virtual ~Command(){};
};
class CowCommand : public Command {
  Cow cow;
  public:
  CowCommand(const Cow& cow) : cow(cow) {}
  void execute() override {
    cow.moo();
  }
};

class DogCommand : public Command {
  Dog dog;
  public:
  DogCommand(const Dog& dog) : dog(dog) {}

  void execute() override {
    dog.makeSound();
  }
};

class CarCommand : public Command {
  Car car;
  public:
  CarCommand(const Car& car) : car(car) {}

  void execute() override {
    car.turnCarOn();
    car.revEngine();
  }
};

// invoker

class PlatoSays {
  std::unique_ptr<Command> ptr_command;
  public:
  void setCommand(std::unique_ptr<Command>&& ptr_cmd) {
    ptr_command = std::move(ptr_cmd);
  }
  void invokeCommand() {
    if (ptr_command) {
      std::cout << "Plato says: ";
      ptr_command->execute();
    }
    else {
      std::cout << "Plato has nothing to say!" << std::endl;
    }
  }
};
// client
int main() {
  PlatoSays plato;
  plato.setCommand(std::unique_ptr<Command>(new CowCommand(Cow())));
  plato.invokeCommand();
  plato.setCommand(std::unique_ptr<Command>(new DogCommand(Dog("Lucky"))));
  plato.invokeCommand();
  plato.setCommand(std::unique_ptr<Command>(new CarCommand(Car())));
  plato.invokeCommand();
  return 0;
}
