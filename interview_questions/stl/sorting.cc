/*
 * @Func: Sorting demonstration using sorting
 */

#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>

using namespace std;


int main ( void ) {
  vector<int> vArr{10, 20, 30, 40, 5, 15, 25};

  cout << "Printing the vector before sorting: ";
  copy(vArr.begin(), vArr.end(), ostream_iterator<int>(cout, " "));
  cout << endl;

  cout << "Sorting the vector in ascending order: ";
  sort(vArr.begin(), vArr.end());
  copy(vArr.begin(), vArr.end(), ostream_iterator<int>(cout, " "));
  cout << endl;

  cout << "Sorting the vector in descending order: ";
  sort(vArr.begin(), vArr.end(), greater<int>());
  copy(vArr.begin(), vArr.end(), ostream_iterator<int>(cout, " "));
  cout << endl;
}

