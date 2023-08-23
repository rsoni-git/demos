/*
  @Func: A simple linked list, inserttion and interation
*/

#include <stdio.h>
#include <stdlib.h>


struct stdNode {
  int iData;
  struct stdNode* pstiNextNode;
};

int main ( void ) {
  struct stdNode *pstiNode = NULL, *pstiRootNode = NULL, *pstiParentNode = NULL;

  for ( int iIter = 0; iIter < 10; iIter++ ) {
    pstiNode = (struct stdNode*) malloc(sizeof(struct stdNode));
    pstiNode->iData = iIter;
    pstiNode->pstiNextNode = NULL;

    if ( ! pstiParentNode ) {
      pstiParentNode = pstiNode;
    } else {
      pstiParentNode->pstiNextNode = pstiNode;
      pstiParentNode = pstiNode;
    }

    if ( ! pstiRootNode )
      pstiRootNode = pstiNode;
  }

  for ( int iIter = 0; iIter < 10; iIter++ ) {
    printf("%d ", pstiRootNode->iData);

    if ( pstiRootNode->pstiNextNode )
      pstiRootNode = pstiRootNode->pstiNextNode;
    else
      break;
  }

  return 0;
}