/*
 * @breif: Demonstration threading
 */

#include <iostream>
#include <vector>
#include <thread>
#include <future>
#include <mutex>

extern "C" {
#include <unistd.h>
}


using namespace std;


int threadTarget ( int iThreadId ) {
  cout << "threadTarget() function was called by thread id: " << iThreadId << endl;
  sleep(5);
  return iThreadId;
}


int main ( void ) {
  int iRtn = -1;
  int iNumThreads = 10;
  vector<thread> vThreads(iNumThreads);
  vector<future<int>> vFuture(iNumThreads);
  vector<promise<int>> vPromise(iNumThreads);
  mutex mutexLock;

  for ( int iIter = 0; iIter < iNumThreads; iIter++ ) {
    vFuture[iIter] = vPromise[iIter].get_future();

    vThreads[iIter] = thread([&mutexLock, &vPromise, iIter] ( ) {
                                int iRtn = threadTarget(iIter);
                                {
                                  lock_guard<mutex> lock(mutexLock);
                                  vPromise[iIter].set_value(iRtn);
                                }
                              }
                      );
  }

  for ( int iIter = 0; iIter < iNumThreads; iIter++ ) {
    vThreads[iIter].join();
    iRtn = vFuture[iIter].get();
    cout << "Return value from thread id " << iIter << " is: " << iRtn << endl;
  }

  return 0;
}
