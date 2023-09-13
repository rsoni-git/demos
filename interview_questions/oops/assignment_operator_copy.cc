/*
 * @Func: Demonstration of assignment operator copy
 */


#include <iostream>

using namespace std;


class A {
  public:
    int m_iNum1;
    int m_iNum2;

    A ( void ) : m_iNum1(1), m_iNum2(2) {}
    ~A ( void ) {}

    A& operator = ( const A& ) {
      cout << "Returning the same object" << endl;
      return *this;
    }
   
};


int main ( void ) {
  A obj1, obj2;
  cout << "Value of obj1.iNum1: " << obj1.m_iNum1 << endl;
  cout << "Value of obj1.iNum2: " << obj1.m_iNum2 << endl;

  obj1.m_iNum2 = 4;
  cout << "New value of obj1.iNum2: " << obj1.m_iNum2 << endl;

  obj2 = obj1;
  cout << "Value obj2.m_iNum1: " << obj2.m_iNum1 << endl;  
  cout << "Value obj2.m_iNum2: " << obj2.m_iNum2 << endl;  
}

