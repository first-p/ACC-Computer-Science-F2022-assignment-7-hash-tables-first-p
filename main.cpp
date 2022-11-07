/*********************
Name: Fred Butoma
Assignment 7
Purpose: main.cpp is the driver function and
test bed for the hash table class
*********************/

#include "main.h"

int main() {
  // seed the rand function
  srand(time(NULL));

  /*
   * This code makes test data of 6 - 25 entries
   * Note this guarantees at least one non unique id and one bad id
   * Do not modify this code from here to the next comment telling
   * you to "START HERE"
   */
  const int testdatasize = BASE + (rand() % OFFSET + 1);
  int ids[testdatasize];
  string strs[testdatasize];

  char buffer[BUFFERSIZE];
  for (int i = 0; i < testdatasize; i++) {
    ids[i] = rand() % MAXID + 1;
    for (int j = 0; j < BUFFERSIZE - 1; j++) {
      buffer[j] = 'a' + i;
    }
    buffer[BUFFERSIZE - 1] = '\0';
    strs[i] = buffer;
  }
  ids[testdatasize - 2] = ids[testdatasize - 3];
  strs[testdatasize - 2] = "known duplicate";
  ids[testdatasize - 1] = -1;
  strs[testdatasize - 1] = "known bad";

  /*
   * Show test data
   */
  cout << "Showing Test Data (" << testdatasize << " entries)..." << endl;
  for (int i = 0; i < testdatasize; i++) {
    cout << ids[i] << " : " << strs[i] << endl;
  }
  cout << endl;

  /*
   * Now you have two parallel arrays with ids and strings for test data.
   * START HERE and create your hash table and use the test data to show
   * it works.
   */

  // CREATE HASHTABLE & PRINT IT
  cout << "creating a hashtable object" << endl;
  Hashtable h1;
  string str = "data";

  cout << "\n\n printing empty hash table" << endl;
  h1.printTable();
  cout << "count: " << h1.getCount() << endl;
  
  //ADDING TEST DATA TO HASH TABLE & PRINT HASH TABLE
  cout << "\n\n adding nodes to hashtable" << endl;
  for (int i= 0 ; i < testdatasize; i++){
    if(h1.insertEntry(ids[i],&strs[i])){
      cout << "adding " << ids[i] << " : " << strs[i] << "..success" << endl;
    }
    else {
      cout << "adding " << ids[i] << " : " << strs[i] << "..failed" << endl;
    }
  }
  cout << endl;
  h1.printTable();
  cout << "count: " << h1.getCount() << endl;

  //GETTING DATA FROM HASH TABLE USING TEST DATA IDS
  cout << "\n\n getting data " << endl;
  
  for (int i=0 ; i < testdatasize; i++){
    string data= h1.getData(ids[i]);
    if (data != ""){
       cout << "getting " << ids[i] << " data: " << data << "..success" << endl;
    }
    else{
      cout << "getting " << ids[i] << "..failed" << endl;
    }
  }

  //REMOVING DATA FROM HASH TABLE ONE BY ONE USING TEST DATA IDS & PRINT HASH TABLE
  cout << "\n\n deleting nodes from hashtable" << endl;
   for (int i= 0 ; i < testdatasize; i++){
    if (h1.removeEntry(ids[i])) {
      cout << "removing " << ids[i] << "..success" << endl;
    }
    else {
      cout << "removing " << ids[i] << "..failed" << endl;
    }
  }
  cout << endl;
  h1.printTable();
  cout << "count: " << h1.getCount() << endl;


  //ADDING TEST DATA TO HASH TABLE 2 TIMES & PRINT HASH TABLE
  cout << "\n\n adding nodes to hashtable 2 times" << endl;
  for (int j = 0; j < 2; j++){
    for (int i= 0 ; i < testdatasize; i++){
      if(h1.insertEntry(ids[i],&strs[i])){
        cout << "adding " << ids[i] << " : " << strs[i] << "..success" << endl;
      }
      else {
        cout << "adding " << ids[i] << " : " << strs[i] << "..failed" << endl;
      }
    }
  }
  cout << endl;
  h1.printTable();
  cout << "count: " << h1.getCount() << endl;

  //REMOVING DATA FROM HASH TABLE ONE BY ONE USING TEST DATA IDS 2 TIMES & PRINT HASH TABLE
    cout << "\n\n deleting nodes from hashtable 2 times" << endl;
  for (int j = 0; j < 2; j++){
    for (int i= 0 ; i < testdatasize; i++){
      if (h1.removeEntry(ids[i])) {
        cout << "removing " << ids[i] << "..success" << endl;
      }
      else {
        cout << "removing " << ids[i] << "..failed" << endl;
      }
    }
  }
  cout << endl;
  h1.printTable();
  cout << "count: " << h1.getCount() << endl;

  
  //GETTING DATA FROM EMPTY HASH TABLE USING TEST DATA IDS
  cout << "\n\n getting data from an empty hash table" << endl;
  
  for (int i=0 ; i < testdatasize; i++){
    string data= h1.getData(ids[i]);
    if (data != ""){
       cout << "getting " << ids[i] << " data: " << data << "..success" << endl;
    }
    else{
      cout << "getting " << ids[i] << "..failed" << endl;
    }
  }
  //CREATING NEW TEST DATA AND ADDING BOTH TEST DATA TO THE SAME LIST & PRINT
  cout << " \n\n generating new test data set" << endl;
  const int testdatasize2 = BASE + (rand() % OFFSET + 1);
  int ids2[testdatasize2];
  string strs2[testdatasize2];

  char buffer2[BUFFERSIZE];
  for (int i = 0; i < testdatasize2; i++) {
    ids2[i] = rand() % MAXID + 1;
    for (int j = 0; j < BUFFERSIZE - 1; j++) {
      buffer2[j] = 'a' + i;
    }
    buffer2[BUFFERSIZE - 1] = '\0';
    strs2[i] = buffer2;
  }
  ids2[testdatasize2 - 2] = ids2[testdatasize2 - 3];
  strs2[testdatasize2 - 2] = "known duplicate";
  ids2[testdatasize2 - 1] = -1;
  strs2[testdatasize2 - 1] = "known bad";

  /*
   * Show test data
   */
  cout << " Showing Test Data (" << testdatasize2 << " entries)..." << endl;
  for (int i = 0; i < testdatasize2; i++) {
    cout << ids2[i] << " : " << strs2[i] << endl;
  }
  cout << endl;

  //FILLING UP THE HASH TABLE WITH NEW DATA SET & PRINT IT
    cout << "\n\n adding new data set to hashtable" << endl;
  for (int i= 0 ; i < testdatasize2; i++){
      if(h1.insertEntry(ids2[i],&strs2[i])){
      cout << "adding " << ids2[i] << " : " << strs2[i] << "..success" << endl;
      }
      else {
        cout << "adding " << ids2[i] << " : " << strs2[i] << "..failed" << endl;
      }
    }
  cout << endl;
  h1.printTable();
  cout << "count: " << h1.getCount() << endl;
  
  //FILLING UP THE HASH TABLE WITH OLD DATA SET & PRINT IT
    cout << "\n\n adding old data set to hashtable" << endl;
  for (int i= 0 ; i < testdatasize; i++){
      if(h1.insertEntry(ids[i],&strs[i])){
      cout << "adding " << ids[i] << " : " << strs[i] << "..success" << endl;
      }
      else {
        cout << "adding " << ids[i] << " : " << strs[i] << "..failed" << endl;
      }
    }
  cout << endl;
  h1.printTable();
  cout << "count: " << h1.getCount() << endl;
  
  //REMOVING HALF OF EACH DATA SET FROM THE HASH TABLE
    cout << "\n\n removing half of data set #1" << endl;
  
    for (int i= 0 ; i < testdatasize/2; i++){
      if (h1.removeEntry(ids[i])) {
        cout << "removing " << ids[i] << "..success" << endl;
      }
      else {
        cout << "removing " << ids[i] << "..failed" << endl;
      }
    }
    cout << "\n\n removing half of data set #2" << endl;
    for (int i= 0 ; i < testdatasize2/2; i++){
      if (h1.removeEntry(ids2[i])) {
        cout << "removing " << ids2[i] << "..success" << endl;
      }
      else {
        cout << "removing " << ids2[i] << "..failed" << endl;
      }
    }

  cout << endl;
  h1.printTable();
  cout << "count: " << h1.getCount() << endl;

  //TESTING DATA RETRIEVAL OF ALL TEST DATA IDS GENERATED 

  cout << "\n\n getting all data from hash table using all testdata IDs" << endl;
  
  cout << "\n testdata #1" << endl;
  for (int i=0 ; i < testdatasize; i++){
    string data= h1.getData(ids[i]);
    if (data != ""){
       cout << "getting " << ids[i] << " data: " << data << "..success" << endl;
    }
    else{
      cout << "getting " << ids[i] << "..failed" << endl;
    }
  }
  cout << "\n testdata #2" << endl;
  for (int i=0 ; i < testdatasize2; i++){
    string data= h1.getData(ids2[i]);
    if (data != ""){
       cout << "getting " << ids2[i] << " data: " << data << "..success" << endl;
    }
    else{
      cout << "getting " << ids2[i] << "..failed" << endl;
    }
  }
  cout << endl;
   h1.printTable();
  cout << "count: " << h1.getCount() << endl;

  //CLEARING HASH TABLE 
  cout << "\n\n removing all of data set #1" << endl;
  
    for (int i= 0 ; i < testdatasize; i++){
      if (h1.removeEntry(ids[i])) {
        cout << "removing " << ids[i] << "..success" << endl;
      }
      else {
        cout << "removing " << ids[i] << "..failed" << endl;
      }
    }
    cout << "\n\n removing all of data set #2" << endl;
    for (int i= 0 ; i < testdatasize2; i++){
      if (h1.removeEntry(ids2[i])) {
        cout << "removing " << ids2[i] << "..success" << endl;
      }
      else {
        cout << "removing " << ids2[i] << "..failed" << endl;
      }
    }
    cout << endl;
   h1.printTable();
  cout << "count: " << h1.getCount() << endl;

  //TESTING DATA RETRIEVAL OF ALL TEST DATA IDS GENERATED 
  cout << "\n\n getting all data from hash table using all testdata IDs" << endl;
  
  cout << "\n testdata #1" << endl;
  for (int i=0 ; i < testdatasize; i++){
    string data= h1.getData(ids[i]);
    if (data != ""){
       cout << "getting " << ids[i] << " data: " << data << "..success" << endl;
    }
    else{
      cout << "getting " << ids[i] << "..failed" << endl;
    }
  }
  cout << "\n testdata #2" << endl;
  for (int i=0 ; i < testdatasize2; i++){
    string data= h1.getData(ids2[i]);
    if (data != ""){
       cout << "getting " << ids2[i] << " data: " << data << "..success" << endl;
    }
    else{
      cout << "getting " << ids2[i] << "..failed" << endl;
    }
  }
  cout << endl;
   h1.printTable();
  cout << "count: " << h1.getCount() << endl;

  //RANDOMLY ADDING, GETTING, REMOVING DATA FROM HASH TABLE
    cout << endl;
    cout << "testing random operations using a switch statement"<< endl;
    int rand_idx = 0;
    int choice = rand() % 6 + 1;
    string data = "";
    while (h1.getCount() < BASE) {
      switch (choice) {
      case 1:
        // insertEntry()
        rand_idx = rand() % testdatasize + 0;
        if(h1.insertEntry(ids[rand_idx],&strs[rand_idx])){
        cout << "adding " << ids[rand_idx] << " : " << strs[rand_idx] << "..success" << endl;
        }
        else {
          cout << "adding " << ids[rand_idx] << " : " << strs[rand_idx] << "..failed" << endl;
        }
         
        break;
      case 2:
         // insertEntry()
        rand_idx = rand() % testdatasize2 + 0;
        if(h1.insertEntry(ids2[rand_idx],&strs2[rand_idx])){
        cout << "adding " << ids2[rand_idx] << " : " << strs2[rand_idx] << "..success" << endl;
        }
        else {
          cout << "adding " << ids2[rand_idx] << " : " << strs2[rand_idx] << "..failed" << endl;
        }
          
        break;
      case 3:
        // removeEntry()
          rand_idx = rand() % testdatasize + 0;
          if (h1.removeEntry(ids[rand_idx])) {
            cout << "removing " << ids[rand_idx] << "..success" << endl;
          }
          else {
            cout << "removing " << ids[rand_idx] << "..failed" << endl;
          }
          
        break;
      case 4:
        // removeEntry()
        
          rand_idx = rand() % testdatasize2 + 0;
          if (h1.removeEntry(ids2[rand_idx])) {
            cout << "removing " << ids2[rand_idx] << "..success" << endl;
          }
          else {
            cout << "removing " << ids2[rand_idx] << "..failed" << endl;
          }
        
         
        break;
      case 5:
        // getData()
          rand_idx = rand() % testdatasize + 0;
          data = h1.getData(ids[rand_idx]);
          if (data != ""){
            cout << "getting " << ids[rand_idx] << " data: " << data << "..success" << endl;
          }
          else{
            cout << "getting " << ids[rand_idx] << "..failed" << endl;
          }
        
         
        break;
      case 6:
       // getData() 
          rand_idx = rand() % testdatasize2 + 0;
          data= h1.getData(ids[rand_idx]);
          if (data != ""){
            cout << "getting " << ids2[rand_idx] << " data: " << data << "..success" << endl;
          }
          else{
            cout << "getting " << ids2[rand_idx] << "..failed" << endl;
          }
        
          
        break;
      }
      choice = rand() % 6 + 1;
    }
      cout << endl;
      h1.printTable();
      cout << "count: " << h1.getCount() << endl;

      //CLEARING HASH TABLE 
      cout << "\n\n removing all of data set #1 & #2" << endl;
      
        for (int i= 0 ; i < testdatasize; i++){
          h1.removeEntry(ids[i]);
        }
        for (int i= 0 ; i < testdatasize2; i++){
          h1.removeEntry(ids2[i]);
        }
        cout << endl;
      h1.printTable();
      cout << "count: " << h1.getCount() << endl;











  // cout << "adding node" << endl;
  // h1.hashtable[0].addNode(22,&str);
  // cout << "filling hashtable with testdata" << endl;
  // for (int i = 0 ; i < testdatasize; i++){
  //   h1.insertEntry(ids[i],&strs[i]);
  // }
  // h1.printTable();
  


  // show it is empty by calling getCount and printTable

  // try and put ALL the test data into the table and show what happens

  // continue using and testing your table, add and remove data,
  // do whatever it takes to full test your object and prove it
  // is robust and can handle all use cases.
  ////////////////////////////////////////////////////
  ////////////////////////////////////////////////////
  

  return 0;
}
