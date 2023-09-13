/*
 * @brief: Demonstration STL list
 */

#include <iostream>
#include <list>
#include <iterator>

using namespace std;


int main ( void ) {
  list<int> lList {1, 2, 3, 4, 5, 6};

  cout << "Printing the list: ";
  for ( auto aIter : lList ) {
    cout << aIter << " ";
  }

  cout << endl;

  cout << "First element in the list: " << lList.front() << endl;

  cout << "Last element in the list: " << lList.back() << endl;

  cout << "Size of the list: " << lList.size() << endl;

  cout << "Inserting 0 at the beginning of the last and 7 at the end of the list: ";
  lList.push_front(0);
  lList.push_back(7);
  copy(lList.begin(), lList.end(), ostream_iterator<int>(cout, " "));
  cout << endl;

  cout << "Removing back the recently added element: ";
  lList.pop_front();
  lList.pop_back();
  copy(lList.begin(), lList.end(), ostream_iterator<int>(cout, " "));
}

