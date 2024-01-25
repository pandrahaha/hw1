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
//passing in, odds, and evens by the most recent node after subsequent passes since we arent returning anything
void split(Node*& in, Node*& odds, Node*& evens)
{
  /* Add code here */
// WRITE YOUR CODE HERE
  //pseudo code 
  // BASE CASE when in's val is null, then its empty

  cout << "currently on node val" << in->value << endl;
  if(in == nullptr){
    //done dont do anything
    cout << "done!" << endl;
  }
  else {
    //else  check if even or odd then link it
  //update in
  //recursively call again
  int temp = in->value;
  Node* holder = nullptr;
  if (temp % 2 == 0){
    //CASE 1: EVEN
    cout << "checking if even" << endl;
    //check if evens is empty
    if(evens == nullptr){
      evens = in;
      in = in->next;
      
    }
    else {
      //do while loop to get to the last node
      holder = evens;     
      while(holder->next != nullptr){
        cout << "holder value " << holder->value << endl;
        holder = holder->next;
        
      }
      holder->next = in;
      in = in->next;
    }
    in = in->next;
    split(in, odds, evens);
  }
  else {
      //CASE 2 ODD
      cout << "checking if odd" << endl;
      if(odds == nullptr){
        odds = in;
        in = in->next;
        cout << "60" << endl;
        
      }
      else {
        //do while loop to get to the last node
        holder = odds;
        cout << "66" << endl;
        while(holder->next!= nullptr){
          holder = holder->next;
        }
        holder->next = in;
        in = in->next;
      }
      cout << "fin odd, now calling recursion" << endl;
      split(in, odds, evens);
    }
    
  }
  
  }

  



/* If you needed a helper function, write it here */
