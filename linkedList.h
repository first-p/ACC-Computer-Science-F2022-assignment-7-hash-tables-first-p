/*********************
Name: Fred Butoma
Assignment 6
Purpose: linkedlist.h has all the prototype
methods for the linked list class 
*********************/

#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include "data.h"
#include <iostream>

using std::cout;
using std::endl;

class LinkedList {

public:
  // constructor
  LinkedList();

  // destructor
  ~LinkedList();

  // getters
  bool getNode(int, Data *);
  void printList(bool = false);
  int getCount();
  bool exists(int);
  bool isEmpty();

  // setters
  bool addNode(int, string *);
  bool deleteNode(int);
  bool clearList();

private:
  // attributes
  Node *head;
  // helper methods
  bool addHead(Node*);
  bool delHead(Node*);
  bool addTail(Node*, Node *);
  bool delTail(Node*);
  bool addMiddle(Node*, Node *);
  bool delMiddle(Node*);
  bool isLast(Node*);
  bool delLast(Node*);
  Node *createNode(int, string *);
};

#endif // LINKED_LIST_H

