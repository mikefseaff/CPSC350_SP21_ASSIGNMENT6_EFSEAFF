#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include <iostream>
using namespace std;
//template class for the nodes of the linked list
template<class T>
class Node{
    public:
        //default constructor
        Node();
        //overloaded constructor
        Node(T d);
        //destructor
        ~Node();
        //pointer to the next node in the linked list
        Node<T> *next;
        //pointer to prevous node in the linked list
        Node<T> *prev;
        //data stored in node
        T data;
};

//default constructor
template<class T>
Node<T>::Node(){

}

//overloaded constructor
template<class T>
Node<T>::Node(T d){
    data = d;
    next = NULL; //nullptr or 0
    prev = NULL;
}

//destructor
template<class T>
Node<T>::~Node(){
    next = NULL;
    prev = NULL;
}

//template class for the linked list
template<class T>
class LinkedList{
    public:
    //default constructor
        LinkedList();
        //destructor
        ~LinkedList();
        //inserts a node to the front of the list 
        void insertFront(T data);
        //inserts a node to the back of the list
        void insertBack(T data);
        //remoces the front node
        T removeFront();
        //removes the back node
        T removeBack();
        //finds the node with a specific data value
        T find(T value);
        //removes a node with specific data in it
        T remove(T key);
        //checks if linked list is empty
        bool isEmpty();
        //returns the size of the list
        size_t getSize();
        //prints the linked list for debugging
        void printList(bool printLink);
        //returns the front of the linked list
        T getFront();
    private:
        //pointer to the front node of the list
        Node<T> *front;
        //pointer to the back node of the list
        Node<T> *back;
        //size of the list
        size_t listsize;
};


//default constructor
template<class T>
LinkedList<T>::LinkedList(){
    listsize = 0;
    front = NULL;
    back = NULL;
}
//destructor
template<class T>
LinkedList<T>::~LinkedList(){
    //lets build some character
    //what do we do here?
    //loop with deletes?
    while(front != NULL){
        removeFront();
    }
    
}
 //inserts a node to the front of the list 
template<class T>
void LinkedList<T>::insertFront(T data){
    Node<T> *node = new Node<T>(data);

    if(listsize == 0){
        //list is empty
        back = node;
    }
    else{
        //not empty
        front->prev = node;
        node->next = front;
    }
    front = node;
    listsize++;
}
//inserts a node to the back of the list
template<class T>
void LinkedList<T>::insertBack(T data){
    Node<T> *node = new Node<T>(data);
    if(listsize == 0){
        //list is empty
        front = node;
    }
    else{
        //not empty
        back->next = node;
        node->prev = back;
    }
    back = node;
    listsize++;
}
//remoces the front node
template<class T>
T LinkedList<T>::removeFront(){
     Node<T> *tp = front;

     //check if empty

     //check if listsize = 1
     if (front->next == NULL){
         back = NULL;
     }
     else {
         //listsize >1
         front->next->prev = NULL;
     }
     front = front->next;
     tp->next = NULL;
     T temp = tp->data;
     listsize--;
     delete tp;
     return temp;
 }
//finds the node with a specific data value
template<class T>
T LinkedList<T>::removeBack(){
    Node<T> *tp = back;

     //check if empty

     //check if listsize = 1
     if (back->prev == NULL){
         front = NULL;
     }
     else {
         back->prev->next = NULL;
     }
     back = back->prev;
     tp->prev = NULL;
     T temp = tp->data;
     listsize--;
     delete tp;
     return temp;

}
//finds the node with a specific data value
template<class T>
T LinkedList<T>::find(T value){
    int idx = -1;
    Node<T> *current = front;
    while (current != NULL){
        ++idx;
        if (current->data == value){
            break;
        }
        else{
            current = current->next;
        }
    }
    if(current == NULL){
        //did not find value doesnt exsist 
        idx = -1;
    }
    return idx;

}
 //removes a node with specific data in it
template<class T>
T LinkedList<T>::remove(T key){
    //we could leverage find 

    Node<T> *current = front;

    while(current->data != key){
        current = current->next;

        if(current == NULL){
            return 0;
        }
    }

    //found it, now proceed to remove
    if(current == front){
        front = current->next;
        front->prev = NULL;
    }
    else if (current == back){
        back = current->prev;
        back->next = NULL;
    }
    else{
        //list node is somewhere in the middle 
        current->prev->next = current->next;
        current->next->prev = current->prev;
        
    }
    current->next = NULL;
    current->prev = NULL;
    T temp = current->data;
    listsize--;
    delete current;
    return temp;

}
//prints the linked list for debugging
template<class T>
void LinkedList<T>::printList(bool printLink)
{
    Node<T> *curr = front;
    while(curr != 0){
       if(curr == front){
         cout << "{FRONT}: ";
       }
       else if(curr == back){
         cout << "{REAR}: ";
       }
       if(printLink)
        cout << "[ PREV: "<< curr->prev << " || " << curr->data << " || NEXT: "<< curr->next << " ] ";
      else
        cout << "[ " << curr->data << " ] ";

       curr = curr->next;
       if(curr != 0){
         cout << " ==> ";
       }
    }
    cout << endl;
}
//returns the front of the linked list
template<class T>
T LinkedList<T>::getFront(){
    return front->data;
}
 //returns the size of the list
template<class T>
size_t LinkedList<T>::getSize(){
    return listsize;
}
#endif

