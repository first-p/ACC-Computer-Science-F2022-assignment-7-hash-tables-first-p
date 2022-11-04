/*********************
 Name: Fred Butoma
 Assignment 7
 Purpose: linkedlist.cpp is the linked list class and 
 has all the operations required to manipulate a
 singly linked list
 *********************/

 #include "linkedlist.h"
 #include "data.h"
// constructor
LinkedList::LinkedList() {
  head = new Node;
  head = NULL; 
}
// destructor
LinkedList::~LinkedList() {
  clearList();
}
/////////////////
// setters//////
///////////////
bool LinkedList::addNode(int id, string *data) {
  bool added = false;
  if (id > 0 && *data != "") {
    //created head node (first node)
    if (head == NULL){
      Node *newNode = createNode(id, data);
      newNode->next = NULL;
      newNode->prev = NULL;
      head = newNode;
      added = true;
      }
    Node *current = head;
     //adds a node at front of the list (becomes new head)
    if (id < current->data.id ){
      addHead(id, data);
      added= true;
    }
    // finds the place in ordered list for new node to be added
    while (current->next != NULL && id > current->data.id && id != current->data.id) {
      current = current-> next;
    }
     // add new node in between two existing nodes
    if (id < current->data.id && id > current->prev->data.id) {
      addMiddle(id, data, current);
      added = true;
    }
    // add node at the after the last existing node (new tail)
    else if (id > current->data.id) {
      addTail(id, data, current);
      added = true;
    
    }
  }
  return added;
}
bool LinkedList::addHead(int id, string *data) {
  Node *newNode = createNode(id, data);
  head->prev = newNode;
  newNode->next = head;
  head = newNode;
  return true;
}
bool LinkedList::addMiddle(int id, string *data, Node *current) {
  Node *newNode = createNode(id, data);
  newNode->prev = current->prev;
  newNode->next = current;
  current->prev->next = newNode; 
  current->prev = newNode;
  return true;
}
bool LinkedList::addTail(int id, string *data, Node *current) {
  Node *newNode = createNode(id, data);
  newNode->prev = current;
  current->next = newNode;
  return true;
}
Node* LinkedList::createNode(int id, string *data) {
  Node *newNode = new Node;
  newNode->data.id = id;
  newNode->data.data = *data;
  newNode->next = NULL;
  newNode->prev = NULL;
  return newNode;
}
bool LinkedList::deleteNode(int id) {
  bool deleted = false;
  Node *current = head;
  while (!deleted && current){
       if(id == current->data.id && isLast(current)){
                delLast(current);
                deleted = true;
            }
        else if (id == current->data.id && current->prev == NULL){         
            delHead(current);
            current = NULL;
            deleted = true;
            
        }
        
        else if (id == current->data.id && current->next == NULL){
            delTail(current);
            current = NULL;
            deleted = true;
        }
        else if (id == current->data.id && current->next != NULL && current->prev != NULL ){
            delMiddle(current);
            current = NULL;
            deleted = true;
        }
  
        else {
            current = current -> next;
        }
    }
    return deleted;
}  
bool LinkedList::delHead(Node *current){
    current->next->prev = NULL;
    head = current->next;
    delete current;
    current= NULL;
    return true;
}
bool LinkedList::delMiddle(Node *current){
    current->prev->next = current->next;
    current->next->prev = current->prev;
    delete current;
    current = NULL;
    return true;
}
bool LinkedList::delTail(Node *current){
    current->prev->next = NULL;
    delete current;
    current = NULL;
    return true;
}
bool LinkedList::isLast(Node *current){
    bool isLast = false;
    if (current->next == NULL && current->prev == NULL){
        isLast = true;
    }
    return isLast;
}
bool LinkedList::delLast(Node *current){
    delete current;
    current = NULL;
    head = NULL;
    return true;
}
bool LinkedList::clearList() {
    bool cleared = false;
    Node *current;
    while(head){
        current = head;
        if (!isLast(current)){
            current->next->prev = NULL;
            head = current->next;
            delete current;
            current = NULL;
        }
        else {
            delLast(current);
            cleared = true;
        }
    }
    return cleared; 
}  
/////////////////////
////// getters//////
///////////////////
bool LinkedList::getNode(int id, Data *emptyObj) {
  bool got = false;
  Node *current = head;
  while (current){
    if (id == current->data.id){
        emptyObj->id = current->data.id;
        emptyObj->data = current->data.data;
        got = true;
        current = NULL;
    }
    else{
        current = current -> next;
    }
  }
  return got;
}
void LinkedList::printList(bool backward) {
  Node *current = new Node;
  current = head;
  int count = 0;
  if (!backward) {
    while (current) {
      cout << count << ": " << current->data.id << " : " << current->data.data << endl;
      current = current->next;
      count++;
    }
  } else if (backward) {
    current = head;
    bool tailFound = false;
    int count = 0;
    while (current && !tailFound) {
      if (current->next) {
        current = current->next;
        count++;
      } else {
        tailFound = true;
      }
    }
    while (current) {
      cout << count << ": " << current->data.id << " : " << current->data.data << endl;
      current = current->prev;
      count --;
    }
  }
}
int LinkedList::getCount() {
  Node *current = head;
  int count = 0;
    while (current) {
      count++;
      current = current->next;
    }
  return count;
}
bool LinkedList::exists(int id) {
  bool exists = false;
  Node *current = head;
  while (current){
    if (current->data.id == id){
        exists = true;
        current = NULL;
    }
    else {
        current = current->next;
    }
  }
  return exists;
}