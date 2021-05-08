#ifndef GENSTACK_H
#define GENSTACK_H

#include <iostream>
using namespace std;
#include "LinkedList.h"
//template class for a stack of a doubly linked list
template <class T>
class GenStack{
    public:
        GenStack(); //default constructor
        ~GenStack(); //destructor

        //functions
        void push(T data);
        T pop();

        //helper functions
        T peek(); //aka top()
        bool isEmpty();
        size_t getSize();
        void printStack();
        bool isFull();

    private:
       LinkedList<T> *myList = new LinkedList<T>;
       int size = 5;
};

//default constructor
template <class T>
GenStack<T>::GenStack(){
    
}
//destructor
template <class T>
GenStack<T>::~GenStack(){
    delete myList;
}
//pushes what ever data to the stack
template <class T>
void GenStack<T>::push(T data){

    if(isFull()){
        myList->removeBack();
    }
    myList->insertFront(data);
    

}

//pops/removes the node from the stack
template <class T>
T GenStack<T>::pop(){
    //check if empty before proceeding
    if(!isEmpty()){
        return myList->removeFront();
    }
    else {
        
        return T();
    }
    
}

template <class T>
bool GenStack<T>::isFull(){
    if(getSize() == size){
        return true;
    }
    else{
        return false;
    }
}

//returns the data that is at the top of the stack
template <class T>
T GenStack<T>::peek(){
    //check if empty 
    if(!isEmpty()){
        return myList->getFront();
    }
    else {
        
        return T();
    }
    
}


//checks if the stack is empty
template <class T>
bool GenStack<T>::isEmpty(){
    return (myList->getSize() == 0);
}

//returns the size of the stack
template <class T>
size_t GenStack<T>::getSize(){
    return (myList->getSize());
}
//prints the contents of the stack for debugging
template <class T>
void GenStack<T>::printStack(){
    myList->printList(true);
}
#endif