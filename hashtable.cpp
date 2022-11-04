/*********************
Name: Fred Butoma
Assignment 7
Purpose: hashtable.cpp is the hash table class
and includes all operations for manipulating a
hash table object
*********************/

#include "hashtable.h"

HashTable::HashTable() {
    count = 0;
    for (int i = 0; i < HASHTABLESIZE; i++) {
        hashtable[i] = nullptr;
    }
}

HashTable::~HashTable() {
    for (int i = 0; i < HASHTABLESIZE; i++) {
        if (hashtable[i]) {
            delete hashtable[i];
            hashtable[i] = nullptr;
        }
    }
}

bool HashTable::insertEntry(int id, string *data){

}
string HashTable::getData(int id){

}


bool HashTable::removeEntry(int id){

}

int HashTable::getCount(){

}

void HashTable::printTable(){

}


int HashTable::hash(int id){

}


