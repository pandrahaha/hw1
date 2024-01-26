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
//passing in, odds, and evens. In is by the most recent node after subsequent passes since we arent returning anything
void split(Node*& in, Node*& odds, Node*& evens)
{
  /* Add code here */
// WRITE YOUR CODE HERE


  // BASE CASE when at last node, then its empty
  cout << "currently on node val " << in->value << " and theyre pointing to " << in->next << endl;
  Node currNode = *in;
  bool last = false;
  if(currNode.next == nullptr){
    //last node,
    cout << "done?" << endl;
    bool last = true;
    in = nullptr;
  }
  else {
    
    in = in->next;
    currNode.next = nullptr;
  //else  check if even or odd then link it
  //update in, recursively call again
    
    Node holder (0,nullptr); //dummy var just to make a node
    Node* tempPointer = nullptr;
    if (currNode.value % 2 == 0){
    //CASE 1: EVEN
      cout << "checking if even" << endl;
    //check if evens is empty
      if(evens == nullptr){
        cout << "first even node" << endl;
        evens = &currNode;
      }
      else {
        cout << "evens first node is " << evens->value << " and points to node " << evens->next << endl;
        
        //do while loop to get to the last node
        cout << "before the while loop" << endl;
        holder = *evens; 
        tempPointer = evens;    
        //if at last node, call skip to calling recursive call
        if(tempPointer->next != nullptr) {
          cout << "entered if" << endl;
          while(tempPointer->next != nullptr){
            cout << "tempPointer value " << tempPointer-> value << endl;
            tempPointer = tempPointer->next;
          }
          tempPointer->next = &currNode;     
        }
        else if (tempPointer->next == nullptr) {
          tempPointer->next = &currNode;
        }
        else if (last == true) {
          holder.next = &currNode; 
          cout<< "last bool" << endl;
          
        }
      }
      
      cout << "currently in is pointing to " << in->value << endl;
      split(in, odds, evens);
      
  }
  else {
      //CASE 2 ODD
      cout << "checking if odd" << endl;
      if(odds == nullptr){
        cout << "first odd node" << endl;
        //Node* oHead = &currNode;
        odds = &currNode;      
      }
      else {
        //do while loop to get to the last node
        holder = *odds;
        cout << "before the while loop" << endl;
        if(holder.next != nullptr) {
        while(holder.next != nullptr){
          holder = *(holder.next);
        }
        holder.next = &currNode;  
        }
        else if (last == true) {
          holder.next = &currNode; 
          cout<< "last bool" << endl;
        }
      }
      
      cout << "currently in is pointing to " << in->value << endl;
      split(in, odds, evens);
    }
  }  
}


/* If you needed a helper function, write it here */
