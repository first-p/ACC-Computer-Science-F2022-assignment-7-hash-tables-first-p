/*********************
Name: Fred Butoma
Assignment 7
Purpose: hashtable.cpp is the hash table class
and includes all operations for manipulating a
hash table object
*********************/

#include "hashtable.h"

Hashtable::Hashtable() {
    count = 0;
    for (int i = 0; i < HASHTABLESIZE; i++) {
        hashtable[i] = NULL;
    }
}

Hashtable::~Hashtable() {
    for (int i = 0; i < HASHTABLESIZE; i++) {
        if (hashtable[i]) {
            delete hashtable[i];
            hashtable[i] = NULL;
        }
    }
}

bool Hashtable::insertEntry(int id, string *data){
    bool added = false; 
    int position = hash(id);

    if (id > 0 && *data != ""){
        added = hashtable[position]->addNode(id, data);
        count++;
    }
    return added;
}
string Hashtable::getData(int id){
    int position = hash(id);
    Data *emptyObj;
    hashtable[position]->getNode(id, emptyObj);

    return emptyObj->data;
}


bool Hashtable::removeEntry(int id){
    bool removed = false; 
    int position = hash(id);

    removed = hashtable[position]->deleteNode(id);
    count --;

    return removed;
}

int Hashtable::getCount(){
    return count;
}

void Hashtable::printTable(){
    for (int i = 0; i < HASHTABLESIZE; i++){
        if (hashtable[i]){
            cout << "Entry " << i << " : " << hashtable[i]->printList(false) << endl;
        }
        else{
            cout << "Entry " << i << " : " << "EMPTY" << endl;
        }
    }
}


int Hashtable::hash(int id){
    return id % HASHTABLESIZE;
}


