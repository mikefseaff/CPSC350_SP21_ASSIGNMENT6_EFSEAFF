#ifndef BST_H
#define BST_H
#include "Student.h"
#include "Faculty.h"
//class file for BST nodes that hold an object of any type (data)

template<class T> 
class TreeNode{

    public:
        //default constructor
        TreeNode();
        //overloaded constructor
        TreeNode(T tempPerson);
        //destructor
        ~TreeNode();
        //data object for what ever the bst nodes need to hold
        T data;
        //pointer to left node child
        TreeNode<T> *left;
        //pointer to right node child
        TreeNode<T> *right;

};

//default constructor
template<class T>
TreeNode<T>::TreeNode(){
    left = NULL;
    right = NULL;
}

//overloaded constructor
template<class T>
TreeNode<T>::TreeNode(T tempPerson){
    left = NULL;
    right = NULL;
    data = tempPerson;
}
//destructor
template<class T>
TreeNode<T>::~TreeNode(){
    left = NULL;
    right = NULL;
}

//template class for the BST that holds nodes of a specific type

template<class T>
class BST{
    public:
        //default constructor
        BST();
        //destructor
        ~BST();

        //inserts a node into the bst
        void insert(T value);
        //returns true if the node passed in exists in the tree
        bool contains(T value);
        //deletes a node given its data
        bool deleteNode(T k);
        //returns true if the bst is empty
        bool isEmpty();
        //finds the node given the ID for a student or faculty member
        TreeNode<T>* findNode(int ID);

        T getMin();//go left 
        T getMax();//go right

        //trees root node public because it needed to be accessable by other classes for simplicity
        TreeNode<T> *root;
       
        //gets a nodes successor if deleted
        TreeNode<T>* getSuccessor(TreeNode<T> *d); //simplifies deleteNode a bit
        //prints nodes addresses
        void recPrint(TreeNode<T> *node);
        //recursivly deletes all the nodes in the bst
        void recursiveNodeDeletion(TreeNode<T> *node);
        //prints the data of the nodes for file writing
        string recursiveDataPrint(TreeNode<T> *node);
        //prints the data of all the nodes to the console
        string recursiveDataPrintConsole(TreeNode<T> *node);
        //returns the data of all students in a specific major
        string findAllOfMajor(string Major,TreeNode<T> *node);
        //returns all students or faculty that have the same name
        string findAllOfSameName(string Name, TreeNode<T> *node);
        //earses the strings textFileData and TreeNodesData
        void wipeTreeNodesData();

    private:
        //string to be printing to file for saving
        string textFileData;
        //string to be printed to console
        string TreeNodesData;
};

 
template<class T>
BST<T>::BST(){
    root = NULL; //empty tree

}
template<class T>
BST<T>::~BST(){
    recursiveNodeDeletion(root);
    
}

template<class T>
void BST<T>::recPrint(TreeNode<T> *node){
    if(node == NULL){
        return;
    }

    recPrint(node->left);
    cout << node->data << endl;
    recPrint(node->right);
}

template<class T>
bool BST<T>::isEmpty(){
    if (root == NULL){
        return true;
    }
    else{
        return false;
    }
}

template<class T>
T BST<T>::getMin(){
    TreeNode<T> *current = root;

    if(root == NULL){
        return T();
    }

    while(current->left != NULL){
        current = current->left;
    }

    return current->data;
}
template<class T>
T BST<T>::getMax(){
    TreeNode<T> *current = root;

    if(root == NULL){
        return T();
    }

    while(current->right != NULL){
        current = current->right;
    }
    return current->data;
}


template<class T>
void BST<T>::insert(T value)
{
    TreeNode<T> *node = new TreeNode<T>(value);

    if(root == NULL){
        //empty tree
        root = node;
        
    }
    else{
        //its not an empty tree
        TreeNode<T> *current = root;
        TreeNode<T> *parent = NULL;


        while(true){
            parent = current;
            if (value < current->data){
                current = current->left;

                if(current == NULL){
                    //insertion point
                    parent->left = node;
                    break;
                }
            }
            else{
                //go right
                current = current->right;
                if(current == NULL){
                    parent->right = node;
                    break;
                }
            }
        }

    }
    
}
template<class T>
bool BST<T>::contains(T value){
    if(root == NULL){
        return false;
    }
    else{
        //not empty
        TreeNode<T> *current = root;

        while(current->data != value){
            if(value < current->data){
                current = current->left;
            }
            else{
                current = current->right;
            }
            if(current == NULL){
                return false;
            }
        }
        return true;
    }
}

template<class T>
TreeNode<T>* BST<T>::findNode(int ID){
    if(root == NULL){
        return root;
    }
    else{
        //not empty
        TreeNode<T> *current = root;

        while(current->data.getID() != ID){
            if(ID < current->data.getID()){
                current = current->left;
            }
            else{
                current = current->right;
            }
            if(current == NULL){
                return current;
            }
        }
        return current;
    }
}

template<class T>
bool BST<T>::deleteNode(T k){
    if(isEmpty()){ //or root == NULL
        return false;
    }

    TreeNode<T> *parent = NULL;
    TreeNode<T> *current = root;
    bool isLeftNode = true;

    while(current->data != k){
        parent = current;

        if(k < current->data){
            isLeftNode = true;
            current = current->left;
        }
        else{
            isLeftNode = false;
            current = current->right;
        }

        if(current == NULL){
            
            return false;
        }
    }
    //now we found node now we delete it

    //case: node to delete does not have children, leaf node
    if(current->left == NULL && current->right == NULL){
        if(current == root){
            root = NULL;
        }
        else if (isLeftNode){
            parent->left = NULL;
        }
        else{
            parent->right = NULL;
        }
    }

    //case node to be deleted has one child
    else if (current->right == NULL){
        //dooes not have a right child must have left
        if(current == root){
            root = current->left;
        }
        else if(isLeftNode){
            parent->left = current->left;
        }
        else{
            //node to be deleted is a right child
            parent->right = current->left;
        }
    }

    else if (current->left == NULL){
        //dooes not have a left child must have right
        if(current == root){
            root = current->right;
        }
        else if(isLeftNode){
            parent->left = current->right;
        }
        else{
            //node to be deleted is a right child
            parent->right = current->right;
        }
    }

    else{
        //node has two children, at this point we being to cry.
        //we have to find the successor


        TreeNode<T> *successor = getSuccessor(current);//current is the node to be deleted

        if(current == root){
            root = successor;
        }
        else if (isLeftNode){
            parent->left = successor;
        }
        else{
            parent->right = successor;
        }

        successor->left = current->left;

    }
    //delete (garbage collect) in this function or something special in the destructor?
    delete current;
    return true;
}
template<class T>
TreeNode<T>* BST<T>::getSuccessor(TreeNode<T> *d){
    //successor parent
    TreeNode<T> *sp = d;
    TreeNode<T> *successor = d;
    TreeNode<T> *current = d->right;

    while(current != NULL){
        sp = successor;
        successor = current;
        current = current->left;
    }

    if(successor != d->right){
        sp->left = successor->right;
        successor->right = d->right;
    }
    return successor;
}
template<class T>
void BST<T>::recursiveNodeDeletion(TreeNode<T> *node){
    if(node != NULL){
        recursiveNodeDeletion(node->left);
        recursiveNodeDeletion(node->right);
        
        delete node;
    }
}

template<class T>
string BST<T>::recursiveDataPrint(TreeNode<T> *node){
    if(node != NULL){
        textFileData += node->data.printData();
        recursiveDataPrint(node->left);
        recursiveDataPrint(node->right);
        
    }
    return textFileData;
}

template<class T>
string BST<T>::recursiveDataPrintConsole(TreeNode<T> *node){
    if(node != NULL){
        
        
        recursiveDataPrintConsole(node->left);
        recursiveDataPrintConsole(node->right);
        TreeNodesData += node->data.printDataConsole();
        
    }
    return TreeNodesData;
}
template<class T>
string BST<T>::findAllOfMajor(string Major, TreeNode<T> *node){
    if(node != NULL){
        if(node->data.getMajor() == Major){
            TreeNodesData += node->data.printDataConsole();
        }
        findAllOfMajor(Major, node->left);
        findAllOfMajor(Major, node->right);
        
    }
    return TreeNodesData;
}

template<class T>
string BST<T>::findAllOfSameName(string Name, TreeNode<T> *node){
    if(node != NULL){
        if(node->data.getName() == Name){
            TreeNodesData += node->data.printDataConsole();
        }
        findAllOfSameName(Name, node->left);
        findAllOfSameName(Name, node->right);
        
    }
    return TreeNodesData;
}

template<class T>
void BST<T>::wipeTreeNodesData(){
    TreeNodesData = "";
}
#endif