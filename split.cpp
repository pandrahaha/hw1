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
// #include <iostream>
// using namespace std;
/* Add a prototype for a helper function here if you need */

//gets to last node recursively
Node* getLastNode(Node*& list)
{
  //base case, last node has no next
  Node* tempList = list;
  if(tempList->next != nullptr){
    tempList = tempList->next;
    getLastNode(tempList);
  }
  else {
    return list;
  }
  return list;
}


//passing in, odds, and evens. In is by the most recent node after subsequent passes since we arent returning anything
void split(Node*& in, Node*& odds, Node*& evens)
{
  /* Add code here */
// WRITE YOUR CODE HERE
  
  // BASE CASE when at last node, sort then its empty
  
  Node currNode = *in;
  
  if(currNode.next == nullptr){
    //last node
    Node* temp = nullptr;
    if(currNode.value % 2 == 0){
      temp = evens;
      temp->next = &currNode;
    }
    else {
      temp = odds;
      temp->next = &currNode;
    
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
    //check if evens is empty
      if(evens == nullptr){
        evens = &currNode;
        
      }
      else {
       
        tempPointer = evens;    
        //if at last node, call skip to calling recursive call
        if(tempPointer->next != nullptr) {
            
          tempPointer->next = getLastNode(evens);     
        }
        else if (tempPointer->next == nullptr) {
          tempPointer->next = &currNode;
          
        }
        
      }
   
      split(in, odds, evens);
      
  }
  else {
      //CASE 2 ODD
      
      if(odds == nullptr){
        odds = &currNode;      
      }
      else {
       
        tempPointer = odds;    
        //if at last node, call skip to calling recursive call
        if(tempPointer->next != nullptr) {
          
          
          tempPointer->next = getLastNode(odds);     
        }
        else if (tempPointer->next == nullptr) {
          tempPointer->next = &currNode;
        }
        
        
      }
      
   
      split(in, odds, evens);
    }
  }  
}


/* If you needed a helper function, write it here */
