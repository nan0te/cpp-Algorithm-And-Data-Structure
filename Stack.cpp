#ifndef STACK_CPP
#define STACK_CPP
#include <iostream>
#include <stdlib.h>
#include "IStack.h"

template <class Type>
class Stack : public IStack<Type> {

    struct Node {
        Type item;
        int next;
    };

    public:
    Stack(void) ; 
    virtual ~Stack (void) {}
    virtual bool isEmpty(void) ;
    virtual bool isFull(void) ;
    virtual void push_back(const Type& item);
    virtual void pop(void) ;
    virtual Type& peek(void) ;
    virtual int size(void) ;
    private:
        enum { MAX_ITEMS = 512, null = -1 } ;
        int last, count, Free, newFree, first ;
        struct Node rep[MAX_ITEMS] ;
       // Stack(const Stack&);
        // Stack<Type>& operator= (const Stack<Type>&);
        };

template <class Type>
Stack<Type>::Stack(void) {

    

    for ( int i = 0 ; i < MAX_ITEMS ; i++ ) {
            rep[i].item = 0;
            rep[i].next = i + 1;
    }
            rep[MAX_ITEMS-1].next = null;

    first = null; Free = 0 ; last = null ; newFree = 0; count = 0 ;        
}

template <class Type>
bool Stack<Type>::isEmpty(){
    return  count == 0 ;
}


template <class Type>
bool Stack<Type>::isFull(){
    return count == MAX_ITEMS ;

}

template <class Type>
int Stack<Type>::size(){
    return count ;
}

template <class Type>
void Stack<Type>::push_back( const Type& item ) {

    if( !isFull() ) {
        newFree = rep[Free].next ;
        rep[Free].item = item ;

    }
     if(!isEmpty()) {
         first = Free ; last = Free ;
         rep[last].next = null ;
     }
     else {
            last = Free ;
            rep[last].next = null;
     }
     Free = newFree;
     count++;
}

template <class Type>
 void Stack<Type>::pop(void){    
    //rep[last].item = 0 ;
    
    //  std::cout << "pop:" << *item << std::endl;
       last--;  count--;
     // return *item;
}

template <class Type>
Type& Stack<Type>::peek(void)
{
    Type *item = &rep[last].item;
    return *item;
}

#endif