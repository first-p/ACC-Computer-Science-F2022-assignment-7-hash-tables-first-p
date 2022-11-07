/*********************
Name: Fred Butoma
Assignment 7
Purpose: hashtable.cpp is the hash table class
and includes all operations for manipulating a
hash table object
*********************/

#include "hashtable.h"
#include "linkedlist.h"

Hashtable::Hashtable() {
    count = 0;
    cout << "inside constructor" << endl;
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

    if (id > 0 && *data != ""){
         int position = hash(id);

         if (!hashtable[position]){
            hashtable[position] = new LinkedList;
            bool success = hashtable[position]->addNode(id, data);
            if (success){
                added = true;
                 count++;
            }
         }
         else{
            bool success = hashtable[position]->addNode(id, data);
            if (success){
                added = true;
                count++;
            }
         }
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
    if (id > 0){
        int position = hash(id);
        if (hashtable[position]){
            bool success = hashtable[position]->deleteNode(id);
            if (success){
                removed = true;
                count --;
            }
            
            if (hashtable[position]->isEmpty()){
                hashtable[position] == NULL;
                
            }
        }
       
    }

    return removed;
}

int Hashtable::getCount(){
    return count;
}

void Hashtable::printTable(){
    for (int i = 0; i < HASHTABLESIZE; i++){
        if (hashtable[i]){
            // if (!hashtable[i]->isEmpty()){
                  cout << "Entry " << i << " : ";
                hashtable[i]->printList(false); 
                cout << "|" << endl;
            // }
          
            
        }
        else if (!hashtable[i]){
            cout << "Entry " << i << " : " << "EMPTY" << endl;
        }
    }
    cout << "count: " << count << endl;
}



int Hashtable::hash(int id){
    return id % HASHTABLESIZE;
}


