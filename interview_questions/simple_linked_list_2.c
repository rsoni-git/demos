#include <stdio.h>
#include <stdlib.h>

struct Node {
  int data;
  struct Node* next;
}


int main ( void ) {
  struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));
  struct Node* parent_node = NULL;
  struct Node* root_node = NULL;
  int value = 0;

  while ( true ) {
    new_node->data = value;
    new_node->next = NULL;

    if ( ! parent_node ) {
      parent_node = new_node;
    } else {
      parent_node->next = new_node;
      parent_node = parent_node->next;
    }

    if ( ! parent_node ) {

    }
  }
}

