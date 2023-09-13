/*
 * @Func: Demonstration friend class
 */

#include <iostream>

using namespace std;

// Forward declaration of class B
class B;

class A {
  private:
    int iNumA;

    // Declare class B as a friend class
    friend class B;

  public:
    // Constructor to initialize iNumA
    A() : iNumA(12) {}

};


class B {
  public:
    void print ( void ) {
      A objA;
      cout << "Value of class A private member variable iNumA = " << objA.iNumA << endl;
    }
};


int main ( void ) {
  B objB;

  objB.print();
}

