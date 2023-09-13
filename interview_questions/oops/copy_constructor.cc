/*
 * @Func: Demonstration of copy constructor
 */


#include <iostream>

using namespace std;


class A {
  public:
    int m_iNum1;
    int m_iNum2;

    A ( void ) : m_iNum1(1), m_iNum2(2) {}
    ~A ( void ) {}
   
    // Define copy constructor
    // If you comment the below line, both variables will be copied automatically
    // Else m_iNum1 will be 0 and m_iNum2 will be 4
    A ( const A& ) : m_iNum2(4) {}
};


int main ( void ) {
  A obj1;
  cout << "Value of obj1.iNum1: " << obj1.m_iNum1 << endl;
  cout << "Value of obj1.iNum2: " << obj1.m_iNum2 << endl;

  A obj2(obj1);
  cout << "Value of obj2.iNum1: " << obj2.m_iNum1 << endl;
  cout << "Value of obj2.iNum2: " << obj2.m_iNum2 << endl;
  
}

