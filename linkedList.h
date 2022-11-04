/*********************
 Name: Fred Butoma
 Assignment 7
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
        // setters
        bool addNode(int, string *);
        bool deleteNode(int);
        bool clearList();

    private:
        // attributes
        Node *head;
        // helper methods
        bool addHead(int, string *);
        bool delHead(Node*);
        bool addTail(int, string *, Node *);
        bool delTail(Node*);
        bool addMiddle(int, string *, Node *);
        bool delMiddle(Node*);
        bool isLast(Node*);
        bool delLast(Node*);
        Node *createNode(int, string *);
};

#endif // LINKED_LIST_H