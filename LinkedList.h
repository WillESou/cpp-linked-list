/*
Name: William Sou
Description: Templated Linked List

*/


#include <stdlib.h>
#include <iostream>


//Node class declared

template <typename T>

class Node {

 private:

  T data;

  Node<T> *nextNode;
  Node<T>  *previousNode;

 public:

  Node(T newData);
  T getData();
  Node<T>* getNext();
  Node<T>* getPrevious();
  void setNext(Node<T> *nextNode);
  void setPrevious(Node<T> *previousNode);
};


//LinkedList class declared

template<typename T>

class LinkedList
{
  
 private:
  
  Node<T> *firstNode, *lastNode;
  
 public:

  LinkedList();
  void print();
  void addToEnd(T data);
  void addToFront(T data);
  bool addAtIndex(T data, int index);
  T removeFromFront();
  T removeFromEnd();
  bool removeTheFirst(T data);
  void removeAllOf(T data);
  void removeAtIndex(int index);
  bool elementExists(T data);
  int indexOf(T data);
  Node<T>* find(int index);
  T retrieveFront();
  T retrieveEnd();
  T retrieve(int Index);
  int length();
  void empty();
};



//LinkedList constructor defined
template<typename T>
LinkedList<T>::LinkedList(){

  this->firstNode = NULL;
  this->lastNode = NULL;

  

}

//LinkedList print method
template<typename T>
void LinkedList<T>::print(){

  Node<T>* pointer = this->firstNode;

  if(pointer == NULL){
    std::cout << "LIST IS EMPTY!" << std::endl;
  }else{
    
    std::cout << "[";
    int counter = 0;

    std::cout<< *pointer->getData();
    pointer = pointer->getNext();
    while(pointer != NULL){
      
      
      
      std::cout<< "," << *pointer->getData();
      pointer = pointer->getNext();

      counter++;
      
    }
    
    std::cout << "]" << std::endl;
  }
}


//LinkedList addToEnd method

template <typename T>
void LinkedList<T>::addToEnd(T data){


  Node<T>*  newNode = new Node<T>(data);
  
  if(this->lastNode == NULL)
    {
      if(this->firstNode == NULL)
	{
	  firstNode = newNode;
	  lastNode = newNode;
	}else if(this->firstNode->getNext() == NULL)
	{

	  this->firstNode->setNext(newNode);
	  newNode->setPrevious(firstNode);
	}

    }else{
    
    this->lastNode->setNext(newNode);
    newNode->setPrevious(lastNode);
    this->lastNode = newNode;
  }
  
}

//LinkedList addToFront method

template <typename T>
void LinkedList<T>::addToFront(T data){
  
  Node<T>* newNode = new Node<T>(data);
  
  if(this->firstNode == NULL){
    this->firstNode = newNode;
    this->lastNode = newNode;
  }else{
    newNode->setNext(this->firstNode);
    this->firstNode->setPrevious(newNode);
    firstNode = newNode;
    
    
  }
}

//LinkedList addAtIndex method

template <typename T>
bool LinkedList<T>::addAtIndex(T data, int index){

  if(index == 0){
    addToFront(data);
    return true;
  }else{
    
    Node<T>* pointer = this->firstNode;
    Node<T>* newNode = new Node<T>(data);



    for(int i = 0;i < index;i++){

      if(pointer->getNext() == NULL){
	return false;
      }else{
	pointer = pointer->getNext();
      }
      
    }
    
    newNode->setNext(pointer);
    newNode->setPrevious(pointer->getPrevious());
    pointer->getPrevious()->setNext(newNode);
    pointer->setPrevious(newNode);    
    return true;
  }

}


//LinkedList removeFromFront method

template <typename T>
T LinkedList<T>::removeFromFront(){
  
  Node<T>* pointer = this->firstNode;
  T data;
  if(pointer->getNext() != NULL){
    firstNode = pointer->getNext();
    pointer->getNext()->setPrevious(NULL);
    
  }else{
    firstNode = NULL;
    lastNode = NULL;
  }
  data = pointer->getData();
  delete pointer;
  return data;
}

//LinkedList removeFromEnd method

template <class T>
T LinkedList<T>::removeFromEnd(){

  Node<T>* pointer = this->lastNode;
  T data;

  if(pointer->getPrevious() != NULL){
    lastNode = pointer->getPrevious();
    pointer->getPrevious()->setNext(NULL);
  }else{
    lastNode = NULL;
    firstNode = NULL;
  }
  
  data = pointer->getData();
  delete pointer;
  return data;

}

//LinkedList removeTheFirst method

template <typename T>
bool LinkedList<T>::removeTheFirst(T data){
  
  Node<T>* pointer = this->firstNode;
  bool found = true;
  int index = 0;
  
  while(found){
    
    if(pointer == NULL){
      found = false;
      break;
    }else if(pointer->getData() == data){
      removeAtIndex(index);
      break;
    }
    index++;
    pointer = pointer->getNext();

  }
  return found;
}

//LinkedList removeAllOf
template <typename T>
void LinkedList<T>::removeAllOf(T data){

  bool dataDeleted = true;

  while(dataDeleted){
    dataDeleted = removeTheFirst(data);
  }


}



//LinkedList removeAtIndex method
template <typename T>
void LinkedList<T>::removeAtIndex(int index){

  Node<T>* deletedNode;

  deletedNode = this->firstNode;

  if(index == 0){
    removeFromFront();
  }else{


    for(int i = 0;i < index;i++)
      {
	if(deletedNode->getNext() == NULL)
	  {
	    std::cout << "SPECIFIED INDEX IS OUT OF RANGE!" << std::endl;
	    return;
	  }
	std::cout << "Moving to index " << i << std::endl;
	deletedNode = deletedNode->getNext();
      }
  
 

    if(deletedNode->getNext() == NULL)
      {
	deletedNode->getPrevious()->setNext(NULL);
      }else{
      
      deletedNode->getPrevious()->setNext(deletedNode->getNext());
      deletedNode->getNext()->setPrevious(deletedNode->getPrevious());
      delete deletedNode;
    }
  
  }

}


//LinkedList elementExists method

template <typename T>
bool LinkedList<T>::elementExists(T data){

  Node<T>* pointer = this->firstNode;
  bool found = true;
  int index = 0;

  while(found){

    if(pointer == NULL){
      found = false;
      break;
    }else if(pointer->getData() == data){
      return true;
      break;
    }
    index++;
    pointer = pointer->getNext();

  }
  return false;

}


//LinkedList find method
template <typename T>
Node<T>* LinkedList<T>::find(int index){
 
  Node<T>* currentNode;
  
  currentNode = this->firstNode;


  if(index == 0){
    return currentNode;
  }else{
    for(int i = 0;i < index;i++)
      {
	currentNode = currentNode->getNext();
      }
    return currentNode;
  }

}

//LinkedList IndexOf method

template <typename T>
int LinkedList<T>::indexOf(T data){
 
  Node<T>* pointer = this->firstNode;
  bool found = true;
  int index = 0;

  while(found){

    if(pointer == NULL){
      break;
    }else if(pointer->getData() == data){
      return index;
      break;
    }
    index++;
    pointer = pointer->getNext();

  }
  return index;


}

//LinkedList retrieveFront method

template <typename T>
T LinkedList<T>::retrieveFront(){

  return this->firstNode->getData();

}

//LinkedList retrieveEnd method

template <typename T>
T LinkedList<T>::retrieveEnd(){

  return this->lastNode->getData();
}

//LinkedList retrieve method

template <typename T>
T LinkedList<T>::retrieve(int index){

  return find(index)->getData();

}

//LinkedList length method
template <typename T>
int LinkedList<T>::length(){
  
  int length = 0;
  Node<T>* pointer = firstNode;
  bool listNotEnd = true;

  while(listNotEnd){
    
    if(pointer->getNext() == NULL){
      listNotEnd = false;
    }
    length++;
    pointer = pointer->getNext();

  }
  
  return length;
  

}

//LinkedList empty method

template <typename T>
void LinkedList<T>::empty(){



  Node<T>* pointer = lastNode;
  Node<T>* next = nullptr;

  while(pointer){
    
    next = pointer->getPrevious();
    delete pointer;
    pointer = next;

  }

  this->firstNode = NULL;
  this->lastNode = NULL;

}



// Node constructor

template <typename T>
Node<T>::Node(T newData){
  
  this->data = newData;
  this->nextNode = NULL;
  this->previousNode = NULL;

}

// Node getData method

template <typename T>
T Node<T>::getData(){

  return this->data;

}


//Node getNext method

template <typename T> 
Node<T>* Node<T>::getNext(){

  return this->nextNode;

}

//Node getPrevious method

template <typename T> 
Node<T>* Node<T>::getPrevious(){

  return this->previousNode;

}

//Node setNext method

template <typename T> 
void Node<T>::setNext(Node* newNode){
  
  this->nextNode = newNode;

}

//Node setPrevious method

template <typename T>
void Node<T>::setPrevious(Node* newNode){

  this->previousNode = newNode;

}
