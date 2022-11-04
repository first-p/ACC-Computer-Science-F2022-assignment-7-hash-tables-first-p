/*********************
Name: Fred Butoma
Assignment 7
Purpose: hashtable.h contains all the
prototypes and libraries for the hash table class
*********************/

#ifndef HASH_TABLE_H
#define HASH_TABLE_H

#include "linkedList.cpp"
#include <iostream>

#define HASHTABLESIZE 15

using std::cout;
using std::endl;



class HashTable {
public:
  HashTable();
  ~HashTable();
  bool insertEntry(int, string*);
  string getData(int);
  bool removeEntry(int);
  int getCount();
  void printTable();

private:
  int hast(int);
};

#endif // #HASH_TABLE_H