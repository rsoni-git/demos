/*
 * @Func: Demonstration of operator overloading parenthesis
 */


#include <iostream>

using namespace std;


class A {
  public:
    // Overload parenthesis operator
    // Add paramenters passes inside the object parenthesis
    int operator () ( int iX, int iY ) {
      return (iX + iY);
    }
};


int main ( void ) {
  A obj1;

  cout << "ClassObject(x, y): " << obj1(2, 3) << endl;

}

