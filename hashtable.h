/*********************
Name: Fred Butoma
Assignment 7
Purpose: hashtable.h contains all the
prototypes and libraries for the hash table class
*********************/

#ifndef HASH_TABLE_H
#define HASH_TABLE_H

#include "linkedList.h"
#include <iostream>

#define HASHTABLESIZE 15

using std::cout;
using std::endl;



class Hashtable {

public:
  Hashtable();
  ~Hashtable();
  
  bool insertEntry(int, string*);
  string getData(int);
  bool removeEntry(int);
  int getCount();
  void printTable();


  

private:
  int hash(int);
  int count;
  LinkedList *hashtable[HASHTABLESIZE];
  void insert(LinkedList *, int, int, string *, bool *, int *);
};

#endif // #HASH_TABLE_H