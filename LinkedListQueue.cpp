//LinkedListQueue.cpp
#ifndef _LINKEDLISTQUEUE_CPP
#define _LINKEDLISTQUEUE_CPP

#include "LinkedListQueue.hpp"
#include <cstdlib> //for NULL
#include <cassert>
#include <iostream>
LinkedListQueue::LinkedListQueue()
{
  // TODO:  Initialize any member variables as needed in the constructor.
   head=NULL;
   tail=NULL;
size=0;
}

void LinkedListQueue::add(MazeState *elem)
{
  // TODO:  Implement this.

  node *temp=new node;
  temp->data=elem;
   if(head==NULL){
   head=temp;
   tail=temp;
   }else{
 
  tail->next=temp;
  tail=temp;
}

  

size++;

  return;
}

MazeState *LinkedListQueue::remove()
{
  // TODO:  Implement this.
  assert(head != NULL||size==0);
  node *temp=new node;
  MazeState *ret=head->data;
  
   if(size==1){
   tail=NULL;
   delete head;
   head=NULL;
   }else{
  temp=head->next;
   delete head;
   head=temp;}
 
 
 

   size--;
   return ret;
   
}

bool LinkedListQueue::is_empty()
{
  // TODO:  Implement this.
   return tail==NULL||head==NULL||size==0; ;
}

LinkedListQueue::~LinkedListQueue()
{
  // TODO:  Implement the destructor.  Be sure to delete everything.
           while(tail!=NULL||size!=0){
             remove();
}


}

#endif
