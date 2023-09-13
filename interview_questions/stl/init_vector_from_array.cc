/*
 * @brief: Intialize a vector from array
 */


#include <iostream>
#include <vector>
#include <iterator>

using namespace std;

int main ( void ) {
  int aiArr[] = {1, 2, 3, 4, 5};
  int iSize = sizeof(aiArr) / sizeof(int);

  // Parameters 1 and 2 here are reference to beginning and end of the array
  vector<int> vArr(aiArr, (aiArr + iSize));
  
  cout << "Vector converted from array: ";
  copy(vArr.begin(), vArr.end(), ostream_iterator<int>(cout, " "));
  cout << endl;
}

