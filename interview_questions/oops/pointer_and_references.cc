/*
 * @brief: Demonstration of differences of pointer and references
 */

#include <iostream>

using namespace std;


template<size_t tiSize> void references ( int iNum1, int& iNum2, int (&aiArr) [tiSize] ) {

  cout << "*** Inside function references() ***" << endl << endl;

  iNum1 = 10;
  cout << "Setting the value of parameter iNum1: " << iNum1 << endl;

  iNum2 = 10;
  cout << "Setting the value of parameter iNum2: " << iNum2 << endl;

  aiArr[2] = 10;
  cout << "Setting the value of aiArr[2]: " << aiArr[2] << endl;

  cout << "Size of the array: " << tiSize;

  cout << endl << "*** Exiting function references() ***" << endl << endl;
}


void  pointers ( int iNum1, int* iNum2, int* aiArr /* or int aiArr[] both are same */ ) {

  cout << "*** Inside function pointers() ***" << endl << endl;

  iNum1 = 20;
  cout << "Setting the value of parameter iNum1: " << iNum1 << endl;

  *iNum2 = 20;
  cout << "Setting the value of parameter iNum2: " << iNum2 << endl;

  aiArr[2] = 20;
  cout << "Setting the value of aiArr[2]: " << aiArr[2] << endl;

  cout << endl << "*** Exiting function pointers() ***" << endl << endl;
}


int main ( void ) {

  int iNum1 = 5;
  int iNum2 = 5;
  int aiArr[] = {1, 2, 3, 4, 5};

  references(iNum1, iNum2, aiArr);

  cout << "Values after calling references(): " << endl;

  // iNum1 should not change (Passed as value to references(), which creates a copy)
  cout << "Value iNum1: " << iNum1 << endl;

  cout << "Value iNum2: " << iNum2 << endl;
  cout << "Value of aiArr[]: ";

  for ( int iIter = 0; iIter < 5; iIter++ )
    cout << aiArr[iIter] << " ";

  cout << endl << endl;

  pointers(iNum1, &iNum2, aiArr);
  cout << "Values after calling pointers(): " << endl;

  // iNum1 should not change (Passed as value to pointers(), which creates a copy)
  cout << "Value iNum1: " << iNum1 << endl;

  cout << "Value iNum2: " << iNum2 << endl;
  cout << "Value of aiArr[]: ";

  for ( int iIter = 0; iIter < 5; iIter++ )
    cout << aiArr[iIter] << " ";
}

