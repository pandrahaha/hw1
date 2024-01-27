/*
CSCI 104: Homework 1 Problem 1

Write a recursive function to split a sorted singly-linked
list into two sorted linked lists, where one has the even 
numbers and the other contains the odd numbers. Students 
will receive no credit for non-recursive solutions. 
To test your program write a separate .cpp file and #include
split.h.  **Do NOT add main() to this file**.  When you submit
the function below should be the only one in this file.
*/

#include "split.h"
#include <iostream>
using namespace std;
/* Add a prototype for a helper function here if you need */

//gets to last node recursively
Node* getLastNode(Node*& list)
{
  //base case, last node has no next
  Node* tempList = list;
  Node* lastNodePtr = list;
  if(tempList->next != nullptr){
    tempList = tempList->next;
    getLastNode(tempList);
  }
  else {
    return list;
  }
}


//passing in, odds, and evens. In is by the most recent node after subsequent passes since we arent returning anything
void split(Node*& in, Node*& odds, Node*& evens)
{
  /* Add code here */
// WRITE YOUR CODE HERE
  Node* curr = nullptr;
  int cntr;
  // BASE CASE when at last node, sort then its empty
  cout << " entered recursion, currently on node val " << in->value << " and theyre pointing to " << in->next << endl;
  Node currNode = *in;
  
  if(currNode.next == nullptr){
    //last node
    Node* temp = nullptr;
    if(currNode.value % 2 == 0){
      temp = evens;
      temp->next = &currNode;
    //   cout << "---Printing evens ARRAY final split " << endl;
    //  cntr = 1;
    //  curr = evens;
    //  cout << "evens is pointing to: " << evens->value << endl;
    }
    else {
      temp = odds;
      temp->next = &currNode;
    //   cout << "---Printing odds ARRAY final split " << endl;
    //  cntr = 1;
    //  curr = odds;
    //  cout << "odds is pointing to: " << evens->value << endl;
    
    }
    //cout << "DONE" << endl;
  in = nullptr;
  }
  else {
    
    currNode.next = nullptr;
    in = in->next;
  //else  check if even or odd then link it
  //update in, recursively call again
    
    //Node holder (0,nullptr); //dummy var just to make a node
    Node* tempPointer = nullptr;
    if (currNode.value % 2 == 0){
    //CASE 1: EVEN
      cout << "checking if even" << endl;
    //check if evens is empty
      if(evens == nullptr){
        cout << "first even node" << endl;
        evens = &currNode;
        cout << "evens is now pointing to " << evens->value << endl;
      }
      else {
        cout << "evens first node is " << evens->value << " and points to node " << evens->next << endl;
        
        
        tempPointer = evens;    
        //if at last node, call skip to calling recursive call
        if(tempPointer->next != nullptr) {
          cout << "entered if" << endl;


          // while(tempPointer->next != nullptr){
          //   cout << "tempPointer value " << tempPointer-> value << endl;
          //   tempPointer = tempPointer->next;
          // }

          
          
          tempPointer->next = getLastNode(evens);     
        }
        else if (tempPointer->next == nullptr) {
          tempPointer->next = &currNode;
          cout << "evens second node is " << tempPointer->next->value << endl;
        }
        
      }
      
      cout << "(BEFORE RECURSIVE CALL): currently in is pointing to " << in->value << endl;

       cout << "---Printing evens ARRAY during split " << endl;
     cntr = 1;
     curr = evens;
     cout << "evens is pointing to: " << evens->value << endl;
    // while (curr != nullptr){
    //   cout << "node " << cntr << " value = " << curr->value << endl;
    //   cntr ++;
    //   curr = curr->next;
    // }
      split(in, odds, evens);
      
  }
  else {
      //CASE 2 ODD
      cout << "checking if odd" << endl;
      if(odds == nullptr){
        cout << "first odd node" << endl;
        odds = &currNode;      
        cout << "odds is now pointing to " << odds->value << endl;
      }
      else {
       
        tempPointer = odds;    
        //if at last node, call skip to calling recursive call
        if(tempPointer->next != nullptr) {
          cout << "entered if" << endl;
          // while(tempPointer->next != nullptr){
          //   cout << "tempPointer value " << tempPointer-> value << endl;
          //   tempPointer = tempPointer->next;
          // }
          
          tempPointer->next = getLastNode(odds);     
        }
        else if (tempPointer->next == nullptr) {
          tempPointer->next = &currNode;
          cout << "odds second node is " << tempPointer->next->value << endl;
        }
        
        
      }
      
    //   cout << "(BEFORE RECURSIVE CALL):currently in is pointing to " << in->value << endl;
    //    cout << "---Printing odds ARRAY during split " << endl;
    //  cntr = 1;
    //  curr = odds;
    //  cout << "odds is pointing to: " << odds->value << endl;
    // while (curr != nullptr){
    //   cout << "node " << cntr << " value = " << curr->value << endl;
    //   cntr ++;
    //   curr = curr->next;
    // }
      split(in, odds, evens);
    }
  }  
}


/* If you needed a helper function, write it here */
