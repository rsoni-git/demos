/*
 * @Func: Demos C++ maps
 */

#include <iostream>
#include <map>

using namespace std;


int main ( void ) {
  map<std::string, int> mMap;

  mMap.insert({"key1", 1});
  mMap.insert({"key2", 2});
  mMap.insert({"key3", 3});
  mMap.insert({"key4", 4});

  cout << "Printing the original map:" << endl;
  for ( auto aIter = mMap.begin(); aIter != mMap.end(); ++aIter ) {
    cout << aIter->first << ": " << aIter->second << endl;
  }

  cout << endl << endl;

  cout << "Printing map after delete the third element:" << endl; 
  mMap.erase("key3");

  for ( auto aIter : mMap ) {
    cout << aIter.first << ": " << aIter.second << endl;
  }
}

