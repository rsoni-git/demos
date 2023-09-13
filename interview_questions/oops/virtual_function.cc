/*
 * @Func: Demonstrate virtual functions
 */


#include <iostream>

using namespace std;


class BaseClass {
  public:
    virtual void print ( void ) {
      cout << "Function called BaseClass::print()";
    }

};


class DerivedClass : public BaseClass {

  public:
    void print ( void ) override {
      cout << "Function called DerivedClass::print()" << endl;
    }

};


int main ( void ) {

  cout << "A simple demonstration of vitual functions" << endl;

  // Create pointer of type BaseClass
  BaseClass* objBaseClass;

  // Create derived class object
  DerivedClass objDerivedClass;

  // Assign address of the DerivedClass object to the BaseClass pointer
  objBaseClass = &objDerivedClass;

  // This should call DerivedClass::print()
  objBaseClass->print();
}
