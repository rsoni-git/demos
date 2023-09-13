/*
 * @Func: Bubble sort demo
 */

#include <iostream>
#include <vector>
#include <iterator>

using namespace std;


int main ( int iArgc, char** ppcArgv ) {
  bool bSwapped = false;
  vector<int> vArr;

  if ( iArgc <= 1 ) {
    cout << "Error: Pass an integer list as parameters to do sorting" << endl;
    return 1;
  }
  // Insert the command line parameters to the vector
  for ( int iIter = 1; iIter < iArgc; iIter++ ) {
    vArr.push_back(atoi(ppcArgv[iIter]));
  }

  // Print the vector before sorting
  cout << "Vector before sorting: ";
  copy(vArr.begin(), vArr.end(), ostream_iterator<int>(cout, " "));
  cout << endl;

  while ( true ) {
    bSwapped = false;

    for ( int iIter = 0; iIter < vArr.size() - 1 ; iIter++ ) {
      if ( vArr[iIter] > vArr[iIter + 1] ) {
        vArr[iIter] = vArr[iIter] ^ vArr[iIter + 1];
        vArr[iIter + 1] = vArr[iIter] ^ vArr[iIter + 1];
        vArr[iIter] = vArr[iIter] ^ vArr[iIter + 1];
        bSwapped = true;
      }
    }

    // Continue until the pass where no elements were swapped
    // This means that the vector is now sorted, break !!!
    if ( ! bSwapped )
      break;
  }

  // Print the vector after sorting
  cout << "Vector after sorting: ";
  copy(vArr.begin(), vArr.end(), ostream_iterator<int>(cout, " "));
  cout << endl;

  return 0;
}
