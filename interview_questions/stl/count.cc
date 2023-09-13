/*
 * @Func: Demonstrating of number of occurence count
 */


#include <iostream>
#include <algorithm>
#include <iterator>

using namespace std;


int main ( void ) {
  vector<int> vArr { 2, 4, 5, 6, 7, 7, 8, 7, 7, 9 };

  cout << "Counting the occurence of number 7 in vector: ";
  copy(vArr.begin(), vArr.end(), ostream_iterator<int>(cout, " "));
  cout << endl;

  cout << "Count: ";
  cout << count(vArr.begin(), vArr.end(), 7) << endl;
}

