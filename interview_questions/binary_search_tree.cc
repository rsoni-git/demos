/*
 * @Func: Binary search tree
 */

#include <iostream>
#include <vector>
#include <iterator>

using namespace std;


struct stdTreeNode {
  int iValue;
  struct stdTreeNode *pstiNodeLeft, *pstiNodeRight;
};

typedef struct stdTreeNode stdNode;


stdNode* newNode ( int iNodeValue ) {
  stdNode* pstiNode = (stdNode*) malloc(sizeof(stdNode));
  if ( ! pstiNode )
    return nullptr;

  pstiNode->iValue = iNodeValue;
  pstiNode->pstiNodeLeft = pstiNode->pstiNodeRight = nullptr;

  return pstiNode;
}


int insert ( stdNode* pstiRootNode, int iNodeValue ) {
  stdNode *pstiNode = nullptr, *pstiNodeTmp = nullptr;
  stdNode* pstiNewNode = newNode(iNodeValue);

  if ( ! pstiRootNode )
    goto ERREXIT;

  pstiNode = pstiRootNode;

  while ( true ) {
    if ( iNodeValue <= pstiNode->iValue ) {
      if ( pstiNode->pstiNodeLeft ) {
        if ( iNodeValue > pstiNode->pstiNodeLeft->iValue ) {
          pstiNodeTmp = pstiNode->pstiNodeLeft;
          pstiNode->pstiNodeLeft = pstiNewNode;
          pstiNode->pstiNodeLeft->
        } else {
          pstiNode = pstiNode->pstiNodeLeft;
        }

      } else {
        pstiNode->pstiNodeLeft = pstiNewNode;
        break;
      }

    } else {
      if ( pstiNode->pstiNodeRight ) {
        pstiNode = pstiNode->pstiNodeRight;
      } else {
        pstiNode->pstiNodeRight = pstiNewNode;
        break;
      }
    }
  }

  EXIT:
    return 0;

  ERREXIT:
    return -1;
}


void inorderPrint ( stdNode* pstiParentNode ) {
  if ( pstiParentNode ) {
    inorderPrint(pstiParentNode->pstiNodeLeft);
    cout << pstiParentNode->iValue;
    inorderPrint(pstiParentNode->pstiNodeRight);
  }
}


int main ( int iArgc, char** ppcArgv ) {
  vector<int> vArr;
  stdNode* pstiRootNode = nullptr;

  if ( iArgc <= 1 ) {
    cout << "Error: Pass an integer list as parameters to be inserted into the binary search tree" << endl;
    return -1;
  }

  for ( int iIter = 1; iIter < iArgc; iIter++  ) {
    vArr.push_back(atoi(ppcArgv[iIter]));
  }

  // Print the vector before inserting to BST
  cout << "Integer parameter list: ";
  copy(vArr.begin(), vArr.end(), ostream_iterator<int>(cout, " "));
  cout << endl;

  for ( auto aIter : vArr ) {
    if ( ! pstiRootNode ) {
      pstiRootNode = newNode(aIter);
      continue;
    }

    insert(pstiRootNode, aIter);
  }

  inorderPrint(pstiRootNode);

  return 0;    
} 

