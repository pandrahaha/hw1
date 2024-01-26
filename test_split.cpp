/*
CSCI 104: Homework 1 Problem 1

Use this file to test your split.cpp file.

Create linked lists and split them with your split() function.

You can compile this file like this:
g++ split.cpp test_split.cpp -o test_split
*/

#include "split.h"
#include <iostream>
using namespace std;
int main() // int main (int argc, char* argv[])
{
  int A [10] = {1,2,3,4,5,6,7,8,9,10};
  Node* nArray [10];
  Node* temp = nullptr, *in = nullptr, *evens = nullptr, *odds = nullptr;
  
  //just making a bunch of unconnected nodes
  for (int i = 0; i < 10; i++){
    temp = new Node(A[i],nullptr);
    nArray[i] = temp;
  }
 
  //now to link the nodes, leave last node unlinked, it should be nullptr for its next
  for(int i = 0; i < 9; i++){
    if(i == 0) {
      //this is the first node, need to make in point to it
      nArray[0]->next = nArray[1];
      in = nArray[0];
    }
    else { //connect the nodes
      
        nArray[i]->next = nArray[i+1];
    }
    
  }

  //PRINTING OUT "IN"
    cout << "Printing IN ARRAY " << endl;
    int cntr = 1;
    Node* curr = in;
    while (curr != nullptr){
      cout << "node " << cntr << " value = " << curr->value << endl;
      cntr ++;
      curr = curr->next;
    }

  //CALLING split
  cout <<"calling split" << endl;
  split(in, odds, evens);
  cout << "finished split :) " << endl;
  //PRINTING OUT "IN"
    cout << "Printing IN ARRAY post split " << endl;
     cntr = 1;
    curr = in;
    while (curr != nullptr){
      cout << "node " << cntr << " value = " << curr->value << endl;
      cntr ++;
      curr = curr->next;
    }

    //PRINTING OUT "evens"
    cout << "Printing evens ARRAY post split " << endl;
     cntr = 1;
     curr = evens;
     cout << "evens is pointing to: " << evens->value << endl;
    while (curr != nullptr){
      cout << "node " << cntr << " value = " << curr->value << endl;
      cntr ++;
      curr = curr->next;
    }
    //PRINTING OUT "odds"
    cout << "Printing odds ARRAY post split " << endl;
     cntr = 1;
     curr = odds;
    while (curr != nullptr){
      cout << "node " << cntr << " value = " << curr->value << endl;
      cntr ++;
      curr = curr->next;
    }

  return 0;
}
