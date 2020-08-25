#ifndef BSTREE_CPP
#define BSTREE_CPP

#include <iostream>
#include <stdlib.h>
#define nullptr NULL


template <class Type>
class BSTree {
    
    struct Node {
        Type data;
        Node* left;
        Node* right;
    };

    Node* root;
    int size;
    Node* makeEmpty(Node* current) {
        if(current == NULL)
            return NULL;
        {
            makeEmpty(current->left);
            makeEmpty(current->right);
            delete current;
        }
        return NULL;
    }

    Node* insert(Type item, Node* current)
    {
        if(current == NULL)
        {
            current = new Node;
            current->data = item;
            current->left = current->right = NULL;
            
        }
        else if(item < current->data) current->left = insert(item, current->left);
        else if(item > current->data) current->right = insert(item, current->right);
        
        size++;
       
       return current;
    }

    Node* findMin(Node* current)
    {
        if(current == NULL)             return NULL;
        else if(current->left == NULL)  return current;
        else                            return findMin(current->left);
    }

    Node* findMax(Node* current) {
        if(current == NULL)             return NULL;
        else if(current->right == NULL) return current;
        else                            return findMax(current->right);
    }

    Node* remove(Type item, Node* current) {
        Node* aux;
        if(current == NULL)              return NULL;
        else if(item < current->data)    current->left = remove(item, current->left);
        else if(item > current->data)    current->right = remove(item, current->right);
        else if(current->left && current->right)
        {
            aux = findMin(current->right);
            current->data = aux->data;
            current->right = remove(current->data, current->right);
        }
        else
        {
            aux = current;
            if(current->left == NULL)         current = current->right;
            else if(current->right == NULL)   current = current->left;
            delete aux;
        }
        size--;

        return current;
    }

    void inorder(Node* current) {  // preorden raiz, izq, derecha . 
        if(current == NULL) return;
        inorder(current->left);
        std::cout << current->data << " ";
        inorder(current->right);
    }
    void postorder ( Node* curren ){
        if(curren == NULL) return;
        postorder(curren->left);
        postorder(current->right);
        std::cout << curren->data << " ";
    }

    void preorder( Node* current ) {
        if(curren == NULL) return;
        std::cout << curren->data << " ";
        postorder(curren->left);
        postorder(current->right);
        
    }

    Node* find(Node* current, Type item) {
        if(current == NULL) return NULL;
        else if(item < current->data)    return find(current->left, item);
        else if(item > current->data)    return find(current->right, item);
        else                             return current;
    } 

public:
    BSTree(void) ;
    ~BSTree(void) ;
    void Insert(const int& item) ;
    void Remove(const int& item) ;
    void Display() ;
    void search(const int& item) ;
};

 

template <class Type>
BSTree<Type>::BSTree() {
    
    this->root = NULL;
    this->size=0;
}

template <class Type>
BSTree<Type>::~BSTree() {
        
     this->root = makeEmpty(this->root);
}

template <class Type>
void BSTree<Type>::Insert(const int& item) {
       
    this->root = insert(item, this->root);
}

template <class Type>
void BSTree<Type>::Remove(const int& item) {
        
    this->root = remove(item, this->root);
}

template <class Type>
 void BSTree<Type>::Display() {

    inorder(root);
    printf("\n");
    
}

template <class Type>
void BSTree<Type>::search(const int& item) {
    
    root = find(root, item);
    
 }


#endif










                                                                                // if token == '(' arbol.insertleft('') ; pilaPadre.push(arbol) ; arbol = arbol.getLeft ;
                                                                                // else if token != +-*/ - arbol.root (int(token)) - root = pilapadre.pop() - arbol = root;
                                                                                // else if token == +*+/ - arbol.root ( token ) - arbol.insertright ('') - pilapadre.push(arbol) - arbol =  arbol->right
                                                                                // else if token == ')' - arbol = pilapadres.pop()
                                                                                //else return
                                                                                // return arbol