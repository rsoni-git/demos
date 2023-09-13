/*
 * @breif: Demonstration threading
 */

#include <iostream>
#include <vector>
#include <thread>
#include <future>

extern "C" {
#include <unistd.h>
}


using namespace std;


int threadTarget ( int iThreadId ) {
  // cout << "threadTarget() function was called by thread id: " << iThreadId;
  //sleep(10);
  return iThreadId;
}


int main ( void ) {
  vector<thread> vThreadContainer(10);
  future<int> returnValue[10];

  for ( int iIter = 0; iIter < 10; iIter++ ) {
    promise<int> promise;
    returnValue[iIter] = promise.get_future();
    vThreadContainer.push_back(
      thread([&promise, iIter] ( ) {
                int iRtn = threadTarget(iIter);
                promise.set_value(iRtn);
             }
      )
    );
  }

  for ( auto& iIter : vThreadContainer ) {
    iIter.join();
  }

  for ( int iIter = 0; iIter < 10; iIter++ ) {
    int iRtn = returnValue[10].get();
    cout << "Return value from thread id " << iIter << " is: " << iRtn << endl;
  }
}

