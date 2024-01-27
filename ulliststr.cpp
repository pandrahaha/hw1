#include <cstddef>
#include <stdexcept>
#include "ulliststr.h"

ULListStr::ULListStr()
{
  head_ = NULL;
  tail_ = NULL;
  size_ = 0;
}

ULListStr::~ULListStr()
{
  clear();
}

bool ULListStr::empty() const
{
  return size_ == 0;
}

size_t ULListStr::size() const
{
  return size_;
}

// WRITE YOUR CODE HERE

void ULListStr:: push_back(const std::string& val)
{
  if(head_== nullptr){ //Completely empty, no head or tail either
  //make a head
  
  head_ = new Item();
  tail_ = head_;
  head_->first = 9;
  head_->last = 10;
  size_ = 1;
  head_->val[9] = val;

  }
  else if (head_ == tail_ ) { //only one node
    //find the last val, if full, make a new node and that val will be first
    if(head_->last == 10){
      tail_ = new Item();
      tail_->prev = head_;
      head_->next = tail_;
      size_ += 1;
      tail_->val[0] = val;
      tail_->first = 0;
      tail_->last = 1;
    }
    else {
      //not full, just push back like normal
      head_->val[head_->last - 1] = val;
      head_->last++;
      size_+=1;

    }
    
  }
  else { //go to tail and check if you can add
  if(tail_->last == 10){
    //make new node
      tail_ = new Item();
      tail_->prev = head_;
      head_->next = tail_;
      size_ += 1;
      tail_->val[0] = val;
      tail_->first = 0;
      tail_->last = 1;
  }
  else {
    
    tail_->val[tail_->last - 1] = val;
    tail_->last++;
    size_+=1;
  }

  }
}


void ULListStr:: push_front(const std::string& val)
{
  if(head_ == nullptr){ //Completely empty, no head or tail either
  //make a head
  //putting it at the back for consistency
  head_ = new Item();
  tail_ = head_;
  head_->first = 9;
  head_->last = 10;
  head_->prev = nullptr;
  head_->next = nullptr;
  size_ = 1;
  head_->val[9] = val;

  }
  else if (head_ == tail_ ) { //only one node
    //find the first val, if full, make a new node and that val will be first
    if(head_->first == 0){
      head_ = new Item();
      tail_->prev = head_;
      head_->next = tail_;
      head_->prev = nullptr;
      size_ += 1;
      head_->val[9] = val;
      head_->first = 9;
      head_->last = 10;
    }
    else {
      //not full, just push front like normal
      head_->val[head_->first - 1] = val;
      head_->first --;
      size_+=1;

    }
    
  }
  else { //go to head_ and check if you can add
  if(head_->first == 0){ //head_ is full
    //make new node
       Item* tempHead = new Item();
      size_ += 1;
      tempHead->val[9] = val;
      tempHead->first = 9;
      tempHead->last = 10;
      tempHead->next = head_;
      tempHead->prev = nullptr;
      head_->prev = tempHead;
      head_ = tempHead;
      
  }
  else { //push front like normal
    
    head_->val[head_->first - 1] = val;
    head_->first--;
    size_+=1;
  }

  }
}

void ULListStr:: pop_back()
{
  if(empty()){
    //do nothing
  }
  else {
    //go to tail and remove last element; deallocate if empty
    
    tail_->val[tail_->last - 1] = ""; //just to remove the string?
    tail_->last --; //make sure to update the last idx so it isnt stuck on the old val if not properly deleted. 
    size_ --; 
    if((tail_->last) - (tail_->first )== 0){
      //empty, deallocate
      Item* tempTail = tail_->prev;
      delete tail_;
      tail_ = tempTail;

    }
}
}

void ULListStr:: pop_front()
{
  if(empty()){
    //do nothing
  }
  else {
    //go to head and remove first element; deallocate if empty
    
    head_->val[head_->first] = ""; //just to remove the string?
    head_->first += 1; //make sure to update the last idx so it isnt stuck on the old val if not properly deleted. 
    size_ --; 
    if((head_->last) - (head_->first) == 0){
      //empty, deallocate
      Item* tempHead = head_->next;
      delete head_;
      head_ = tempHead;

    }
  }
}

std::string const &  ULListStr:: back() const
{
  std:: string* backString = &(tail_->val[(tail_->last) -1]);
  return *backString; 
}

std::string const &  ULListStr:: front() const
{
  std:: string* frontString = &(head_->val[head_->first]);
  return *frontString; 
}


std::string* ULListStr:: getValAtLoc(size_t loc) const
{
  std:: string* ans = nullptr;
  size_t cntr = 0;
  if(loc > (size_ - 1)){
    return NULL; //out of bounds / non existent
  }
  else {
    //check if its in the head_
    // see how many items are in head
    size_t numInHead = head_->last - head_->first;
    if (numInHead < loc){ // it is in the head
      size_t index = head_->first + loc - 1;
       ans = &(head_->val[index]);
      return ans;
      
    }
    else {
      //not in head, need to start looping, we can skip head
      size_t numInHead = head_->last - head_->first;
      cntr += numInHead;
      Item* curr = head_->next;
      while (cntr < loc){
        //step 1: check if it is in this current items
        size_t numInCurr = (curr->last) - (curr->first);
        if ((numInCurr + cntr)  > loc) { // it is in curr
          size_t index = curr->first + (loc - cntr);
          ans = &(curr->val[index]);
          //final while loop, make cntr higher than loc
          cntr += 2 * loc;    
        }   
        else {
          //its not in curr, update curr;
          curr = curr->next;
        }
      }
      return ans;  
    }
  }
}

void ULListStr::set(size_t loc, const std::string& val)
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  *ptr = val;
}

std::string& ULListStr::get(size_t loc)
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  return *ptr;
}

std::string const & ULListStr::get(size_t loc) const
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  return *ptr;
}

void ULListStr::clear()
{
  while(head_ != NULL){
    Item *temp = head_->next;
    delete head_;
    head_ = temp;
  }
  tail_ = NULL;
  size_ = 0;
}
