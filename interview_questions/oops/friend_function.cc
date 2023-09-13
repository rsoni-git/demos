/*
 * @Func: Demonstration friend functions
 */

#include <iostream>

using namespace std;


class A {
  private:
    int iNumA;

    // Declare friendOfClassA function as a friend function of this class
    friend void friendOfClassA( void );

  public:
    A ( void ) : iNumA(12) {};
};


void friendOfClassA ( void ) {
  A objA;
  cout << "Value of class A private memeber variable iNumA: " << objA.iNumA << endl;
}


int main ( void ) {
  friendOfClassA();
  return 0;
}
